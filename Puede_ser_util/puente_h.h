/* Implementación de un puente H con el driver l298n para controlar motores DC
 */

#ifndef _PUENTE_H_INCLUDED_
#define _PUENTE_H_INCLUDED_


#include "sapi.h"

typedef enum {HORARIO,ANTIHORARIO} sentido_t;

typedef struct
{
	uint32_t pin_velocidad;		//Pin por el que se controla la velocidad
	uint32_t pin_1;				//Pin para controlar el sentido de rotación del motor
	uint32_t pin_2;				//Pin para controlar el sentido de rotación del motor

	sentido_t sentido_rotacion;	//TRUE = HORARIO, FALSE = ANTIHORARIO
	uint8_t velocidad;			//Valor de 0 a 255 que indica la velocidad de giro

}puenteh_t;

void puente_h_conf(puenteh_t*, uint32_t, uint32_t, uint32_t);
void puente_h_rotar(puenteh_t*, sentido_t);
void puente_h_alto(puenteh_t*);





#endif
