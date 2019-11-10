/* En este archivo se describen las operacionse que hace el LCD en el statechart.
 * Por ejemplo, la función de escritura de un mensaje en la pantalla. Esta función
 * es invocada por el statechart.
 */

#include "lcd_operations.h"
#include "utils.h"

extern void prefixIface_opMostrar_msj(const Prefix* handle, const sc_string Mensaje, const sc_integer fil, const sc_integer col)
{
	/* Esta función se encarga de mostrar un mensaje en un display LCD 16x2.
	 * Se le indica el mensaje y en qué posición escribir */

	lcdGoToXY( fil, col ); // Poner cursor en fil, col
	lcdSendStringRaw( "                " );
	lcdGoToXY( fil, col ); // Poner cursor en fil, col
	lcdSendStringRaw(Mensaje);
}

extern void prefixIface_opMostrar_num(const Prefix* handle, const sc_integer Numero, const sc_integer fil, const sc_integer col)
{
	/* Esta función recibe un número, lo convierte a string y lo muestra
	 * por el LCD.*/

	char result[COLUMNAS_LCD];		//Variable donde se guarda el dato convertido a string


	itoa(Numero, result,10);		//Convierto a una string

	lcdGoToXY( fil, col ); // Poner cursor en fil, col
	lcdSendStringRaw( "                " );
	lcdGoToXY( fil, col ); // Poner cursor en fil, col
	lcdSendStringRaw(result);
}
