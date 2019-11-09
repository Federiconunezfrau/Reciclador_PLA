/*Implementación de un rotary encoder. Extraído de la página:
 * http://www.buxtronix.net/2011/10/rotary-encoders-done-properly.html
 *
 * Allí se encuentra descripto el algoritmo de funcionamiento.
 */


#include "rotary_encoder_state.h"


#define R_START 0x0

#ifdef HALF_STEP
// Use the half-step state table (emits a code at 00 and 11)
#define R_CCW_BEGIN 0x1
#define R_CW_BEGIN 0x2
#define R_START_M 0x3
#define R_CW_BEGIN_M 0x4
#define R_CCW_BEGIN_M 0x5
const unsigned char ttable[6][4] = {
  // R_START (00)
  {R_START_M,            R_CW_BEGIN,     R_CCW_BEGIN,  R_START},
  // R_CCW_BEGIN
  {R_START_M | DIR_CCW, R_START,        R_CCW_BEGIN,  R_START},
  // R_CW_BEGIN
  {R_START_M | DIR_CW,  R_CW_BEGIN,     R_START,      R_START},
  // R_START_M (11)
  {R_START_M,            R_CCW_BEGIN_M,  R_CW_BEGIN_M, R_START},
  // R_CW_BEGIN_M
  {R_START_M,            R_START_M,      R_CW_BEGIN_M, R_START | DIR_CW},
  // R_CCW_BEGIN_M
  {R_START_M,            R_CCW_BEGIN_M,  R_START_M,    R_START | DIR_CCW},
};

#else

// Use the full-step state table (emits a code at 00 only)
#define R_CW_FINAL 0x1
#define R_CW_BEGIN 0x2
#define R_CW_NEXT 0x3
#define R_CCW_BEGIN 0x4
#define R_CCW_FINAL 0x5
#define R_CCW_NEXT 0x6

const unsigned char ttable[7][4] = {
  // R_START
  {R_START,    R_CW_BEGIN,  R_CCW_BEGIN, R_START},
  // R_CW_FINAL
  {R_CW_NEXT,  R_START,     R_CW_FINAL,  R_START | DIR_CW},
  // R_CW_BEGIN
  {R_CW_NEXT,  R_CW_BEGIN,  R_START,     R_START},
  // R_CW_NEXT
  {R_CW_NEXT,  R_CW_BEGIN,  R_CW_FINAL,  R_START},
  // R_CCW_BEGIN
  {R_CCW_NEXT, R_START,     R_CCW_BEGIN, R_START},
  // R_CCW_FINAL
  {R_CCW_NEXT, R_CCW_FINAL, R_START,     R_START | DIR_CCW},
  // R_CCW_NEXT
  {R_CCW_NEXT, R_CCW_FINAL, R_CCW_BEGIN, R_START},
};
#endif

//Inicialización del encoder

void rotary_encoder_conf(rotary_encoder_t *r,uint32_t pin1, uint32_t pin2, uint32_t pin_pulsador)
{
	r->pin1 = pin1;
	r->pin2 = pin2;
	r->pin_pulsador = pin_pulsador;

	#ifdef ENABLE_PULLUPS
	gpioWrite(pin1, HIGH);
	gpioWrite(pin2, HIGH);
	#endif
  // Initialise state.
  r->state = R_START;
  gpioConfig(pin1,GPIO_INPUT);	//Configuro ambos pines del encoder como entradas
  gpioConfig(pin2,GPIO_INPUT);
  gpioConfig(pin_pulsador, GPIO_INPUT_PULLUP);

  r->boton_presionado = FALSE;
}

//Procesamiento de la rotación del encoder

unsigned char rotary_encoder_process(rotary_encoder_t *r)
{
	// Grab state of input pins.
	unsigned char pinstate = ((!gpioRead(r->pin2)) << 1) | (!gpioRead(r->pin1));
	// Determine new state from the pins and state table.
	r->state = ttable[(r->state) & 0xf][pinstate];
	// Return emit bits, ie the generated event.
	return (r->state) & 0x30;
}

//Procesamiento del pulsador del encoder

void rotary_encoder_button(rotary_encoder_t *r)
{
	if( (!gpioRead(r->pin_pulsador)) == TRUE )
	{
		r->boton_presionado = TRUE;
	}
	else
	{
		r->boton_presionado = FALSE;
	}
}
