/* En este archivo se describen las operacionse que hace el LCD en el statechart.
 * Por ejemplo, la función de escritura de un mensaje en la pantalla. Esta función
 * es invocada por el statechart.
 */

#include "lcd_operations.h"

extern void prefixIface_opMostrar_msj(const Prefix* handle, const sc_string Mensaje, const sc_integer fil, const sc_integer col)
{
	/* Esta función se encarga de mostrar un mensaje en un display LCD 16x2.
	 * Se le indica el mensaje y en qué posición escribir */

	lcdGoToXY( fil, col ); // Poner cursor en fil, col
	lcdSendStringRaw( "                " );
	lcdGoToXY( fil, col ); // Poner cursor en fil, col
	lcdSendStringRaw(Mensaje);
}
