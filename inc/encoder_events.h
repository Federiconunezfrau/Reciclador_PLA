#ifndef _LCD_H_INCLUDED_
#define _LCD_H_INCLUDED_

#include "Prefix.h"
#include "rotary_encoder_state.h"


void identificar_rotacion_encoder(unsigned char,Prefix*);
void identificar_eventos_encoder(Prefix *, rotary_encoder_t *);


#endif
