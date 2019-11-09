/* En este archivo se declaran las funciones asociadas al encoder. Cuando se
 * rota el encoder o se presiona el botón, estas funciones le dicen al statechart que
 * sucedió determinado evento. Luego este sabe qué debe hacer. Por ejemplo cambiar
 * lo que tiene que mostrar en la pantalla o acceder a tal menú.
 */

#include "encoder_events.h"

void identificar_rotacion_encoder(unsigned char r, Prefix *statechart)
{
	/*Identifica el evento que se le debe indicar al statechart
	 *que ocurrió, para que este sepa qué hacer en función de
	 *lo ocurrido con el encoder*/

	if(r == DIR_CW)
	{
		prefixIface_raise_evEnc_rot_derecha(statechart);
	}
	else if(r == DIR_CCW)
	{
		prefixIface_raise_evEnc_rot_izquierda(statechart);

	}
}

void identificar_eventos_encoder(Prefix *statechart, rotary_encoder_t *r)
{
	unsigned char encoder_result;

	rotary_encoder_button(r);

	if(r->boton_presionado == TRUE)
	{
		prefixIface_raise_evTECXOprimido(statechart);
	}
	else
	{
		prefixIface_raise_evTECXNoOprimido(statechart);
	}

	encoder_result = rotary_encoder_process(r);

	identificar_rotacion_encoder(encoder_result,statechart);



}


