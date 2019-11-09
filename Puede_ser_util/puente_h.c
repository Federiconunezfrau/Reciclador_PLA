#include "../../Reciclador_PLA/Puede_ser_util/puente_h.h"



//Configuración del puente h para usarlo con el motor DC
void puente_h_conf(puenteh_t * p, uint32_t pin_1, uint32_t pin_2, uint32_t pin_velocidad)
{
	//Se configuran los pines del driver

	p-> pin_1 = pin_1;
	p-> pin_2 = pin_2;
	p-> pin_velocidad = pin_velocidad;

	//Se configuran todos los pines como salidas
	gpioConfig(pin_1, GPIO_OUTPUT);
	gpioConfig(pin_2, GPIO_OUTPUT);
	gpioConfig(pin_velocidad, GPIO_OUTPUT);

	//TODO:Se inicializa el PWM utilizado por el driver para controlar la velocidad

	gpioWrite(pin_1, FALSE);
	p->velocidad = 0;

}

//Iniciar rotacion del motor
void puente_h_rotar(puenteh_t *p, sentido_t sentido)
{
	if(sentido == HORARIO)	//Sentido Horario
	{
		gpioWrite(p->pin_1, TRUE);
		gpioWrite(p->pin_2, FALSE);
	}
	else if(sentido == ANTIHORARIO)	//Sentido Antihorario
	{
		gpioWrite(p->pin_1, FALSE);
		gpioWrite(p->pin_2,TRUE);
	}
}

//Funcion para detener el motor
void puente_h_alto(puenteh_t *p)
{
	gpioWrite(p->pin_1,FALSE);
	gpioWrite(p->pin_2,FALSE);
}








