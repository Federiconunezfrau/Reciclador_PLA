/* En este archivo se describen las funciones asociadas al control del driver
 * puente h. Por ejemplo, funciones de hacer girar el motor, de decirle que se
 * detenga y de configurar el puente h. Estas funciones son invocadas por el
 * statechart.
 */

#include "puente_h_operations.h"







extern void prefixIface_opStart_puente_h(const Prefix* handle)
{
	/* Esta función se encarga de hacer girar el motor del extrusor */

	gpioWrite(PIN_PUENTE_1, TRUE);
	gpioWrite(PIN_PUENTE_2, FALSE);

}

extern void prefixIface_opRetract_puente_h(const Prefix* handle)
{
	/* Esta función se encarga de hacer girar el motor del extrusor */

	gpioWrite(PIN_PUENTE_1, FALSE);
	gpioWrite(PIN_PUENTE_2, TRUE);

}

extern void prefixIface_opStop_puente_h(const Prefix* handle)
{
	/* Esta función se encarga de detener el motor del extrusor */

	gpioWrite(PIN_PUENTE_1,FALSE);
	gpioWrite(PIN_PUENTE_2,FALSE);
}

extern void prefixIface_opConfig_puente_h(const Prefix* handle)
{
	//Se configuran todos los pines como salidas
	gpioConfig(PIN_PUENTE_1, GPIO_OUTPUT);
	gpioConfig(PIN_PUENTE_2, GPIO_OUTPUT);
	gpioConfig(PIN_PUENTE_VELOCIDAD, GPIO_OUTPUT);

	//TODO:Se inicializa el PWM utilizado por el driver para controlar la velocidad

	//Le indica al puente H que apague el motor para que este no gire
	gpioWrite(PIN_PUENTE_1, FALSE);
	gpioWrite(PIN_PUENTE_2, FALSE);
}


