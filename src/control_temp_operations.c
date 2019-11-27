/* En este archivo se describen las funciones asociadas al control de temperaturas.
 * Por ejemplo, funciones de hacer control del actuador, y de lectura de temperatura.
 * Estas funciones son invocadas por el statechart.
 */

#include "control_temp_operations.h"


extern void prefixIface_opConfig_control_temp(const Prefix* handle)
{
	/* En esta función se configura el PWM para su uso durante el control
	 * de la temperatura.
	 */


	//Inicio la config del acutador (PWM)
	pwmConfig( 0, PWM_ENABLE );
	pwmConfig(PIN_PWM_ACTUADOR, PWM_ENABLE_OUTPUT);		//Asociación del PWM con el control de temp

	pwmWrite(PIN_PWM_ACTUADOR, 0);						//Setea duty en 0, para iniciar apagado

	adcConfig( ADC_ENABLE );	//Enciendo el ADC

	uartConfig( UART_USB, 115200 );	//Configuro la UART para enviar los datos
}


extern void prefixIface_opApagar_control_temp(const Prefix* handle)
{
	/* Esta función se encarga de apagar el sistema de control de temperaturas.
	 * Lo deja en libertad para que naturalmente se enfríe y vuelva a
	 * temperatura ambiente.
	 */

	pwmWrite(PIN_PWM_ACTUADOR, 0);	//Se apaga seteando el duty cycle en 0
}


extern sc_integer prefixIface_opControlar_temp(const Prefix* handle, const sc_integer ref)
{
	/* Esta función es la encargada de ejecutar el control de temperatura. Recibe la variable
	 * "ref" que indica el setpoint al que se quiere llegar. Devuelve la temperatura actual medida.
	 * Realiza un PID. En cada invocación de la función se realiza la corrección del sistema de
	 * control.
	 */

	//Primera prueba donde solo leo la temperatura y la envío por UART

	uint16_t read;						//Lectura directa del ADC
	uint16_t temp;						//Conversion a temperatura
	uint16_t voltage_adc;				//Conversion a tension
	int16_t error_actual;				//Error en cada pasada

	/*float read;
	float temp;
	float voltage_adc;
	float error_actual;*/

	static int16_t duty;					//Duty aplicado a la planta

	static int16_t duty_pre_windup;		//Duty calculado por el contrlador

	static int16_t error_acumulado;		//Error acumulado en todas las pasadas
	//static float error_acumulado;
	//static int16_t error_windup_actual;
	//static float error_windup_actual;
	//static int16_t error_windup_acumulado;
	//static float error_windup_acumulado;
	read = adcRead( CH1 );				//Leo la temperatura del sensor en una variable de 16 bits

	voltage_adc = TENSION_ADC(read);	//Paso a tension
	temp = TEMP_ADC(voltage_adc);		//Paso a temperatura

	//Si estoy debajo de la temperatura mínima:
	if(temp < TEMP_MIN_PERMITIDA)
	{
		duty = 255;
	}
	else	//Aplico el control
	{
		error_actual = ref - temp;
		error_acumulado += error_actual;
		duty_pre_windup = KP * error_actual + KI * PERIODO * error_acumulado;

		//Anti wind-up

		if(duty_pre_windup < 2)
		{
			duty = 0;
		}
		else if(duty_pre_windup > 254)
		{
			duty = 255;
		}
		else
		{
			duty = duty_pre_windup;
		}
		//error_windup_actual = duty - duty_pre_windup;
		//error_windup_acumulado += error_windup_actual;
		//duty = duty + KT * PERIODO * error_windup_acumulado;
		duty = duty + KI * KT * PERIODO * (duty - duty_pre_windup);
	}
	pwmWrite(PIN_PWM_ACTUADOR, duty);	//50% duty cycle

	//if(temp==ref)
	//{
	//	error_acumulado = 0;
	//}



	return temp;
}

extern void prefixIface_opEnviar_UART(const Prefix* handle, const sc_integer num)
{
	char number[10];			//Variable donde se guarda el dato convertido a string

	if(num>TEMP_MIN_PERMITIDA)
	{
		itoa(num, number,10);		//Convierto a una string

	    uartWriteString( UART_USB, number );
	    uartWriteString( UART_USB, "\r\n" );
	}


}


