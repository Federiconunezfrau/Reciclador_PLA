/* Primera prueba del reciclador PLA sistemas embebidos 2c 2019*/


#include "sapi.h"					//Inclusión de la sAPI de la EDU-CIAA
#include "sapi_debugPrint.h"		//Biblioteca de uso de UART

#include "TimerTicks.h"				//Biblioteca de manejo de timers en el statechart de Yakindu


#include "Prefix.h"					//Statechart de Yakindu
#include "PrefixRequired.h"			//Funciones que hay que definir del statechart

#include "board_connections.h"		//Pines de la placa donde se conecta cada periférico

#include "rotary_encoder_state.h"	//Biblioteca de uso del encoder


#include "encoder_events.h"			//Funciones que leen el encoder y levantan eventos en el statechart
#include "lcd_operations.h"			//Operaciones del statechart del LCD
#include "puente_h_operations.h"	//Operaciones del statechart del puente h



//=================================================================
//Macros asociadas a la interrupción de ticks para el uso del statechart

#define TICKRATE_1MS	(1)											/* 1000 ticks per second */
#define TICKRATE_MS		(TICKRATE_1MS)								/* 1000 ticks per second */
#define NOF_TIMERS (sizeof(PrefixTimeEvents)/sizeof(sc_boolean))	//Cantidad de Timers del statechart

//=================================================================
//Macros asociadas al uso de la uart
//Agrego esto de la UART solo porque en los ejemplos de yakindu lo dejan, aunque no
//lo usemos.

#define UART_SELECTED UART_USB		//Se envía por puerto serie a través del cable USB

CONSOLE_PRINT_ENABLE				//Macro necesaria para usar la UART

/* VARIABLES Y FUNCIONES DE YAKINDU *****************************************************/
//=================================================================
//Definición de la variable donde se administran los diferentes timers del statechart

TimerTicks ticks[NOF_TIMERS];

//=================================================================
//Funciones utilizadas por Yakindu para manejar sus timers

extern void prefix_setTimer(Prefix* handle, const sc_eventid evid, const sc_integer time_ms, const sc_boolean periodic)
{
	/*! This function has to set up timers for the time events that are required by the state machine. */
	/*!
		This function will be called for each time event that is relevant for a state when a state will be entered.
		\param evid An unique identifier of the event.
		\time_ms The time in milli seconds
		\periodic Indicates the the time event must be raised periodically until the timer is unset */

	SetNewTimerTick(ticks, NOF_TIMERS, evid, time_ms, periodic);
}

extern void prefix_unsetTimer(Prefix* handle, const sc_eventid evid)
{
	/*! This function has to unset timers for the time events that are required by the state machine. */
	/*!
		This function will be called for each time event taht is relevant for a state when a state will be left.
		\param evid An unique identifier of the event.*/

	UnsetTimerTick(ticks, NOF_TIMERS, evid);
}

//=================================================================
//Declaración de la variable del statechart de Yakindu
static Prefix statechart;


//=================================================================
//Creo una estructura del tipo puente h
//volatile puenteh_t p;

//=================================================================
//Funciones del statechart que deben definirse

//extern void prefixIface_opMostrar_msj(const Prefix* handle, const sc_string Mensaje, const sc_integer fil, const sc_integer col)
//{
	/* Esta función se encarga de mostrar un mensaje en un display LCD 16x2.
	 * Se le indica el mensaje y en qué posición escribir */

//	lcdGoToXY( fil, col ); // Poner cursor en fil, col
//	lcdSendStringRaw( "                " );
//	lcdGoToXY( fil, col ); // Poner cursor en fil, col
//	lcdSendStringRaw(Mensaje);
//}

//extern void prefixInternal_opStart_puente_h(const Prefix* handle)
//{
	/* Esta función se encarga de hacer girar el motor del extrusor */

//	gpioWrite(PIN_PUENTE_1, TRUE);
//	gpioWrite(PIN_PUENTE_2, FALSE);

//}
//extern void prefixInternal_opStop_puente_h(const Prefix* handle)
//{
	/* Esta función se encarga de detener el motor del extrusor */

//	gpioWrite(PIN_PUENTE_1,FALSE);
//	gpioWrite(PIN_PUENTE_2,FALSE);
//}

//=================================================================
//Variables y funciones para ejecutar el statechart en el main, con un tiempo periódico

volatile bool SysTick_Time_Flag = false;

void myTickHook( void *ptr )
{
	SysTick_Time_Flag = true;
}
/****************************************************************************************/

//=================================================================
//Programa principal
int main(void)
{
	//Configuración inicial de la placa
	boardConfig();

	/* Init Ticks counter => TICKRATE_MS */
	tickConfig( TICKRATE_MS );

	/* Add Tick Hook */
	tickCallbackSet( myTickHook, (void*)NULL );

	//Inicializo el uso del LCD, como de 16x2 y caracteres de 5x8 pixeles
	lcdInit( 16, 2, 5, 8 );

	//Creo un contador que uso después
	uint32_t i;

	//Creo una instancia de la estructura rotary encoder
	rotary_encoder_t r;

	//Configuro el encoder para el primer uso
	rotary_encoder_conf(&r,PIN_CANAL_1,PIN_CANAL_2,PIN_PULSADOR);

	//Función que limpia la pantalla del LCD
	lcdClear();

	InitTimerTicks(ticks, NOF_TIMERS);

	//Inicializo el statechart para su uso
	prefix_init(&statechart);

	//Comienza a funcionar el statechart
	prefix_enter(&statechart);

	//Bucle principal
	while(1)
	{
		/* Me quedo esperando por la interrupción de ticks, que se ejecuta cada 1ms.
		 * Es decir que el statechart se procesa cada 1ms aprox.*/

		__WFI();	//<-- Wait For Interruption

		if (SysTick_Time_Flag == true)
		{
			SysTick_Time_Flag = false;

			/* Se procesan todos los timers utilizados por el statechart.*/
			//Porción de código extraída de los ejemplos de Yakindu
			UpdateTimers(ticks, NOF_TIMERS);
			for (i = 0; i < NOF_TIMERS; i++)
			{
				if (IsPendEvent(ticks, NOF_TIMERS, ticks[i].evid) == true)
				{
					prefix_raiseTimeEvent(&statechart, ticks[i].evid);	// Event -> Ticks.evid => OK
					MarkAsAttEvent(ticks, NOF_TIMERS, ticks[i].evid);
				}
			}

			/* Se identifican todos los eventos asociados al encoder.*/
			identificar_eventos_encoder(&statechart, &r);

			/*Se actualiza el statechart*/
			prefix_runCycle(&statechart);
		}
	}
}
