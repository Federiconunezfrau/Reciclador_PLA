#ifndef _BOARD_CONNECTIONS_H_
#define _BOARD_CONNECTIONS_H

#include "sapi.h"

//Se incluyen las definiciones de los pines de la EDU-CIAA y sus conexiones con los periféricos

//No se incluyen los del LCD porque las funciones del LCD asumen los pines llamados
//LCD_EN, LCD_RS, LCD_1, LCD_2, LCD_3, LCD_4 automáticamente.

//=================================================================
//Rotary Encoder

#define PIN_CANAL_1 (GPIO0)
#define PIN_CANAL_2 (GPIO1)
#define PIN_PULSADOR (GPIO2)

//=================================================================
//Puente H l298n

#define PIN_PUENTE_1 (GPIO3)
#define PIN_PUENTE_2 (GPIO4)
#define PIN_PUENTE_VELOCIDAD (T_FIL1)	//<-- Salida PWM




#endif
