/*Implementación de un rotary encoder. Extraído de la página:
 * http://www.buxtronix.net/2011/10/rotary-encoders-done-properly.html
 *
 * Allí se encuentra descripto el algoritmo de funcionamiento.
 */

#ifndef _ROTARY_ENCODER_STATE_H_
#define _ROTARY_ENCODER_STATE_H_

#include "sapi.h"


// Enable this to emit codes twice per step.
//#define HALF_STEP

// Enable weak pullups
//#define ENABLE_PULLUPS

// Values returned by 'process'
// No complete step yet.
#define DIR_NONE 0x0
// Clockwise step.
#define DIR_CW 0x10
// Anti-clockwise step.
#define DIR_CCW 0x20

typedef struct
{
	unsigned char state;
	uint32_t pin1;
	uint32_t pin2;
	uint32_t pin_pulsador;

	bool_t boton_presionado;

}rotary_encoder_t;

void rotary_encoder_conf(rotary_encoder_t *,uint32_t, uint32_t,uint32_t);
unsigned char rotary_encoder_process(rotary_encoder_t *);
void rotary_encoder_button(rotary_encoder_t *);




#endif
