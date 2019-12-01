#include "uart.h"
extern bool_t isStringComplete;
extern char strbuffer[];

extern void prefixInternal_opSend_Status(const Prefix* handle, const sc_integer st, const sc_integer temp, const sc_integer setpoint) {
	char T[10];			//Variable donde se guarda el dato convertido a string
	char SP[10];
	char * STATUS;
	itoa(temp, T,10);		//Convierto a una string
	itoa(setpoint, SP,10);		//Convierto a una string
	STATUS = "OFF";
	if (st == 1) {
		STATUS = "ON";
	}
	uartWriteString( UART_USB, STATUS );
	uartWriteString( UART_USB, "," );
	uartWriteString( UART_USB, T );
	uartWriteString( UART_USB, "," );
	uartWriteString( UART_USB, SP );
	uartWriteString( UART_USB, "\r\n" );
}




