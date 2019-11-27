#ifndef _CONTROL_TEMP_OPERATIONS_H_
#define _CONTROL_TEMP_OPERATIONS_H_

#include "PrefixRequired.h"

#include "board_connections.h"

#include "utils.h"


//Relacion de tension y valores del adc en milivolts. Por ejemplo para n = 1024,
//1024 * 3.22 = 3300 mV = 3.3 V
#define TENSION_ADC(n) (n * 3.22)

//Relacion de temperatura en miles de grados y tensión del adc en milivots. Por ejemplo para
//v = 3300 mV = 3.3 V, 3300 * 34.5 + 129.3 * 1000 = 243150
#define TEMP_ADC(v) ((129.3 * 1000 + 34.5 * v)/1000)

#define TEMP_MIN_PERMITIDA (152)	//Grados celcius
#define PERIODO (0.5)				//Periodo con el que se ejecuta el PWM

//Constantes de control PI

//Primera prueba:
//#define KP (10)
//#define KI (0)
//#define KT (1)	//<-- Esta es para el antiwindup

//Segunda prueba:
#define KP (10)
#define KI (0.1)
#define KT (1)		//<-- Esta es para el antiwindup

//Tercera prueba:
//#define KP (10)
//#define KI (0.1)
//#define KT (1)

#endif
