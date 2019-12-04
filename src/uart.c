#include "uart.h"
#include "utils.h"
#include <string.h>

extern void prefixInternal_opSend_Status(const Prefix* handle, const sc_integer st, const sc_integer temp, const sc_integer setpoint, const sc_integer extr_st)
{
	char T[10];				//Variable donde se guarda el dato convertido a string
	char SP[10];
	char * STATUS;
	char * EXTR;			//Variable que indica si se está extruyendo, si está detenido o si está en reversa

	char mander[50] = "";



	itoa(temp, T,10);		//Convierto a una string
	itoa(setpoint, SP,10);	//Convierto a una string
	STATUS = "OFF";

	EXTR = "OFF";

	if (st == 1) {
		STATUS = "ON";
	}

	clearstring(mander);
	strcat(mander, STATUS);
	strcat(mander, ",");
	strcat(mander, T);
	strcat(mander, ",");
	strcat(mander, SP);
	strcat(mander, "\n");

	if(extr_st == 1)
	{
		EXTR = "ON";
	}

//	uartWriteString( UART_232, STATUS );
//	uartWriteString( UART_232, "," );
//	uartWriteString( UART_232, T );
//	uartWriteString( UART_232, "," );
//	uartWriteString( UART_232, SP );
//	uartWriteString( UART_232, "\n" );
	uartWriteString( UART_232, mander);
	uartWriteString( UART_USB, mander);
//	//DEBUG
//	uartWriteString( UART_USB, STATUS );
//	uartWriteString( UART_USB, "," );
//	uartWriteString( UART_USB, T );
//	uartWriteString( UART_USB, "," );
//	uartWriteString( UART_USB, SP );
//	uartWriteString( UART_USB, "\r\n" );
}







