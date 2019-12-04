
#include <stdlib.h>
#include <string.h>
#include "sc_types.h"
#include "Prefix.h"
#include "PrefixRequired.h"
/*! \file Implementation of the state machine 'prefix'
*/

/* prototypes of all internal functions */
static sc_boolean prefix_check_BOTON_DEL_ENCODER_DEBOUNCE_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_BOTON_DEL_ENCODER_NO_OPRIMIDO_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_BOTON_DEL_ENCODER_OPRIMIDO_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_BOTON_DEL_ENCODER_VALIDACION_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_BOTON_DEL_ENCODER_VALIDACION_tr1_tr1(const Prefix* handle);
static sc_boolean prefix_check_ENCODER_REPOSO_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_ENCODER_REPOSO_tr1_tr1(const Prefix* handle);
static sc_boolean prefix_check_ENCODER_REPOSO_tr2_tr2(const Prefix* handle);
static sc_boolean prefix_check_ENCODER_REPOSO_tr3_tr3(const Prefix* handle);
static sc_boolean prefix_check_ENCODER_ROTACION_DERECHA_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_ENCODER_ROTACION_IZQUIERDA_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_MOTORES_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_MOTORES_tr1_tr1(const Prefix* handle);
static sc_boolean prefix_check_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_MOTORES_tr2_tr2(const Prefix* handle);
static sc_boolean prefix_check_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP_tr1_tr1(const Prefix* handle);
static sc_boolean prefix_check_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP_tr2_tr2(const Prefix* handle);
static sc_boolean prefix_check_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_WI_FI_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_WI_FI_tr1_tr1(const Prefix* handle);
static sc_boolean prefix_check_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_WI_FI_tr2_tr2(const Prefix* handle);
static sc_boolean prefix_check_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION_tr1_tr1(const Prefix* handle);
static sc_boolean prefix_check_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION_tr2_tr2(const Prefix* handle);
static sc_boolean prefix_check_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_CANCELAR_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_CANCELAR_tr1_tr1(const Prefix* handle);
static sc_boolean prefix_check_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_CANCELAR_tr2_tr2(const Prefix* handle);
static sc_boolean prefix_check_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_SETEAR_TEMP_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_SETEAR_TEMP_tr1_tr1(const Prefix* handle);
static sc_boolean prefix_check_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_SETEAR_TEMP_tr2_tr2(const Prefix* handle);
static sc_boolean prefix_check_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR_tr1_tr1(const Prefix* handle);
static sc_boolean prefix_check_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR_tr2_tr2(const Prefix* handle);
static sc_boolean prefix_check_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_CANCELAR_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_CANCELAR_tr1_tr1(const Prefix* handle);
static sc_boolean prefix_check_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_CANCELAR_tr2_tr2(const Prefix* handle);
static sc_boolean prefix_check_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION_tr1_tr1(const Prefix* handle);
static sc_boolean prefix_check_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION_tr2_tr2(const Prefix* handle);
static sc_boolean prefix_check_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION_tr1_tr1(const Prefix* handle);
static sc_boolean prefix_check_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION_tr2_tr2(const Prefix* handle);
static sc_boolean prefix_check_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT_tr1_tr1(const Prefix* handle);
static sc_boolean prefix_check_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT_tr2_tr2(const Prefix* handle);
static sc_boolean prefix_check_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP_tr1_tr1(const Prefix* handle);
static sc_boolean prefix_check_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP_tr2_tr2(const Prefix* handle);
static sc_boolean prefix_check_LCD_MENU_WIFI_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_PUENTE_H_STOP_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_PUENTE_H_STOP_tr1_tr1(const Prefix* handle);
static sc_boolean prefix_check_PUENTE_H_H_ROTACION_HORARIO_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_PUENTE_H_H_ROTACION_HORARIO_tr1_tr1(const Prefix* handle);
static sc_boolean prefix_check_PUENTE_H_CONFIGURAR_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_PUENTE_H_H_RETRACT_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_PUENTE_H_H_RETRACT_tr1_tr1(const Prefix* handle);
static sc_boolean prefix_check_x_TEMP_APAGADO_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_x_TEMP_CALENTAR_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_x_TEMP_CALENTAR_EJECUTAR_CONTROL_TEMP_CONTROL_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_x_TEMP_CALENTAR_ENVIAR_DATOS_TEMP_ENVIAR_UART_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_x_TEMP_CONF_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_UART_UART_SEND_STATUS_tr0_tr0(const Prefix* handle);
static void prefix_effect_BOTON_DEL_ENCODER_DEBOUNCE_tr0(Prefix* handle);
static void prefix_effect_BOTON_DEL_ENCODER_NO_OPRIMIDO_tr0(Prefix* handle);
static void prefix_effect_BOTON_DEL_ENCODER_OPRIMIDO_tr0(Prefix* handle);
static void prefix_effect_BOTON_DEL_ENCODER_VALIDACION_tr0(Prefix* handle);
static void prefix_effect_BOTON_DEL_ENCODER_VALIDACION_tr1(Prefix* handle);
static void prefix_effect_ENCODER_REPOSO_tr0(Prefix* handle);
static void prefix_effect_ENCODER_REPOSO_tr1(Prefix* handle);
static void prefix_effect_ENCODER_REPOSO_tr2(Prefix* handle);
static void prefix_effect_ENCODER_REPOSO_tr3(Prefix* handle);
static void prefix_effect_ENCODER_ROTACION_DERECHA_tr0(Prefix* handle);
static void prefix_effect_ENCODER_ROTACION_IZQUIERDA_tr0(Prefix* handle);
static void prefix_effect_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_MOTORES_tr0(Prefix* handle);
static void prefix_effect_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_MOTORES_tr1(Prefix* handle);
static void prefix_effect_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_MOTORES_tr2(Prefix* handle);
static void prefix_effect_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP_tr0(Prefix* handle);
static void prefix_effect_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP_tr1(Prefix* handle);
static void prefix_effect_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP_tr2(Prefix* handle);
static void prefix_effect_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_WI_FI_tr0(Prefix* handle);
static void prefix_effect_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_WI_FI_tr1(Prefix* handle);
static void prefix_effect_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_WI_FI_tr2(Prefix* handle);
static void prefix_effect_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION_tr0(Prefix* handle);
static void prefix_effect_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION_tr1(Prefix* handle);
static void prefix_effect_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION_tr2(Prefix* handle);
static void prefix_effect_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_CANCELAR_tr0(Prefix* handle);
static void prefix_effect_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_CANCELAR_tr1(Prefix* handle);
static void prefix_effect_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_CANCELAR_tr2(Prefix* handle);
static void prefix_effect_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_SETEAR_TEMP_tr0(Prefix* handle);
static void prefix_effect_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_SETEAR_TEMP_tr1(Prefix* handle);
static void prefix_effect_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_SETEAR_TEMP_tr2(Prefix* handle);
static void prefix_effect_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR_tr0(Prefix* handle);
static void prefix_effect_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR_tr1(Prefix* handle);
static void prefix_effect_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR_tr2(Prefix* handle);
static void prefix_effect_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_CANCELAR_tr0(Prefix* handle);
static void prefix_effect_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_CANCELAR_tr1(Prefix* handle);
static void prefix_effect_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_CANCELAR_tr2(Prefix* handle);
static void prefix_effect_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION_tr0(Prefix* handle);
static void prefix_effect_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION_tr1(Prefix* handle);
static void prefix_effect_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION_tr2(Prefix* handle);
static void prefix_effect_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION_tr0(Prefix* handle);
static void prefix_effect_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION_tr1(Prefix* handle);
static void prefix_effect_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION_tr2(Prefix* handle);
static void prefix_effect_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT_tr0(Prefix* handle);
static void prefix_effect_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT_tr1(Prefix* handle);
static void prefix_effect_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT_tr2(Prefix* handle);
static void prefix_effect_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP_tr0(Prefix* handle);
static void prefix_effect_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP_tr1(Prefix* handle);
static void prefix_effect_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP_tr2(Prefix* handle);
static void prefix_effect_LCD_MENU_WIFI_tr0(Prefix* handle);
static void prefix_effect_PUENTE_H_STOP_tr0(Prefix* handle);
static void prefix_effect_PUENTE_H_STOP_tr1(Prefix* handle);
static void prefix_effect_PUENTE_H_H_ROTACION_HORARIO_tr0(Prefix* handle);
static void prefix_effect_PUENTE_H_H_ROTACION_HORARIO_tr1(Prefix* handle);
static void prefix_effect_PUENTE_H_CONFIGURAR_tr0(Prefix* handle);
static void prefix_effect_PUENTE_H_H_RETRACT_tr0(Prefix* handle);
static void prefix_effect_PUENTE_H_H_RETRACT_tr1(Prefix* handle);
static void prefix_effect_x_TEMP_APAGADO_tr0(Prefix* handle);
static void prefix_effect_x_TEMP_CALENTAR_tr0(Prefix* handle);
static void prefix_effect_x_TEMP_CALENTAR_EJECUTAR_CONTROL_TEMP_CONTROL_tr0(Prefix* handle);
static void prefix_effect_x_TEMP_CALENTAR_ENVIAR_DATOS_TEMP_ENVIAR_UART_tr0(Prefix* handle);
static void prefix_effect_x_TEMP_CONF_tr0(Prefix* handle);
static void prefix_effect_UART_UART_SEND_STATUS_tr0(Prefix* handle);
static void prefix_enact_BOTON_DEL_ENCODER_DEBOUNCE(Prefix* handle);
static void prefix_enact_BOTON_DEL_ENCODER_OPRIMIDO(Prefix* handle);
static void prefix_enact_ENCODER_REPOSO(Prefix* handle);
static void prefix_enact_ENCODER_ROTACION_DERECHA(Prefix* handle);
static void prefix_enact_ENCODER_ROTACION_IZQUIERDA(Prefix* handle);
static void prefix_enact_LCD_MENU_PRINCIPAL(Prefix* handle);
static void prefix_enact_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_MOTORES(Prefix* handle);
static void prefix_enact_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP(Prefix* handle);
static void prefix_enact_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_WI_FI(Prefix* handle);
static void prefix_enact_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION(Prefix* handle);
static void prefix_enact_LCD_MENU_CONF_TEMP(Prefix* handle);
static void prefix_enact_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_CANCELAR(Prefix* handle);
static void prefix_enact_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_SETEAR_TEMP(Prefix* handle);
static void prefix_enact_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR(Prefix* handle);
static void prefix_enact_LCD_MENU_CONF_MOTORES(Prefix* handle);
static void prefix_enact_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_CANCELAR(Prefix* handle);
static void prefix_enact_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION(Prefix* handle);
static void prefix_enact_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION(Prefix* handle);
static void prefix_enact_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT(Prefix* handle);
static void prefix_enact_LCD_MENU_SET_TEMP(Prefix* handle);
static void prefix_enact_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP(Prefix* handle);
static void prefix_enact_LCD_MENU_WIFI(Prefix* handle);
static void prefix_enact_PUENTE_H_STOP(Prefix* handle);
static void prefix_enact_PUENTE_H_H_ROTACION_HORARIO(Prefix* handle);
static void prefix_enact_PUENTE_H_CONFIGURAR(Prefix* handle);
static void prefix_enact_PUENTE_H_H_RETRACT(Prefix* handle);
static void prefix_enact_x_TEMP_APAGADO(Prefix* handle);
static void prefix_enact_x_TEMP_CALENTAR(Prefix* handle);
static void prefix_enact_x_TEMP_CALENTAR_EJECUTAR_CONTROL_TEMP_CONTROL(Prefix* handle);
static void prefix_enact_x_TEMP_CALENTAR_ENVIAR_DATOS_TEMP_ENVIAR_UART(Prefix* handle);
static void prefix_enact_x_TEMP_CONF(Prefix* handle);
static void prefix_enact_UART_UART_SEND_STATUS(Prefix* handle);
static void prefix_exact_BOTON_DEL_ENCODER_DEBOUNCE(Prefix* handle);
static void prefix_exact_x_TEMP_CALENTAR_EJECUTAR_CONTROL_TEMP_CONTROL(Prefix* handle);
static void prefix_exact_x_TEMP_CALENTAR_ENVIAR_DATOS_TEMP_ENVIAR_UART(Prefix* handle);
static void prefix_exact_UART_UART_SEND_STATUS(Prefix* handle);
static void prefix_enseq_BOTON_DEL_ENCODER_DEBOUNCE_default(Prefix* handle);
static void prefix_enseq_BOTON_DEL_ENCODER_NO_OPRIMIDO_default(Prefix* handle);
static void prefix_enseq_BOTON_DEL_ENCODER_OPRIMIDO_default(Prefix* handle);
static void prefix_enseq_BOTON_DEL_ENCODER_VALIDACION_default(Prefix* handle);
static void prefix_enseq_ENCODER_REPOSO_default(Prefix* handle);
static void prefix_enseq_ENCODER_ROTACION_DERECHA_default(Prefix* handle);
static void prefix_enseq_ENCODER_ROTACION_IZQUIERDA_default(Prefix* handle);
static void prefix_enseq_LCD_MENU_PRINCIPAL_default(Prefix* handle);
static void prefix_enseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_MOTORES_default(Prefix* handle);
static void prefix_enseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP_default(Prefix* handle);
static void prefix_enseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_WI_FI_default(Prefix* handle);
static void prefix_enseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION_default(Prefix* handle);
static void prefix_enseq_LCD_MENU_CONF_TEMP_default(Prefix* handle);
static void prefix_enseq_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_CANCELAR_default(Prefix* handle);
static void prefix_enseq_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_SETEAR_TEMP_default(Prefix* handle);
static void prefix_enseq_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR_default(Prefix* handle);
static void prefix_enseq_LCD_MENU_CONF_MOTORES_default(Prefix* handle);
static void prefix_enseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_CANCELAR_default(Prefix* handle);
static void prefix_enseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION_default(Prefix* handle);
static void prefix_enseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION_default(Prefix* handle);
static void prefix_enseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT_default(Prefix* handle);
static void prefix_enseq_LCD_MENU_SET_TEMP_default(Prefix* handle);
static void prefix_enseq_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP_default(Prefix* handle);
static void prefix_enseq_LCD_MENU_WIFI_default(Prefix* handle);
static void prefix_enseq_PUENTE_H_STOP_default(Prefix* handle);
static void prefix_enseq_PUENTE_H_H_ROTACION_HORARIO_default(Prefix* handle);
static void prefix_enseq_PUENTE_H_CONFIGURAR_default(Prefix* handle);
static void prefix_enseq_PUENTE_H_H_RETRACT_default(Prefix* handle);
static void prefix_enseq_x_TEMP_APAGADO_default(Prefix* handle);
static void prefix_enseq_x_TEMP_CALENTAR_default(Prefix* handle);
static void prefix_enseq_x_TEMP_CALENTAR_EJECUTAR_CONTROL_TEMP_CONTROL_default(Prefix* handle);
static void prefix_enseq_x_TEMP_CALENTAR_ENVIAR_DATOS_TEMP_ENVIAR_UART_default(Prefix* handle);
static void prefix_enseq_x_TEMP_CONF_default(Prefix* handle);
static void prefix_enseq_UART_UART_SEND_STATUS_default(Prefix* handle);
static void prefix_enseq_BOTON_DEL_ENCODER_default(Prefix* handle);
static void prefix_enseq_ENCODER_default(Prefix* handle);
static void prefix_enseq_LCD_default(Prefix* handle);
static void prefix_enseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_default(Prefix* handle);
static void prefix_enseq_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_default(Prefix* handle);
static void prefix_enseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_default(Prefix* handle);
static void prefix_enseq_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_default(Prefix* handle);
static void prefix_enseq_PUENTE_H_default(Prefix* handle);
static void prefix_enseq_x_default(Prefix* handle);
static void prefix_enseq_x_TEMP_CALENTAR_EJECUTAR_CONTROL_default(Prefix* handle);
static void prefix_enseq_x_TEMP_CALENTAR_ENVIAR_DATOS_default(Prefix* handle);
static void prefix_enseq_UART_default(Prefix* handle);
static void prefix_exseq_BOTON_DEL_ENCODER_DEBOUNCE(Prefix* handle);
static void prefix_exseq_BOTON_DEL_ENCODER_NO_OPRIMIDO(Prefix* handle);
static void prefix_exseq_BOTON_DEL_ENCODER_OPRIMIDO(Prefix* handle);
static void prefix_exseq_BOTON_DEL_ENCODER_VALIDACION(Prefix* handle);
static void prefix_exseq_ENCODER_REPOSO(Prefix* handle);
static void prefix_exseq_ENCODER_ROTACION_DERECHA(Prefix* handle);
static void prefix_exseq_ENCODER_ROTACION_IZQUIERDA(Prefix* handle);
static void prefix_exseq_LCD_MENU_PRINCIPAL(Prefix* handle);
static void prefix_exseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_MOTORES(Prefix* handle);
static void prefix_exseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP(Prefix* handle);
static void prefix_exseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_WI_FI(Prefix* handle);
static void prefix_exseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION(Prefix* handle);
static void prefix_exseq_LCD_MENU_CONF_TEMP(Prefix* handle);
static void prefix_exseq_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_CANCELAR(Prefix* handle);
static void prefix_exseq_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_SETEAR_TEMP(Prefix* handle);
static void prefix_exseq_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR(Prefix* handle);
static void prefix_exseq_LCD_MENU_CONF_MOTORES(Prefix* handle);
static void prefix_exseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_CANCELAR(Prefix* handle);
static void prefix_exseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION(Prefix* handle);
static void prefix_exseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION(Prefix* handle);
static void prefix_exseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT(Prefix* handle);
static void prefix_exseq_LCD_MENU_SET_TEMP(Prefix* handle);
static void prefix_exseq_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP(Prefix* handle);
static void prefix_exseq_LCD_MENU_WIFI(Prefix* handle);
static void prefix_exseq_PUENTE_H_STOP(Prefix* handle);
static void prefix_exseq_PUENTE_H_H_ROTACION_HORARIO(Prefix* handle);
static void prefix_exseq_PUENTE_H_CONFIGURAR(Prefix* handle);
static void prefix_exseq_PUENTE_H_H_RETRACT(Prefix* handle);
static void prefix_exseq_x_TEMP_APAGADO(Prefix* handle);
static void prefix_exseq_x_TEMP_CALENTAR(Prefix* handle);
static void prefix_exseq_x_TEMP_CALENTAR_EJECUTAR_CONTROL_TEMP_CONTROL(Prefix* handle);
static void prefix_exseq_x_TEMP_CALENTAR_ENVIAR_DATOS_TEMP_ENVIAR_UART(Prefix* handle);
static void prefix_exseq_x_TEMP_CONF(Prefix* handle);
static void prefix_exseq_UART_UART_SEND_STATUS(Prefix* handle);
static void prefix_exseq_BOTON_DEL_ENCODER(Prefix* handle);
static void prefix_exseq_ENCODER(Prefix* handle);
static void prefix_exseq_LCD(Prefix* handle);
static void prefix_exseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL(Prefix* handle);
static void prefix_exseq_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP(Prefix* handle);
static void prefix_exseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES(Prefix* handle);
static void prefix_exseq_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP(Prefix* handle);
static void prefix_exseq_PUENTE_H(Prefix* handle);
static void prefix_exseq_x(Prefix* handle);
static void prefix_exseq_x_TEMP_CALENTAR_EJECUTAR_CONTROL(Prefix* handle);
static void prefix_exseq_x_TEMP_CALENTAR_ENVIAR_DATOS(Prefix* handle);
static void prefix_exseq_UART(Prefix* handle);
static void prefix_react_BOTON_DEL_ENCODER_DEBOUNCE(Prefix* handle);
static void prefix_react_BOTON_DEL_ENCODER_NO_OPRIMIDO(Prefix* handle);
static void prefix_react_BOTON_DEL_ENCODER_OPRIMIDO(Prefix* handle);
static void prefix_react_BOTON_DEL_ENCODER_VALIDACION(Prefix* handle);
static void prefix_react_ENCODER_REPOSO(Prefix* handle);
static void prefix_react_ENCODER_ROTACION_DERECHA(Prefix* handle);
static void prefix_react_ENCODER_ROTACION_IZQUIERDA(Prefix* handle);
static void prefix_react_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_MOTORES(Prefix* handle);
static void prefix_react_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP(Prefix* handle);
static void prefix_react_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_WI_FI(Prefix* handle);
static void prefix_react_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION(Prefix* handle);
static void prefix_react_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_CANCELAR(Prefix* handle);
static void prefix_react_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_SETEAR_TEMP(Prefix* handle);
static void prefix_react_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR(Prefix* handle);
static void prefix_react_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_CANCELAR(Prefix* handle);
static void prefix_react_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION(Prefix* handle);
static void prefix_react_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION(Prefix* handle);
static void prefix_react_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT(Prefix* handle);
static void prefix_react_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP(Prefix* handle);
static void prefix_react_LCD_MENU_WIFI(Prefix* handle);
static void prefix_react_PUENTE_H_STOP(Prefix* handle);
static void prefix_react_PUENTE_H_H_ROTACION_HORARIO(Prefix* handle);
static void prefix_react_PUENTE_H_CONFIGURAR(Prefix* handle);
static void prefix_react_PUENTE_H_H_RETRACT(Prefix* handle);
static void prefix_react_x_TEMP_APAGADO(Prefix* handle);
static void prefix_react_x_TEMP_CALENTAR_EJECUTAR_CONTROL_TEMP_CONTROL(Prefix* handle);
static void prefix_react_x_TEMP_CALENTAR_ENVIAR_DATOS_TEMP_ENVIAR_UART(Prefix* handle);
static void prefix_react_x_TEMP_CONF(Prefix* handle);
static void prefix_react_UART_UART_SEND_STATUS(Prefix* handle);
static void prefix_react_BOTON_DEL_ENCODER__entry_Default(Prefix* handle);
static void prefix_react_ENCODER__entry_Default(Prefix* handle);
static void prefix_react_LCD__entry_Default(Prefix* handle);
static void prefix_react_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL__entry_Default(Prefix* handle);
static void prefix_react_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP__entry_Default(Prefix* handle);
static void prefix_react_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES__entry_Default(Prefix* handle);
static void prefix_react_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP__entry_Default(Prefix* handle);
static void prefix_react_PUENTE_H__entry_Default(Prefix* handle);
static void prefix_react_x__entry_Default(Prefix* handle);
static void prefix_react_x_TEMP_CALENTAR_EJECUTAR_CONTROL__entry_Default(Prefix* handle);
static void prefix_react_x_TEMP_CALENTAR_ENVIAR_DATOS__entry_Default(Prefix* handle);
static void prefix_react_UART__entry_Default(Prefix* handle);
static void prefix_clearInEvents(Prefix* handle);
static void prefix_clearOutEvents(Prefix* handle);

const sc_integer PREFIX_PREFIXIFACE_MAX_DER_COUNT = 3;
const sc_integer PREFIX_PREFIXIFACE_MAX_IZQ_COUNT = 3;
const sc_integer PREFIX_PREFIXIFACE_TRUE_ID = 0;
const sc_integer PREFIX_PREFIXIFACE_FALSE_ID = 1;
const sc_boolean PREFIX_PREFIXIFACE_HORARIO = bool_true;
const sc_boolean PREFIX_PREFIXIFACE_ANTIHORARIO = bool_false;
const sc_string PREFIX_PREFIXIFACE_MSJ_MENU_PRINCIPAL = "Menu principal";
const sc_string PREFIX_PREFIXIFACE_MSJ_MENU_CONF_MOTORES = "Conf motores";
const sc_string PREFIX_PREFIXIFACE_MSJ_MENU_CONF_WI_FI = "Conf Wi-Fi";
const sc_string PREFIX_PREFIXIFACE_MSJ_MENU_EXTRUIR = "Extrusion";
const sc_string PREFIX_PREFIXIFACE_MSJ_MENU_CONF_TEMP = "Conf temp";
const sc_string PREFIX_PREFIXIFACE_MSJ_MENU_CANCELAR = "Cancelar";
const sc_string PREFIX_PREFIXIFACE_MSJ_MENU_MOTOR_EXTRUSION = "Start extrusión";
const sc_string PREFIX_PREFIXIFACE_MSJ_MENU_MOTOR_EXTRUSION_STOP = "Stop extrusion/retract";
const sc_string PREFIX_PREFIXIFACE_MSJ_MENU_MOTOR_EXTRUSION_RETRACT = "Start retract";
const sc_string PREFIX_PREFIXIFACE_MSJ_MENU_SETEAR_TEMP = "Set temp";
const sc_string PREFIX_PREFIXIFACE_MSJ_MENU_ENFRIAR = "Off temp";
const sc_string PREFIX_PREFIXIFACE_MSJ_MENU_SET_TEMP = "Temperature ? [°C]";
const sc_string PREFIX_PREFIXIFACE_MSJ_MENU_WIFI = "IP";

void prefix_init(Prefix* handle)
{
	sc_integer i;

	for (i = 0; i < PREFIX_MAX_ORTHOGONAL_STATES; ++i)
	{
		handle->stateConfVector[i] = Prefix_last_state;
	}
	
	
	handle->stateConfVectorPosition = 0;

	prefix_clearInEvents(handle);
	prefix_clearOutEvents(handle);

	/* Default init sequence for statechart prefix */
	handle->internal.viEnc_count_der = 0;
	handle->internal.viEnc_count_izq = 0;
	handle->internal.viEnc_volver = 0;
	handle->internal.viTecla = 0;
	handle->internal.viSet_temp_lcd = 0;
	handle->internal.viActual_temp = 0;
	handle->internal.viRef_temp = 0;
	handle->internal.viTemp = 0;
	handle->internal.viSetPoint = 0;
	handle->internal.viStatus = 0;
	handle->internal.viIP = "";

}

void prefix_enter(Prefix* handle)
{
	/* Default enter sequence for statechart prefix */
	prefix_enseq_BOTON_DEL_ENCODER_default(handle);
	prefix_enseq_ENCODER_default(handle);
	prefix_enseq_LCD_default(handle);
	prefix_enseq_PUENTE_H_default(handle);
	prefix_enseq_x_default(handle);
	prefix_enseq_UART_default(handle);
}

void prefix_exit(Prefix* handle)
{
	/* Default exit sequence for statechart prefix */
	prefix_exseq_BOTON_DEL_ENCODER(handle);
	prefix_exseq_ENCODER(handle);
	prefix_exseq_LCD(handle);
	prefix_exseq_PUENTE_H(handle);
	prefix_exseq_x(handle);
	prefix_exseq_UART(handle);
}

sc_boolean prefix_isActive(const Prefix* handle)
{
	sc_boolean result;
	if (handle->stateConfVector[0] != Prefix_last_state || handle->stateConfVector[1] != Prefix_last_state || handle->stateConfVector[2] != Prefix_last_state || handle->stateConfVector[3] != Prefix_last_state || handle->stateConfVector[4] != Prefix_last_state || handle->stateConfVector[5] != Prefix_last_state || handle->stateConfVector[6] != Prefix_last_state)
	{
		result =  bool_true;
	}
	else
	{
		result = bool_false;
	}
	return result;
}

/* 
 * Always returns 'false' since this state machine can never become final.
 */
sc_boolean prefix_isFinal(const Prefix* handle)
{
   return bool_false;
}

static void prefix_clearInEvents(Prefix* handle)
{
	handle->iface.evActualizar_setpoint_raised = bool_false;
	handle->iface.evEnc_rot_derecha_raised = bool_false;
	handle->iface.evEnc_rot_izquierda_raised = bool_false;
	handle->iface.evEnc_boton_raised = bool_false;
	handle->iface.evTECXNoOprimido_raised = bool_false;
	handle->iface.evTECXOprimido_raised = bool_false;
	handle->iface.evPuente_h_alto_raised = bool_false;
	handle->iface.evPuente_h_horario_raised = bool_false;
	handle->iface.evPuente_h_antihorario_raised = bool_false;
	handle->iface.evConf_Ready_Puente_H_raised = bool_false;
	handle->iface.evConf_Ready_temp_raised = bool_false;
	handle->iface.evTemp_start_raised = bool_false;
	handle->iface.evTemp_stop_raised = bool_false;
	handle->iface.evStop_puente_h_raised = bool_false;
	handle->iface.evStart_puente_h_raised = bool_false;
	handle->iface.evRetract_puente_h_raised = bool_false;
	handle->internal.siDespl_derecha_raised = bool_false;
	handle->internal.siDespl_izquierda_raised = bool_false;
	handle->internal.siEntrar_raised = bool_false;
	handle->timeEvents.prefix_BOTON_DEL_ENCODER_DEBOUNCE_tev0_raised = bool_false;
	handle->timeEvents.prefix_x_TEMP_CALENTAR_EJECUTAR_CONTROL_TEMP_CONTROL_tev0_raised = bool_false;
	handle->timeEvents.prefix_x_TEMP_CALENTAR_ENVIAR_DATOS_TEMP_ENVIAR_UART_tev0_raised = bool_false;
	handle->timeEvents.prefix_UART_UART_SEND_STATUS_tev0_raised = bool_false;
}

static void prefix_clearOutEvents(Prefix* handle)
{
}

void prefix_runCycle(Prefix* handle)
{
	
	prefix_clearOutEvents(handle);
	
	for (handle->stateConfVectorPosition = 0;
		handle->stateConfVectorPosition < PREFIX_MAX_ORTHOGONAL_STATES;
		handle->stateConfVectorPosition++)
		{
			
		switch (handle->stateConfVector[handle->stateConfVectorPosition])
		{
		case Prefix_BOTON_DEL_ENCODER_DEBOUNCE :
		{
			prefix_react_BOTON_DEL_ENCODER_DEBOUNCE(handle);
			break;
		}
		case Prefix_BOTON_DEL_ENCODER_NO_OPRIMIDO :
		{
			prefix_react_BOTON_DEL_ENCODER_NO_OPRIMIDO(handle);
			break;
		}
		case Prefix_BOTON_DEL_ENCODER_OPRIMIDO :
		{
			prefix_react_BOTON_DEL_ENCODER_OPRIMIDO(handle);
			break;
		}
		case Prefix_BOTON_DEL_ENCODER_VALIDACION :
		{
			prefix_react_BOTON_DEL_ENCODER_VALIDACION(handle);
			break;
		}
		case Prefix_ENCODER_REPOSO :
		{
			prefix_react_ENCODER_REPOSO(handle);
			break;
		}
		case Prefix_ENCODER_ROTACION_DERECHA :
		{
			prefix_react_ENCODER_ROTACION_DERECHA(handle);
			break;
		}
		case Prefix_ENCODER_ROTACION_IZQUIERDA :
		{
			prefix_react_ENCODER_ROTACION_IZQUIERDA(handle);
			break;
		}
		case Prefix_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_MOTORES :
		{
			prefix_react_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_MOTORES(handle);
			break;
		}
		case Prefix_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP :
		{
			prefix_react_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP(handle);
			break;
		}
		case Prefix_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_WI_FI :
		{
			prefix_react_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_WI_FI(handle);
			break;
		}
		case Prefix_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION :
		{
			prefix_react_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION(handle);
			break;
		}
		case Prefix_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_CANCELAR :
		{
			prefix_react_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_CANCELAR(handle);
			break;
		}
		case Prefix_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_SETEAR_TEMP :
		{
			prefix_react_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_SETEAR_TEMP(handle);
			break;
		}
		case Prefix_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR :
		{
			prefix_react_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR(handle);
			break;
		}
		case Prefix_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_CANCELAR :
		{
			prefix_react_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_CANCELAR(handle);
			break;
		}
		case Prefix_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION :
		{
			prefix_react_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION(handle);
			break;
		}
		case Prefix_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION :
		{
			prefix_react_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION(handle);
			break;
		}
		case Prefix_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT :
		{
			prefix_react_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT(handle);
			break;
		}
		case Prefix_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP :
		{
			prefix_react_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP(handle);
			break;
		}
		case Prefix_LCD_MENU_WIFI :
		{
			prefix_react_LCD_MENU_WIFI(handle);
			break;
		}
		case Prefix_PUENTE_H_STOP :
		{
			prefix_react_PUENTE_H_STOP(handle);
			break;
		}
		case Prefix_PUENTE_H_H_ROTACION_HORARIO :
		{
			prefix_react_PUENTE_H_H_ROTACION_HORARIO(handle);
			break;
		}
		case Prefix_PUENTE_H_CONFIGURAR :
		{
			prefix_react_PUENTE_H_CONFIGURAR(handle);
			break;
		}
		case Prefix_PUENTE_H_H_RETRACT :
		{
			prefix_react_PUENTE_H_H_RETRACT(handle);
			break;
		}
		case Prefix_x_TEMP_APAGADO :
		{
			prefix_react_x_TEMP_APAGADO(handle);
			break;
		}
		case Prefix_x_TEMP_CALENTAR_EJECUTAR_CONTROL_TEMP_CONTROL :
		{
			prefix_react_x_TEMP_CALENTAR_EJECUTAR_CONTROL_TEMP_CONTROL(handle);
			break;
		}
		case Prefix_x_TEMP_CALENTAR_ENVIAR_DATOS_TEMP_ENVIAR_UART :
		{
			prefix_react_x_TEMP_CALENTAR_ENVIAR_DATOS_TEMP_ENVIAR_UART(handle);
			break;
		}
		case Prefix_x_TEMP_CONF :
		{
			prefix_react_x_TEMP_CONF(handle);
			break;
		}
		case Prefix_UART_UART_SEND_STATUS :
		{
			prefix_react_UART_UART_SEND_STATUS(handle);
			break;
		}
		default:
			break;
		}
	}
	
	prefix_clearInEvents(handle);
}

void prefix_raiseTimeEvent(const Prefix* handle, sc_eventid evid)
{
	if ( ((sc_intptr_t)evid) >= ((sc_intptr_t)&(handle->timeEvents))
		&&  ((sc_intptr_t)evid) < ((sc_intptr_t)&(handle->timeEvents)) + sizeof(PrefixTimeEvents))
		{
		*(sc_boolean*)evid = bool_true;
	}		
}

sc_boolean prefix_isStateActive(const Prefix* handle, PrefixStates state)
{
	sc_boolean result = bool_false;
	switch (state)
	{
		case Prefix_BOTON_DEL_ENCODER_DEBOUNCE :
			result = (sc_boolean) (handle->stateConfVector[0] == Prefix_BOTON_DEL_ENCODER_DEBOUNCE
			);
			break;
		case Prefix_BOTON_DEL_ENCODER_NO_OPRIMIDO :
			result = (sc_boolean) (handle->stateConfVector[0] == Prefix_BOTON_DEL_ENCODER_NO_OPRIMIDO
			);
			break;
		case Prefix_BOTON_DEL_ENCODER_OPRIMIDO :
			result = (sc_boolean) (handle->stateConfVector[0] == Prefix_BOTON_DEL_ENCODER_OPRIMIDO
			);
			break;
		case Prefix_BOTON_DEL_ENCODER_VALIDACION :
			result = (sc_boolean) (handle->stateConfVector[0] == Prefix_BOTON_DEL_ENCODER_VALIDACION
			);
			break;
		case Prefix_ENCODER_REPOSO :
			result = (sc_boolean) (handle->stateConfVector[1] == Prefix_ENCODER_REPOSO
			);
			break;
		case Prefix_ENCODER_ROTACION_DERECHA :
			result = (sc_boolean) (handle->stateConfVector[1] == Prefix_ENCODER_ROTACION_DERECHA
			);
			break;
		case Prefix_ENCODER_ROTACION_IZQUIERDA :
			result = (sc_boolean) (handle->stateConfVector[1] == Prefix_ENCODER_ROTACION_IZQUIERDA
			);
			break;
		case Prefix_LCD_MENU_PRINCIPAL :
			result = (sc_boolean) (handle->stateConfVector[2] >= Prefix_LCD_MENU_PRINCIPAL
				&& handle->stateConfVector[2] <= Prefix_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION);
			break;
		case Prefix_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_MOTORES :
			result = (sc_boolean) (handle->stateConfVector[2] == Prefix_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_MOTORES
			);
			break;
		case Prefix_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP :
			result = (sc_boolean) (handle->stateConfVector[2] == Prefix_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP
			);
			break;
		case Prefix_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_WI_FI :
			result = (sc_boolean) (handle->stateConfVector[2] == Prefix_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_WI_FI
			);
			break;
		case Prefix_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION :
			result = (sc_boolean) (handle->stateConfVector[2] == Prefix_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION
			);
			break;
		case Prefix_LCD_MENU_CONF_TEMP :
			result = (sc_boolean) (handle->stateConfVector[2] >= Prefix_LCD_MENU_CONF_TEMP
				&& handle->stateConfVector[2] <= Prefix_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR);
			break;
		case Prefix_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_CANCELAR :
			result = (sc_boolean) (handle->stateConfVector[2] == Prefix_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_CANCELAR
			);
			break;
		case Prefix_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_SETEAR_TEMP :
			result = (sc_boolean) (handle->stateConfVector[2] == Prefix_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_SETEAR_TEMP
			);
			break;
		case Prefix_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR :
			result = (sc_boolean) (handle->stateConfVector[2] == Prefix_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR
			);
			break;
		case Prefix_LCD_MENU_CONF_MOTORES :
			result = (sc_boolean) (handle->stateConfVector[2] >= Prefix_LCD_MENU_CONF_MOTORES
				&& handle->stateConfVector[2] <= Prefix_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT);
			break;
		case Prefix_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_CANCELAR :
			result = (sc_boolean) (handle->stateConfVector[2] == Prefix_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_CANCELAR
			);
			break;
		case Prefix_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION :
			result = (sc_boolean) (handle->stateConfVector[2] == Prefix_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION
			);
			break;
		case Prefix_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION :
			result = (sc_boolean) (handle->stateConfVector[2] == Prefix_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION
			);
			break;
		case Prefix_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT :
			result = (sc_boolean) (handle->stateConfVector[2] == Prefix_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT
			);
			break;
		case Prefix_LCD_MENU_SET_TEMP :
			result = (sc_boolean) (handle->stateConfVector[2] >= Prefix_LCD_MENU_SET_TEMP
				&& handle->stateConfVector[2] <= Prefix_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP);
			break;
		case Prefix_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP :
			result = (sc_boolean) (handle->stateConfVector[2] == Prefix_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP
			);
			break;
		case Prefix_LCD_MENU_WIFI :
			result = (sc_boolean) (handle->stateConfVector[2] == Prefix_LCD_MENU_WIFI
			);
			break;
		case Prefix_PUENTE_H_STOP :
			result = (sc_boolean) (handle->stateConfVector[3] == Prefix_PUENTE_H_STOP
			);
			break;
		case Prefix_PUENTE_H_H_ROTACION_HORARIO :
			result = (sc_boolean) (handle->stateConfVector[3] == Prefix_PUENTE_H_H_ROTACION_HORARIO
			);
			break;
		case Prefix_PUENTE_H_CONFIGURAR :
			result = (sc_boolean) (handle->stateConfVector[3] == Prefix_PUENTE_H_CONFIGURAR
			);
			break;
		case Prefix_PUENTE_H_H_RETRACT :
			result = (sc_boolean) (handle->stateConfVector[3] == Prefix_PUENTE_H_H_RETRACT
			);
			break;
		case Prefix_x_TEMP_APAGADO :
			result = (sc_boolean) (handle->stateConfVector[4] == Prefix_x_TEMP_APAGADO
			);
			break;
		case Prefix_x_TEMP_CALENTAR :
			result = (sc_boolean) (handle->stateConfVector[4] >= Prefix_x_TEMP_CALENTAR
				&& handle->stateConfVector[4] <= Prefix_x_TEMP_CALENTAR_ENVIAR_DATOS_TEMP_ENVIAR_UART);
			break;
		case Prefix_x_TEMP_CALENTAR_EJECUTAR_CONTROL_TEMP_CONTROL :
			result = (sc_boolean) (handle->stateConfVector[4] == Prefix_x_TEMP_CALENTAR_EJECUTAR_CONTROL_TEMP_CONTROL
			);
			break;
		case Prefix_x_TEMP_CALENTAR_ENVIAR_DATOS_TEMP_ENVIAR_UART :
			result = (sc_boolean) (handle->stateConfVector[5] == Prefix_x_TEMP_CALENTAR_ENVIAR_DATOS_TEMP_ENVIAR_UART
			);
			break;
		case Prefix_x_TEMP_CONF :
			result = (sc_boolean) (handle->stateConfVector[4] == Prefix_x_TEMP_CONF
			);
			break;
		case Prefix_UART_UART_SEND_STATUS :
			result = (sc_boolean) (handle->stateConfVector[6] == Prefix_UART_UART_SEND_STATUS
			);
			break;
		default:
			result = bool_false;
			break;
	}
	return result;
}

void prefixIface_raise_evActualizar_setpoint(Prefix* handle)
{
	handle->iface.evActualizar_setpoint_raised = bool_true;
}
void prefixIface_raise_evEnc_rot_derecha(Prefix* handle)
{
	handle->iface.evEnc_rot_derecha_raised = bool_true;
}
void prefixIface_raise_evEnc_rot_izquierda(Prefix* handle)
{
	handle->iface.evEnc_rot_izquierda_raised = bool_true;
}
void prefixIface_raise_evEnc_boton(Prefix* handle)
{
	handle->iface.evEnc_boton_raised = bool_true;
}
void prefixIface_raise_evTECXNoOprimido(Prefix* handle)
{
	handle->iface.evTECXNoOprimido_raised = bool_true;
}
void prefixIface_raise_evTECXOprimido(Prefix* handle)
{
	handle->iface.evTECXOprimido_raised = bool_true;
}
void prefixIface_raise_evPuente_h_alto(Prefix* handle)
{
	handle->iface.evPuente_h_alto_raised = bool_true;
}
void prefixIface_raise_evPuente_h_horario(Prefix* handle)
{
	handle->iface.evPuente_h_horario_raised = bool_true;
}
void prefixIface_raise_evPuente_h_antihorario(Prefix* handle)
{
	handle->iface.evPuente_h_antihorario_raised = bool_true;
}
void prefixIface_raise_evConf_Ready_Puente_H(Prefix* handle)
{
	handle->iface.evConf_Ready_Puente_H_raised = bool_true;
}
void prefixIface_raise_evConf_Ready_temp(Prefix* handle)
{
	handle->iface.evConf_Ready_temp_raised = bool_true;
}
void prefixIface_raise_evTemp_start(Prefix* handle)
{
	handle->iface.evTemp_start_raised = bool_true;
}
void prefixIface_raise_evTemp_stop(Prefix* handle)
{
	handle->iface.evTemp_stop_raised = bool_true;
}
void prefixIface_raise_evStop_puente_h(Prefix* handle)
{
	handle->iface.evStop_puente_h_raised = bool_true;
}
void prefixIface_raise_evStart_puente_h(Prefix* handle)
{
	handle->iface.evStart_puente_h_raised = bool_true;
}
void prefixIface_raise_evRetract_puente_h(Prefix* handle)
{
	handle->iface.evRetract_puente_h_raised = bool_true;
}


const sc_integer prefixIface_get_mAX_DER_COUNT(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_MAX_DER_COUNT;
}
const sc_integer prefixIface_get_mAX_IZQ_COUNT(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_MAX_IZQ_COUNT;
}
const sc_integer prefixIface_get_tRUE(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_TRUE_ID;
}
const sc_integer prefixIface_get_fALSE(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_FALSE_ID;
}
const sc_boolean prefixIface_get_horario(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_HORARIO;
}
const sc_boolean prefixIface_get_antihorario(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_ANTIHORARIO;
}
const sc_string prefixIface_get_msj_menu_principal(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_MSJ_MENU_PRINCIPAL;
}
const sc_string prefixIface_get_msj_menu_conf_motores(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_MSJ_MENU_CONF_MOTORES;
}
const sc_string prefixIface_get_msj_menu_conf_Wi_Fi(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_MSJ_MENU_CONF_WI_FI;
}
const sc_string prefixIface_get_msj_menu_extruir(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_MSJ_MENU_EXTRUIR;
}
const sc_string prefixIface_get_msj_menu_conf_temp(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_MSJ_MENU_CONF_TEMP;
}
const sc_string prefixIface_get_msj_menu_cancelar(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_MSJ_MENU_CANCELAR;
}
const sc_string prefixIface_get_msj_menu_motor_extrusion(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_MSJ_MENU_MOTOR_EXTRUSION;
}
const sc_string prefixIface_get_msj_menu_motor_extrusion_stop(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_MSJ_MENU_MOTOR_EXTRUSION_STOP;
}
const sc_string prefixIface_get_msj_menu_motor_extrusion_retract(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_MSJ_MENU_MOTOR_EXTRUSION_RETRACT;
}
const sc_string prefixIface_get_msj_menu_setear_temp(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_MSJ_MENU_SETEAR_TEMP;
}
const sc_string prefixIface_get_msj_menu_enfriar(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_MSJ_MENU_ENFRIAR;
}
const sc_string prefixIface_get_msj_menu_set_temp(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_MSJ_MENU_SET_TEMP;
}
const sc_string prefixIface_get_msj_menu_wifi(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_MSJ_MENU_WIFI;
}

/* implementations of all internal functions */

static sc_boolean prefix_check_BOTON_DEL_ENCODER_DEBOUNCE_tr0_tr0(const Prefix* handle)
{
	return handle->timeEvents.prefix_BOTON_DEL_ENCODER_DEBOUNCE_tev0_raised;
}

static sc_boolean prefix_check_BOTON_DEL_ENCODER_NO_OPRIMIDO_tr0_tr0(const Prefix* handle)
{
	return handle->iface.evTECXOprimido_raised;
}

static sc_boolean prefix_check_BOTON_DEL_ENCODER_OPRIMIDO_tr0_tr0(const Prefix* handle)
{
	return handle->iface.evTECXNoOprimido_raised;
}

static sc_boolean prefix_check_BOTON_DEL_ENCODER_VALIDACION_tr0_tr0(const Prefix* handle)
{
	return handle->iface.evTECXOprimido_raised;
}

static sc_boolean prefix_check_BOTON_DEL_ENCODER_VALIDACION_tr1_tr1(const Prefix* handle)
{
	return handle->iface.evTECXNoOprimido_raised;
}

static sc_boolean prefix_check_ENCODER_REPOSO_tr0_tr0(const Prefix* handle)
{
	return ((handle->iface.evEnc_rot_derecha_raised) && (handle->internal.viEnc_count_der >= PREFIX_PREFIXIFACE_MAX_DER_COUNT)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_ENCODER_REPOSO_tr1_tr1(const Prefix* handle)
{
	return ((handle->iface.evEnc_rot_izquierda_raised) && (handle->internal.viEnc_count_izq >= PREFIX_PREFIXIFACE_MAX_IZQ_COUNT)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_ENCODER_REPOSO_tr2_tr2(const Prefix* handle)
{
	return ((handle->iface.evEnc_rot_derecha_raised) && (handle->internal.viEnc_count_der < PREFIX_PREFIXIFACE_MAX_DER_COUNT)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_ENCODER_REPOSO_tr3_tr3(const Prefix* handle)
{
	return ((handle->iface.evEnc_rot_izquierda_raised) && (handle->internal.viEnc_count_izq < PREFIX_PREFIXIFACE_MAX_IZQ_COUNT)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_ENCODER_ROTACION_DERECHA_tr0_tr0(const Prefix* handle)
{
	return (handle->internal.viEnc_volver == PREFIX_PREFIXIFACE_TRUE_ID) ? bool_true : bool_false;
}

static sc_boolean prefix_check_ENCODER_ROTACION_IZQUIERDA_tr0_tr0(const Prefix* handle)
{
	return (handle->internal.viEnc_volver == PREFIX_PREFIXIFACE_TRUE_ID) ? bool_true : bool_false;
}

static sc_boolean prefix_check_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_MOTORES_tr0_tr0(const Prefix* handle)
{
	return handle->internal.siDespl_derecha_raised;
}

static sc_boolean prefix_check_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_MOTORES_tr1_tr1(const Prefix* handle)
{
	return handle->internal.siDespl_izquierda_raised;
}

static sc_boolean prefix_check_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_MOTORES_tr2_tr2(const Prefix* handle)
{
	return handle->internal.siEntrar_raised;
}

static sc_boolean prefix_check_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP_tr0_tr0(const Prefix* handle)
{
	return handle->internal.siDespl_derecha_raised;
}

static sc_boolean prefix_check_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP_tr1_tr1(const Prefix* handle)
{
	return handle->internal.siDespl_izquierda_raised;
}

static sc_boolean prefix_check_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP_tr2_tr2(const Prefix* handle)
{
	return handle->internal.siEntrar_raised;
}

static sc_boolean prefix_check_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_WI_FI_tr0_tr0(const Prefix* handle)
{
	return handle->internal.siDespl_derecha_raised;
}

static sc_boolean prefix_check_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_WI_FI_tr1_tr1(const Prefix* handle)
{
	return handle->internal.siDespl_izquierda_raised;
}

static sc_boolean prefix_check_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_WI_FI_tr2_tr2(const Prefix* handle)
{
	return handle->internal.siEntrar_raised;
}

static sc_boolean prefix_check_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION_tr0_tr0(const Prefix* handle)
{
	return handle->internal.siDespl_derecha_raised;
}

static sc_boolean prefix_check_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION_tr1_tr1(const Prefix* handle)
{
	return handle->internal.siDespl_izquierda_raised;
}

static sc_boolean prefix_check_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION_tr2_tr2(const Prefix* handle)
{
	return handle->internal.siEntrar_raised;
}

static sc_boolean prefix_check_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_CANCELAR_tr0_tr0(const Prefix* handle)
{
	return handle->internal.siEntrar_raised;
}

static sc_boolean prefix_check_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_CANCELAR_tr1_tr1(const Prefix* handle)
{
	return handle->internal.siDespl_derecha_raised;
}

static sc_boolean prefix_check_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_CANCELAR_tr2_tr2(const Prefix* handle)
{
	return handle->internal.siDespl_izquierda_raised;
}

static sc_boolean prefix_check_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_SETEAR_TEMP_tr0_tr0(const Prefix* handle)
{
	return handle->internal.siDespl_izquierda_raised;
}

static sc_boolean prefix_check_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_SETEAR_TEMP_tr1_tr1(const Prefix* handle)
{
	return handle->internal.siDespl_derecha_raised;
}

static sc_boolean prefix_check_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_SETEAR_TEMP_tr2_tr2(const Prefix* handle)
{
	return handle->internal.siEntrar_raised;
}

static sc_boolean prefix_check_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR_tr0_tr0(const Prefix* handle)
{
	return handle->internal.siDespl_izquierda_raised;
}

static sc_boolean prefix_check_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR_tr1_tr1(const Prefix* handle)
{
	return handle->internal.siDespl_derecha_raised;
}

static sc_boolean prefix_check_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR_tr2_tr2(const Prefix* handle)
{
	return handle->internal.siEntrar_raised;
}

static sc_boolean prefix_check_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_CANCELAR_tr0_tr0(const Prefix* handle)
{
	return handle->internal.siEntrar_raised;
}

static sc_boolean prefix_check_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_CANCELAR_tr1_tr1(const Prefix* handle)
{
	return handle->internal.siDespl_derecha_raised;
}

static sc_boolean prefix_check_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_CANCELAR_tr2_tr2(const Prefix* handle)
{
	return handle->internal.siDespl_izquierda_raised;
}

static sc_boolean prefix_check_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION_tr0_tr0(const Prefix* handle)
{
	return handle->internal.siDespl_izquierda_raised;
}

static sc_boolean prefix_check_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION_tr1_tr1(const Prefix* handle)
{
	return handle->internal.siDespl_derecha_raised;
}

static sc_boolean prefix_check_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION_tr2_tr2(const Prefix* handle)
{
	return handle->internal.siEntrar_raised;
}

static sc_boolean prefix_check_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION_tr0_tr0(const Prefix* handle)
{
	return handle->internal.siDespl_izquierda_raised;
}

static sc_boolean prefix_check_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION_tr1_tr1(const Prefix* handle)
{
	return handle->internal.siEntrar_raised;
}

static sc_boolean prefix_check_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION_tr2_tr2(const Prefix* handle)
{
	return handle->internal.siDespl_derecha_raised;
}

static sc_boolean prefix_check_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT_tr0_tr0(const Prefix* handle)
{
	return handle->internal.siDespl_izquierda_raised;
}

static sc_boolean prefix_check_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT_tr1_tr1(const Prefix* handle)
{
	return handle->internal.siDespl_derecha_raised;
}

static sc_boolean prefix_check_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT_tr2_tr2(const Prefix* handle)
{
	return handle->internal.siEntrar_raised;
}

static sc_boolean prefix_check_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP_tr0_tr0(const Prefix* handle)
{
	return handle->internal.siDespl_derecha_raised;
}

static sc_boolean prefix_check_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP_tr1_tr1(const Prefix* handle)
{
	return ((handle->internal.siDespl_izquierda_raised) && (handle->internal.viSet_temp_lcd > 150)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP_tr2_tr2(const Prefix* handle)
{
	return handle->internal.siEntrar_raised;
}

static sc_boolean prefix_check_LCD_MENU_WIFI_tr0_tr0(const Prefix* handle)
{
	return handle->internal.siEntrar_raised;
}

static sc_boolean prefix_check_PUENTE_H_STOP_tr0_tr0(const Prefix* handle)
{
	return handle->iface.evStart_puente_h_raised;
}

static sc_boolean prefix_check_PUENTE_H_STOP_tr1_tr1(const Prefix* handle)
{
	return handle->iface.evRetract_puente_h_raised;
}

static sc_boolean prefix_check_PUENTE_H_H_ROTACION_HORARIO_tr0_tr0(const Prefix* handle)
{
	return handle->iface.evStop_puente_h_raised;
}

static sc_boolean prefix_check_PUENTE_H_H_ROTACION_HORARIO_tr1_tr1(const Prefix* handle)
{
	return handle->iface.evRetract_puente_h_raised;
}

static sc_boolean prefix_check_PUENTE_H_CONFIGURAR_tr0_tr0(const Prefix* handle)
{
	return handle->iface.evConf_Ready_Puente_H_raised;
}

static sc_boolean prefix_check_PUENTE_H_H_RETRACT_tr0_tr0(const Prefix* handle)
{
	return handle->iface.evStart_puente_h_raised;
}

static sc_boolean prefix_check_PUENTE_H_H_RETRACT_tr1_tr1(const Prefix* handle)
{
	return handle->iface.evStop_puente_h_raised;
}

static sc_boolean prefix_check_x_TEMP_APAGADO_tr0_tr0(const Prefix* handle)
{
	return handle->iface.evTemp_start_raised;
}

static sc_boolean prefix_check_x_TEMP_CALENTAR_tr0_tr0(const Prefix* handle)
{
	return handle->iface.evTemp_stop_raised;
}

static sc_boolean prefix_check_x_TEMP_CALENTAR_EJECUTAR_CONTROL_TEMP_CONTROL_tr0_tr0(const Prefix* handle)
{
	return handle->timeEvents.prefix_x_TEMP_CALENTAR_EJECUTAR_CONTROL_TEMP_CONTROL_tev0_raised;
}

static sc_boolean prefix_check_x_TEMP_CALENTAR_ENVIAR_DATOS_TEMP_ENVIAR_UART_tr0_tr0(const Prefix* handle)
{
	return handle->timeEvents.prefix_x_TEMP_CALENTAR_ENVIAR_DATOS_TEMP_ENVIAR_UART_tev0_raised;
}

static sc_boolean prefix_check_x_TEMP_CONF_tr0_tr0(const Prefix* handle)
{
	return handle->iface.evConf_Ready_temp_raised;
}

static sc_boolean prefix_check_UART_UART_SEND_STATUS_tr0_tr0(const Prefix* handle)
{
	return handle->timeEvents.prefix_UART_UART_SEND_STATUS_tev0_raised;
}

static void prefix_effect_BOTON_DEL_ENCODER_DEBOUNCE_tr0(Prefix* handle)
{
	prefix_exseq_BOTON_DEL_ENCODER_DEBOUNCE(handle);
	prefix_enseq_BOTON_DEL_ENCODER_VALIDACION_default(handle);
}

static void prefix_effect_BOTON_DEL_ENCODER_NO_OPRIMIDO_tr0(Prefix* handle)
{
	prefix_exseq_BOTON_DEL_ENCODER_NO_OPRIMIDO(handle);
	prefix_enseq_BOTON_DEL_ENCODER_DEBOUNCE_default(handle);
}

static void prefix_effect_BOTON_DEL_ENCODER_OPRIMIDO_tr0(Prefix* handle)
{
	prefix_exseq_BOTON_DEL_ENCODER_OPRIMIDO(handle);
	prefix_enseq_BOTON_DEL_ENCODER_NO_OPRIMIDO_default(handle);
}

static void prefix_effect_BOTON_DEL_ENCODER_VALIDACION_tr0(Prefix* handle)
{
	prefix_exseq_BOTON_DEL_ENCODER_VALIDACION(handle);
	prefix_enseq_BOTON_DEL_ENCODER_OPRIMIDO_default(handle);
}

static void prefix_effect_BOTON_DEL_ENCODER_VALIDACION_tr1(Prefix* handle)
{
	prefix_exseq_BOTON_DEL_ENCODER_VALIDACION(handle);
	prefix_enseq_BOTON_DEL_ENCODER_NO_OPRIMIDO_default(handle);
}

static void prefix_effect_ENCODER_REPOSO_tr0(Prefix* handle)
{
	prefix_exseq_ENCODER_REPOSO(handle);
	prefix_enseq_ENCODER_ROTACION_DERECHA_default(handle);
}

static void prefix_effect_ENCODER_REPOSO_tr1(Prefix* handle)
{
	prefix_exseq_ENCODER_REPOSO(handle);
	prefix_enseq_ENCODER_ROTACION_IZQUIERDA_default(handle);
}

static void prefix_effect_ENCODER_REPOSO_tr2(Prefix* handle)
{
	prefix_exseq_ENCODER_REPOSO(handle);
	handle->internal.viEnc_count_der += 1;
	handle->internal.viEnc_count_izq = 0;
	prefix_enseq_ENCODER_REPOSO_default(handle);
}

static void prefix_effect_ENCODER_REPOSO_tr3(Prefix* handle)
{
	prefix_exseq_ENCODER_REPOSO(handle);
	handle->internal.viEnc_count_izq += 1;
	handle->internal.viEnc_count_der = 0;
	prefix_enseq_ENCODER_REPOSO_default(handle);
}

static void prefix_effect_ENCODER_ROTACION_DERECHA_tr0(Prefix* handle)
{
	prefix_exseq_ENCODER_ROTACION_DERECHA(handle);
	prefix_enseq_ENCODER_REPOSO_default(handle);
}

static void prefix_effect_ENCODER_ROTACION_IZQUIERDA_tr0(Prefix* handle)
{
	prefix_exseq_ENCODER_ROTACION_IZQUIERDA(handle);
	prefix_enseq_ENCODER_REPOSO_default(handle);
}

static void prefix_effect_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_MOTORES_tr0(Prefix* handle)
{
	prefix_exseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_MOTORES(handle);
	prefix_enseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP_default(handle);
}

static void prefix_effect_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_MOTORES_tr1(Prefix* handle)
{
	prefix_exseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_MOTORES(handle);
	prefix_enseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_WI_FI_default(handle);
}

static void prefix_effect_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_MOTORES_tr2(Prefix* handle)
{
	prefix_exseq_LCD_MENU_PRINCIPAL(handle);
	prefix_enseq_LCD_MENU_CONF_MOTORES_default(handle);
}

static void prefix_effect_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP_tr0(Prefix* handle)
{
	prefix_exseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP(handle);
	prefix_enseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION_default(handle);
}

static void prefix_effect_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP_tr1(Prefix* handle)
{
	prefix_exseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP(handle);
	prefix_enseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_MOTORES_default(handle);
}

static void prefix_effect_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP_tr2(Prefix* handle)
{
	prefix_exseq_LCD_MENU_PRINCIPAL(handle);
	prefix_enseq_LCD_MENU_CONF_TEMP_default(handle);
}

static void prefix_effect_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_WI_FI_tr0(Prefix* handle)
{
	prefix_exseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_WI_FI(handle);
	prefix_enseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_MOTORES_default(handle);
}

static void prefix_effect_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_WI_FI_tr1(Prefix* handle)
{
	prefix_exseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_WI_FI(handle);
	prefix_enseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION_default(handle);
}

static void prefix_effect_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_WI_FI_tr2(Prefix* handle)
{
	prefix_exseq_LCD_MENU_PRINCIPAL(handle);
	prefix_enseq_LCD_MENU_WIFI_default(handle);
}

static void prefix_effect_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION_tr0(Prefix* handle)
{
	prefix_exseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION(handle);
	prefix_enseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_WI_FI_default(handle);
}

static void prefix_effect_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION_tr1(Prefix* handle)
{
	prefix_exseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION(handle);
	prefix_enseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP_default(handle);
}

static void prefix_effect_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION_tr2(Prefix* handle)
{
	prefix_exseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION(handle);
	handle->iface.evTemp_start_raised = bool_true;
	prefix_enseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION_default(handle);
}

static void prefix_effect_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_CANCELAR_tr0(Prefix* handle)
{
	prefix_exseq_LCD_MENU_CONF_TEMP(handle);
	prefix_enseq_LCD_MENU_PRINCIPAL_default(handle);
}

static void prefix_effect_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_CANCELAR_tr1(Prefix* handle)
{
	prefix_exseq_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_CANCELAR(handle);
	prefix_enseq_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_SETEAR_TEMP_default(handle);
}

static void prefix_effect_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_CANCELAR_tr2(Prefix* handle)
{
	prefix_exseq_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_CANCELAR(handle);
	prefix_enseq_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR_default(handle);
}

static void prefix_effect_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_SETEAR_TEMP_tr0(Prefix* handle)
{
	prefix_exseq_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_SETEAR_TEMP(handle);
	prefix_enseq_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_CANCELAR_default(handle);
}

static void prefix_effect_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_SETEAR_TEMP_tr1(Prefix* handle)
{
	prefix_exseq_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_SETEAR_TEMP(handle);
	prefix_enseq_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR_default(handle);
}

static void prefix_effect_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_SETEAR_TEMP_tr2(Prefix* handle)
{
	prefix_exseq_LCD_MENU_CONF_TEMP(handle);
	handle->internal.viSet_temp_lcd = 150;
	prefix_enseq_LCD_MENU_SET_TEMP_default(handle);
}

static void prefix_effect_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR_tr0(Prefix* handle)
{
	prefix_exseq_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR(handle);
	prefix_enseq_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_SETEAR_TEMP_default(handle);
}

static void prefix_effect_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR_tr1(Prefix* handle)
{
	prefix_exseq_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR(handle);
	prefix_enseq_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_CANCELAR_default(handle);
}

static void prefix_effect_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR_tr2(Prefix* handle)
{
	prefix_exseq_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR(handle);
	handle->iface.evTemp_stop_raised = bool_true;
	prefix_enseq_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR_default(handle);
}

static void prefix_effect_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_CANCELAR_tr0(Prefix* handle)
{
	prefix_exseq_LCD_MENU_CONF_MOTORES(handle);
	prefix_enseq_LCD_MENU_PRINCIPAL_default(handle);
}

static void prefix_effect_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_CANCELAR_tr1(Prefix* handle)
{
	prefix_exseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_CANCELAR(handle);
	prefix_enseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION_default(handle);
}

static void prefix_effect_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_CANCELAR_tr2(Prefix* handle)
{
	prefix_exseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_CANCELAR(handle);
	prefix_enseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT_default(handle);
}

static void prefix_effect_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION_tr0(Prefix* handle)
{
	prefix_exseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION(handle);
	prefix_enseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_CANCELAR_default(handle);
}

static void prefix_effect_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION_tr1(Prefix* handle)
{
	prefix_exseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION(handle);
	prefix_enseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION_default(handle);
}

static void prefix_effect_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION_tr2(Prefix* handle)
{
	prefix_exseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION(handle);
	handle->iface.evStart_puente_h_raised = bool_true;
	prefix_enseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION_default(handle);
}

static void prefix_effect_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION_tr0(Prefix* handle)
{
	prefix_exseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION(handle);
	prefix_enseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION_default(handle);
}

static void prefix_effect_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION_tr1(Prefix* handle)
{
	prefix_exseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION(handle);
	handle->iface.evStop_puente_h_raised = bool_true;
	prefix_enseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION_default(handle);
}

static void prefix_effect_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION_tr2(Prefix* handle)
{
	prefix_exseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION(handle);
	prefix_enseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT_default(handle);
}

static void prefix_effect_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT_tr0(Prefix* handle)
{
	prefix_exseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT(handle);
	prefix_enseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION_default(handle);
}

static void prefix_effect_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT_tr1(Prefix* handle)
{
	prefix_exseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT(handle);
	prefix_enseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_CANCELAR_default(handle);
}

static void prefix_effect_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT_tr2(Prefix* handle)
{
	prefix_exseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT(handle);
	handle->iface.evRetract_puente_h_raised = bool_true;
	prefix_enseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT_default(handle);
}

static void prefix_effect_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP_tr0(Prefix* handle)
{
	prefix_exseq_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP(handle);
	handle->internal.viSet_temp_lcd += 1;
	prefix_enseq_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP_default(handle);
}

static void prefix_effect_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP_tr1(Prefix* handle)
{
	prefix_exseq_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP(handle);
	handle->internal.viSet_temp_lcd -= 1;
	prefix_enseq_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP_default(handle);
}

static void prefix_effect_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP_tr2(Prefix* handle)
{
	prefix_exseq_LCD_MENU_SET_TEMP(handle);
	handle->iface.evActualizar_setpoint_raised = bool_true;
	handle->internal.viSetPoint = handle->internal.viSet_temp_lcd;
	prefix_enseq_LCD_MENU_CONF_TEMP_default(handle);
}

static void prefix_effect_LCD_MENU_WIFI_tr0(Prefix* handle)
{
	prefix_exseq_LCD_MENU_WIFI(handle);
	prefix_enseq_LCD_MENU_PRINCIPAL_default(handle);
}

static void prefix_effect_PUENTE_H_STOP_tr0(Prefix* handle)
{
	prefix_exseq_PUENTE_H_STOP(handle);
	prefix_enseq_PUENTE_H_H_ROTACION_HORARIO_default(handle);
}

static void prefix_effect_PUENTE_H_STOP_tr1(Prefix* handle)
{
	prefix_exseq_PUENTE_H_STOP(handle);
	prefix_enseq_PUENTE_H_H_RETRACT_default(handle);
}

static void prefix_effect_PUENTE_H_H_ROTACION_HORARIO_tr0(Prefix* handle)
{
	prefix_exseq_PUENTE_H_H_ROTACION_HORARIO(handle);
	prefix_enseq_PUENTE_H_STOP_default(handle);
}

static void prefix_effect_PUENTE_H_H_ROTACION_HORARIO_tr1(Prefix* handle)
{
	prefix_exseq_PUENTE_H_H_ROTACION_HORARIO(handle);
	prefixIface_opStop_puente_h(handle);
	prefix_enseq_PUENTE_H_H_RETRACT_default(handle);
}

static void prefix_effect_PUENTE_H_CONFIGURAR_tr0(Prefix* handle)
{
	prefix_exseq_PUENTE_H_CONFIGURAR(handle);
	prefix_enseq_PUENTE_H_STOP_default(handle);
}

static void prefix_effect_PUENTE_H_H_RETRACT_tr0(Prefix* handle)
{
	prefix_exseq_PUENTE_H_H_RETRACT(handle);
	prefixIface_opStop_puente_h(handle);
	prefix_enseq_PUENTE_H_H_ROTACION_HORARIO_default(handle);
}

static void prefix_effect_PUENTE_H_H_RETRACT_tr1(Prefix* handle)
{
	prefix_exseq_PUENTE_H_H_RETRACT(handle);
	prefix_enseq_PUENTE_H_STOP_default(handle);
}

static void prefix_effect_x_TEMP_APAGADO_tr0(Prefix* handle)
{
	prefix_exseq_x_TEMP_APAGADO(handle);
	handle->internal.viStatus = 1;
	prefix_enseq_x_TEMP_CALENTAR_default(handle);
}

static void prefix_effect_x_TEMP_CALENTAR_tr0(Prefix* handle)
{
	prefix_exseq_x_TEMP_CALENTAR(handle);
	handle->internal.viStatus = 0;
	prefix_enseq_x_TEMP_APAGADO_default(handle);
}

static void prefix_effect_x_TEMP_CALENTAR_EJECUTAR_CONTROL_TEMP_CONTROL_tr0(Prefix* handle)
{
	prefix_exseq_x_TEMP_CALENTAR_EJECUTAR_CONTROL_TEMP_CONTROL(handle);
	prefix_enseq_x_TEMP_CALENTAR_EJECUTAR_CONTROL_TEMP_CONTROL_default(handle);
}

static void prefix_effect_x_TEMP_CALENTAR_ENVIAR_DATOS_TEMP_ENVIAR_UART_tr0(Prefix* handle)
{
	prefix_exseq_x_TEMP_CALENTAR_ENVIAR_DATOS_TEMP_ENVIAR_UART(handle);
	prefix_enseq_x_TEMP_CALENTAR_ENVIAR_DATOS_TEMP_ENVIAR_UART_default(handle);
}

static void prefix_effect_x_TEMP_CONF_tr0(Prefix* handle)
{
	prefix_exseq_x_TEMP_CONF(handle);
	prefix_enseq_x_TEMP_APAGADO_default(handle);
}

static void prefix_effect_UART_UART_SEND_STATUS_tr0(Prefix* handle)
{
	prefix_exseq_UART_UART_SEND_STATUS(handle);
	prefix_enseq_UART_UART_SEND_STATUS_default(handle);
}

/* Entry action for state 'DEBOUNCE'. */
static void prefix_enact_BOTON_DEL_ENCODER_DEBOUNCE(Prefix* handle)
{
	/* Entry action for state 'DEBOUNCE'. */
	prefix_setTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_BOTON_DEL_ENCODER_DEBOUNCE_tev0_raised) , 50, bool_false);
}

/* Entry action for state 'OPRIMIDO'. */
static void prefix_enact_BOTON_DEL_ENCODER_OPRIMIDO(Prefix* handle)
{
	/* Entry action for state 'OPRIMIDO'. */
	handle->internal.siEntrar_raised = bool_true;
}

/* Entry action for state 'REPOSO'. */
static void prefix_enact_ENCODER_REPOSO(Prefix* handle)
{
	/* Entry action for state 'REPOSO'. */
	handle->internal.viEnc_volver = PREFIX_PREFIXIFACE_FALSE_ID;
}

/* Entry action for state 'ROTACION_DERECHA'. */
static void prefix_enact_ENCODER_ROTACION_DERECHA(Prefix* handle)
{
	/* Entry action for state 'ROTACION_DERECHA'. */
	handle->internal.siDespl_derecha_raised = bool_true;
	handle->internal.viEnc_count_der = 0;
	handle->internal.viEnc_count_izq = 0;
	handle->internal.viEnc_volver = PREFIX_PREFIXIFACE_TRUE_ID;
}

/* Entry action for state 'ROTACION_IZQUIERDA'. */
static void prefix_enact_ENCODER_ROTACION_IZQUIERDA(Prefix* handle)
{
	/* Entry action for state 'ROTACION_IZQUIERDA'. */
	handle->internal.siDespl_izquierda_raised = bool_true;
	handle->internal.viEnc_count_der = 0;
	handle->internal.viEnc_count_izq = 0;
	handle->internal.viEnc_volver = PREFIX_PREFIXIFACE_TRUE_ID;
}

/* Entry action for state 'MENU_PRINCIPAL'. */
static void prefix_enact_LCD_MENU_PRINCIPAL(Prefix* handle)
{
	/* Entry action for state 'MENU_PRINCIPAL'. */
	prefixIface_opMostrar_msj(handle, PREFIX_PREFIXIFACE_MSJ_MENU_PRINCIPAL, 1, 1);
}

/* Entry action for state 'CONF_MOTORES'. */
static void prefix_enact_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_MOTORES(Prefix* handle)
{
	/* Entry action for state 'CONF_MOTORES'. */
	prefixIface_opMostrar_msj(handle, PREFIX_PREFIXIFACE_MSJ_MENU_CONF_MOTORES, 1, 2);
}

/* Entry action for state 'CONF_TEMP'. */
static void prefix_enact_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP(Prefix* handle)
{
	/* Entry action for state 'CONF_TEMP'. */
	prefixIface_opMostrar_msj(handle, PREFIX_PREFIXIFACE_MSJ_MENU_CONF_TEMP, 1, 2);
}

/* Entry action for state 'CONF_WI_FI'. */
static void prefix_enact_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_WI_FI(Prefix* handle)
{
	/* Entry action for state 'CONF_WI_FI'. */
	prefixIface_opMostrar_msj(handle, PREFIX_PREFIXIFACE_MSJ_MENU_CONF_WI_FI, 1, 2);
}

/* Entry action for state 'EXTRUSION'. */
static void prefix_enact_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION(Prefix* handle)
{
	/* Entry action for state 'EXTRUSION'. */
	prefixIface_opMostrar_msj(handle, PREFIX_PREFIXIFACE_MSJ_MENU_EXTRUIR, 1, 2);
}

/* Entry action for state 'MENU_CONF_TEMP'. */
static void prefix_enact_LCD_MENU_CONF_TEMP(Prefix* handle)
{
	/* Entry action for state 'MENU_CONF_TEMP'. */
	prefixIface_opMostrar_msj(handle, PREFIX_PREFIXIFACE_MSJ_MENU_CONF_TEMP, 1, 1);
}

/* Entry action for state 'CANCELAR'. */
static void prefix_enact_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_CANCELAR(Prefix* handle)
{
	/* Entry action for state 'CANCELAR'. */
	prefixIface_opMostrar_msj(handle, PREFIX_PREFIXIFACE_MSJ_MENU_CANCELAR, 1, 2);
}

/* Entry action for state 'SETEAR_TEMP'. */
static void prefix_enact_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_SETEAR_TEMP(Prefix* handle)
{
	/* Entry action for state 'SETEAR_TEMP'. */
	prefixIface_opMostrar_msj(handle, PREFIX_PREFIXIFACE_MSJ_MENU_SETEAR_TEMP, 1, 2);
}

/* Entry action for state 'ENFRIAR'. */
static void prefix_enact_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR(Prefix* handle)
{
	/* Entry action for state 'ENFRIAR'. */
	prefixIface_opMostrar_msj(handle, PREFIX_PREFIXIFACE_MSJ_MENU_ENFRIAR, 1, 2);
}

/* Entry action for state 'MENU_CONF_MOTORES'. */
static void prefix_enact_LCD_MENU_CONF_MOTORES(Prefix* handle)
{
	/* Entry action for state 'MENU_CONF_MOTORES'. */
	prefixIface_opMostrar_msj(handle, PREFIX_PREFIXIFACE_MSJ_MENU_CONF_MOTORES, 1, 1);
}

/* Entry action for state 'CANCELAR'. */
static void prefix_enact_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_CANCELAR(Prefix* handle)
{
	/* Entry action for state 'CANCELAR'. */
	prefixIface_opMostrar_msj(handle, PREFIX_PREFIXIFACE_MSJ_MENU_CANCELAR, 1, 2);
}

/* Entry action for state 'START_EXTRUSION'. */
static void prefix_enact_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION(Prefix* handle)
{
	/* Entry action for state 'START_EXTRUSION'. */
	prefixIface_opMostrar_msj(handle, PREFIX_PREFIXIFACE_MSJ_MENU_MOTOR_EXTRUSION, 1, 2);
}

/* Entry action for state 'STOP_EXTRUSION'. */
static void prefix_enact_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION(Prefix* handle)
{
	/* Entry action for state 'STOP_EXTRUSION'. */
	prefixIface_opMostrar_msj(handle, PREFIX_PREFIXIFACE_MSJ_MENU_MOTOR_EXTRUSION_STOP, 1, 2);
}

/* Entry action for state 'START_RETRACT'. */
static void prefix_enact_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT(Prefix* handle)
{
	/* Entry action for state 'START_RETRACT'. */
	prefixIface_opMostrar_msj(handle, PREFIX_PREFIXIFACE_MSJ_MENU_MOTOR_EXTRUSION_RETRACT, 1, 2);
}

/* Entry action for state 'MENU_SET_TEMP'. */
static void prefix_enact_LCD_MENU_SET_TEMP(Prefix* handle)
{
	/* Entry action for state 'MENU_SET_TEMP'. */
	prefixIface_opMostrar_msj(handle, PREFIX_PREFIXIFACE_MSJ_MENU_SET_TEMP, 1, 1);
}

/* Entry action for state 'SELEC_TEMP'. */
static void prefix_enact_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP(Prefix* handle)
{
	/* Entry action for state 'SELEC_TEMP'. */
	prefixIface_opMostrar_num(handle, handle->internal.viSet_temp_lcd, 1, 2);
}

/* Entry action for state 'MENU_WIFI'. */
static void prefix_enact_LCD_MENU_WIFI(Prefix* handle)
{
	/* Entry action for state 'MENU_WIFI'. */
	prefixIface_opMostrar_msj(handle, PREFIX_PREFIXIFACE_MSJ_MENU_WIFI, 1, 1);
	prefixIface_opMostrar_msj(handle, handle->internal.viIP, 1, 2);
}

/* Entry action for state 'STOP'. */
static void prefix_enact_PUENTE_H_STOP(Prefix* handle)
{
	/* Entry action for state 'STOP'. */
	prefixIface_opStop_puente_h(handle);
}

/* Entry action for state 'H_ROTACION_HORARIO'. */
static void prefix_enact_PUENTE_H_H_ROTACION_HORARIO(Prefix* handle)
{
	/* Entry action for state 'H_ROTACION_HORARIO'. */
	prefixIface_opStart_puente_h(handle);
}

/* Entry action for state 'CONFIGURAR'. */
static void prefix_enact_PUENTE_H_CONFIGURAR(Prefix* handle)
{
	/* Entry action for state 'CONFIGURAR'. */
	prefixIface_opConfig_puente_h(handle);
	handle->iface.evConf_Ready_Puente_H_raised = bool_true;
}

/* Entry action for state 'H_RETRACT'. */
static void prefix_enact_PUENTE_H_H_RETRACT(Prefix* handle)
{
	/* Entry action for state 'H_RETRACT'. */
	prefixIface_opRetract_puente_h(handle);
}

/* Entry action for state 'TEMP_APAGADO'. */
static void prefix_enact_x_TEMP_APAGADO(Prefix* handle)
{
	/* Entry action for state 'TEMP_APAGADO'. */
	prefixIface_opApagar_control_temp(handle);
}

/* Entry action for state 'TEMP_CALENTAR'. */
static void prefix_enact_x_TEMP_CALENTAR(Prefix* handle)
{
	/* Entry action for state 'TEMP_CALENTAR'. */
	handle->internal.viRef_temp = handle->internal.viSetPoint;
}

/* Entry action for state 'TEMP_CONTROL'. */
static void prefix_enact_x_TEMP_CALENTAR_EJECUTAR_CONTROL_TEMP_CONTROL(Prefix* handle)
{
	/* Entry action for state 'TEMP_CONTROL'. */
	prefix_setTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_x_TEMP_CALENTAR_EJECUTAR_CONTROL_TEMP_CONTROL_tev0_raised) , 500, bool_false);
	handle->internal.viActual_temp = prefixIface_opControlar_temp(handle, handle->internal.viRef_temp);
}

/* Entry action for state 'TEMP_ENVIAR_UART'. */
static void prefix_enact_x_TEMP_CALENTAR_ENVIAR_DATOS_TEMP_ENVIAR_UART(Prefix* handle)
{
	/* Entry action for state 'TEMP_ENVIAR_UART'. */
	prefix_setTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_x_TEMP_CALENTAR_ENVIAR_DATOS_TEMP_ENVIAR_UART_tev0_raised) , 1 * 1000, bool_false);
}

/* Entry action for state 'TEMP_CONF'. */
static void prefix_enact_x_TEMP_CONF(Prefix* handle)
{
	/* Entry action for state 'TEMP_CONF'. */
	prefixIface_opConfig_control_temp(handle);
	handle->iface.evConf_Ready_temp_raised = bool_true;
}

/* Entry action for state 'UART_SEND_STATUS'. */
static void prefix_enact_UART_UART_SEND_STATUS(Prefix* handle)
{
	/* Entry action for state 'UART_SEND_STATUS'. */
	prefix_setTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_UART_UART_SEND_STATUS_tev0_raised) , 2000, bool_false);
	prefixInternal_opSend_Status(handle, handle->internal.viStatus, handle->internal.viActual_temp, handle->internal.viSetPoint);
}

/* Exit action for state 'DEBOUNCE'. */
static void prefix_exact_BOTON_DEL_ENCODER_DEBOUNCE(Prefix* handle)
{
	/* Exit action for state 'DEBOUNCE'. */
	prefix_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_BOTON_DEL_ENCODER_DEBOUNCE_tev0_raised) );		
}

/* Exit action for state 'TEMP_CONTROL'. */
static void prefix_exact_x_TEMP_CALENTAR_EJECUTAR_CONTROL_TEMP_CONTROL(Prefix* handle)
{
	/* Exit action for state 'TEMP_CONTROL'. */
	prefix_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_x_TEMP_CALENTAR_EJECUTAR_CONTROL_TEMP_CONTROL_tev0_raised) );		
}

/* Exit action for state 'TEMP_ENVIAR_UART'. */
static void prefix_exact_x_TEMP_CALENTAR_ENVIAR_DATOS_TEMP_ENVIAR_UART(Prefix* handle)
{
	/* Exit action for state 'TEMP_ENVIAR_UART'. */
	prefix_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_x_TEMP_CALENTAR_ENVIAR_DATOS_TEMP_ENVIAR_UART_tev0_raised) );		
}

/* Exit action for state 'UART_SEND_STATUS'. */
static void prefix_exact_UART_UART_SEND_STATUS(Prefix* handle)
{
	/* Exit action for state 'UART_SEND_STATUS'. */
	prefix_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_UART_UART_SEND_STATUS_tev0_raised) );		
}

/* 'default' enter sequence for state DEBOUNCE */
static void prefix_enseq_BOTON_DEL_ENCODER_DEBOUNCE_default(Prefix* handle)
{
	/* 'default' enter sequence for state DEBOUNCE */
	prefix_enact_BOTON_DEL_ENCODER_DEBOUNCE(handle);
	handle->stateConfVector[0] = Prefix_BOTON_DEL_ENCODER_DEBOUNCE;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state NO_OPRIMIDO */
static void prefix_enseq_BOTON_DEL_ENCODER_NO_OPRIMIDO_default(Prefix* handle)
{
	/* 'default' enter sequence for state NO_OPRIMIDO */
	handle->stateConfVector[0] = Prefix_BOTON_DEL_ENCODER_NO_OPRIMIDO;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state OPRIMIDO */
static void prefix_enseq_BOTON_DEL_ENCODER_OPRIMIDO_default(Prefix* handle)
{
	/* 'default' enter sequence for state OPRIMIDO */
	prefix_enact_BOTON_DEL_ENCODER_OPRIMIDO(handle);
	handle->stateConfVector[0] = Prefix_BOTON_DEL_ENCODER_OPRIMIDO;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state VALIDACION */
static void prefix_enseq_BOTON_DEL_ENCODER_VALIDACION_default(Prefix* handle)
{
	/* 'default' enter sequence for state VALIDACION */
	handle->stateConfVector[0] = Prefix_BOTON_DEL_ENCODER_VALIDACION;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state REPOSO */
static void prefix_enseq_ENCODER_REPOSO_default(Prefix* handle)
{
	/* 'default' enter sequence for state REPOSO */
	prefix_enact_ENCODER_REPOSO(handle);
	handle->stateConfVector[1] = Prefix_ENCODER_REPOSO;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state ROTACION_DERECHA */
static void prefix_enseq_ENCODER_ROTACION_DERECHA_default(Prefix* handle)
{
	/* 'default' enter sequence for state ROTACION_DERECHA */
	prefix_enact_ENCODER_ROTACION_DERECHA(handle);
	handle->stateConfVector[1] = Prefix_ENCODER_ROTACION_DERECHA;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state ROTACION_IZQUIERDA */
static void prefix_enseq_ENCODER_ROTACION_IZQUIERDA_default(Prefix* handle)
{
	/* 'default' enter sequence for state ROTACION_IZQUIERDA */
	prefix_enact_ENCODER_ROTACION_IZQUIERDA(handle);
	handle->stateConfVector[1] = Prefix_ENCODER_ROTACION_IZQUIERDA;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state MENU_PRINCIPAL */
static void prefix_enseq_LCD_MENU_PRINCIPAL_default(Prefix* handle)
{
	/* 'default' enter sequence for state MENU_PRINCIPAL */
	prefix_enact_LCD_MENU_PRINCIPAL(handle);
	prefix_enseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_default(handle);
}

/* 'default' enter sequence for state CONF_MOTORES */
static void prefix_enseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_MOTORES_default(Prefix* handle)
{
	/* 'default' enter sequence for state CONF_MOTORES */
	prefix_enact_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_MOTORES(handle);
	handle->stateConfVector[2] = Prefix_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_MOTORES;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state CONF_TEMP */
static void prefix_enseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP_default(Prefix* handle)
{
	/* 'default' enter sequence for state CONF_TEMP */
	prefix_enact_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP(handle);
	handle->stateConfVector[2] = Prefix_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state CONF_WI_FI */
static void prefix_enseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_WI_FI_default(Prefix* handle)
{
	/* 'default' enter sequence for state CONF_WI_FI */
	prefix_enact_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_WI_FI(handle);
	handle->stateConfVector[2] = Prefix_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_WI_FI;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state EXTRUSION */
static void prefix_enseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION_default(Prefix* handle)
{
	/* 'default' enter sequence for state EXTRUSION */
	prefix_enact_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION(handle);
	handle->stateConfVector[2] = Prefix_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state MENU_CONF_TEMP */
static void prefix_enseq_LCD_MENU_CONF_TEMP_default(Prefix* handle)
{
	/* 'default' enter sequence for state MENU_CONF_TEMP */
	prefix_enact_LCD_MENU_CONF_TEMP(handle);
	prefix_enseq_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_default(handle);
}

/* 'default' enter sequence for state CANCELAR */
static void prefix_enseq_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_CANCELAR_default(Prefix* handle)
{
	/* 'default' enter sequence for state CANCELAR */
	prefix_enact_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_CANCELAR(handle);
	handle->stateConfVector[2] = Prefix_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_CANCELAR;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state SETEAR_TEMP */
static void prefix_enseq_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_SETEAR_TEMP_default(Prefix* handle)
{
	/* 'default' enter sequence for state SETEAR_TEMP */
	prefix_enact_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_SETEAR_TEMP(handle);
	handle->stateConfVector[2] = Prefix_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_SETEAR_TEMP;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state ENFRIAR */
static void prefix_enseq_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR_default(Prefix* handle)
{
	/* 'default' enter sequence for state ENFRIAR */
	prefix_enact_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR(handle);
	handle->stateConfVector[2] = Prefix_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state MENU_CONF_MOTORES */
static void prefix_enseq_LCD_MENU_CONF_MOTORES_default(Prefix* handle)
{
	/* 'default' enter sequence for state MENU_CONF_MOTORES */
	prefix_enact_LCD_MENU_CONF_MOTORES(handle);
	prefix_enseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_default(handle);
}

/* 'default' enter sequence for state CANCELAR */
static void prefix_enseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_CANCELAR_default(Prefix* handle)
{
	/* 'default' enter sequence for state CANCELAR */
	prefix_enact_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_CANCELAR(handle);
	handle->stateConfVector[2] = Prefix_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_CANCELAR;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state START_EXTRUSION */
static void prefix_enseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION_default(Prefix* handle)
{
	/* 'default' enter sequence for state START_EXTRUSION */
	prefix_enact_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION(handle);
	handle->stateConfVector[2] = Prefix_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state STOP_EXTRUSION */
static void prefix_enseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION_default(Prefix* handle)
{
	/* 'default' enter sequence for state STOP_EXTRUSION */
	prefix_enact_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION(handle);
	handle->stateConfVector[2] = Prefix_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state START_RETRACT */
static void prefix_enseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT_default(Prefix* handle)
{
	/* 'default' enter sequence for state START_RETRACT */
	prefix_enact_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT(handle);
	handle->stateConfVector[2] = Prefix_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state MENU_SET_TEMP */
static void prefix_enseq_LCD_MENU_SET_TEMP_default(Prefix* handle)
{
	/* 'default' enter sequence for state MENU_SET_TEMP */
	prefix_enact_LCD_MENU_SET_TEMP(handle);
	prefix_enseq_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_default(handle);
}

/* 'default' enter sequence for state SELEC_TEMP */
static void prefix_enseq_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP_default(Prefix* handle)
{
	/* 'default' enter sequence for state SELEC_TEMP */
	prefix_enact_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP(handle);
	handle->stateConfVector[2] = Prefix_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state MENU_WIFI */
static void prefix_enseq_LCD_MENU_WIFI_default(Prefix* handle)
{
	/* 'default' enter sequence for state MENU_WIFI */
	prefix_enact_LCD_MENU_WIFI(handle);
	handle->stateConfVector[2] = Prefix_LCD_MENU_WIFI;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state STOP */
static void prefix_enseq_PUENTE_H_STOP_default(Prefix* handle)
{
	/* 'default' enter sequence for state STOP */
	prefix_enact_PUENTE_H_STOP(handle);
	handle->stateConfVector[3] = Prefix_PUENTE_H_STOP;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state H_ROTACION_HORARIO */
static void prefix_enseq_PUENTE_H_H_ROTACION_HORARIO_default(Prefix* handle)
{
	/* 'default' enter sequence for state H_ROTACION_HORARIO */
	prefix_enact_PUENTE_H_H_ROTACION_HORARIO(handle);
	handle->stateConfVector[3] = Prefix_PUENTE_H_H_ROTACION_HORARIO;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state CONFIGURAR */
static void prefix_enseq_PUENTE_H_CONFIGURAR_default(Prefix* handle)
{
	/* 'default' enter sequence for state CONFIGURAR */
	prefix_enact_PUENTE_H_CONFIGURAR(handle);
	handle->stateConfVector[3] = Prefix_PUENTE_H_CONFIGURAR;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state H_RETRACT */
static void prefix_enseq_PUENTE_H_H_RETRACT_default(Prefix* handle)
{
	/* 'default' enter sequence for state H_RETRACT */
	prefix_enact_PUENTE_H_H_RETRACT(handle);
	handle->stateConfVector[3] = Prefix_PUENTE_H_H_RETRACT;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state TEMP_APAGADO */
static void prefix_enseq_x_TEMP_APAGADO_default(Prefix* handle)
{
	/* 'default' enter sequence for state TEMP_APAGADO */
	prefix_enact_x_TEMP_APAGADO(handle);
	handle->stateConfVector[4] = Prefix_x_TEMP_APAGADO;
	handle->stateConfVectorPosition = 4;
}

/* 'default' enter sequence for state TEMP_CALENTAR */
static void prefix_enseq_x_TEMP_CALENTAR_default(Prefix* handle)
{
	/* 'default' enter sequence for state TEMP_CALENTAR */
	prefix_enact_x_TEMP_CALENTAR(handle);
	prefix_enseq_x_TEMP_CALENTAR_EJECUTAR_CONTROL_default(handle);
	prefix_enseq_x_TEMP_CALENTAR_ENVIAR_DATOS_default(handle);
}

/* 'default' enter sequence for state TEMP_CONTROL */
static void prefix_enseq_x_TEMP_CALENTAR_EJECUTAR_CONTROL_TEMP_CONTROL_default(Prefix* handle)
{
	/* 'default' enter sequence for state TEMP_CONTROL */
	prefix_enact_x_TEMP_CALENTAR_EJECUTAR_CONTROL_TEMP_CONTROL(handle);
	handle->stateConfVector[4] = Prefix_x_TEMP_CALENTAR_EJECUTAR_CONTROL_TEMP_CONTROL;
	handle->stateConfVectorPosition = 4;
}

/* 'default' enter sequence for state TEMP_ENVIAR_UART */
static void prefix_enseq_x_TEMP_CALENTAR_ENVIAR_DATOS_TEMP_ENVIAR_UART_default(Prefix* handle)
{
	/* 'default' enter sequence for state TEMP_ENVIAR_UART */
	prefix_enact_x_TEMP_CALENTAR_ENVIAR_DATOS_TEMP_ENVIAR_UART(handle);
	handle->stateConfVector[5] = Prefix_x_TEMP_CALENTAR_ENVIAR_DATOS_TEMP_ENVIAR_UART;
	handle->stateConfVectorPosition = 5;
}

/* 'default' enter sequence for state TEMP_CONF */
static void prefix_enseq_x_TEMP_CONF_default(Prefix* handle)
{
	/* 'default' enter sequence for state TEMP_CONF */
	prefix_enact_x_TEMP_CONF(handle);
	handle->stateConfVector[4] = Prefix_x_TEMP_CONF;
	handle->stateConfVectorPosition = 4;
}

/* 'default' enter sequence for state UART_SEND_STATUS */
static void prefix_enseq_UART_UART_SEND_STATUS_default(Prefix* handle)
{
	/* 'default' enter sequence for state UART_SEND_STATUS */
	prefix_enact_UART_UART_SEND_STATUS(handle);
	handle->stateConfVector[6] = Prefix_UART_UART_SEND_STATUS;
	handle->stateConfVectorPosition = 6;
}

/* 'default' enter sequence for region BOTON_DEL_ENCODER */
static void prefix_enseq_BOTON_DEL_ENCODER_default(Prefix* handle)
{
	/* 'default' enter sequence for region BOTON_DEL_ENCODER */
	prefix_react_BOTON_DEL_ENCODER__entry_Default(handle);
}

/* 'default' enter sequence for region ENCODER */
static void prefix_enseq_ENCODER_default(Prefix* handle)
{
	/* 'default' enter sequence for region ENCODER */
	prefix_react_ENCODER__entry_Default(handle);
}

/* 'default' enter sequence for region LCD */
static void prefix_enseq_LCD_default(Prefix* handle)
{
	/* 'default' enter sequence for region LCD */
	prefix_react_LCD__entry_Default(handle);
}

/* 'default' enter sequence for region MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL */
static void prefix_enseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_default(Prefix* handle)
{
	/* 'default' enter sequence for region MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL */
	prefix_react_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL__entry_Default(handle);
}

/* 'default' enter sequence for region MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP */
static void prefix_enseq_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_default(Prefix* handle)
{
	/* 'default' enter sequence for region MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP */
	prefix_react_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP__entry_Default(handle);
}

/* 'default' enter sequence for region MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES */
static void prefix_enseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_default(Prefix* handle)
{
	/* 'default' enter sequence for region MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES */
	prefix_react_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES__entry_Default(handle);
}

/* 'default' enter sequence for region MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP */
static void prefix_enseq_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_default(Prefix* handle)
{
	/* 'default' enter sequence for region MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP */
	prefix_react_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP__entry_Default(handle);
}

/* 'default' enter sequence for region PUENTE_H */
static void prefix_enseq_PUENTE_H_default(Prefix* handle)
{
	/* 'default' enter sequence for region PUENTE_H */
	prefix_react_PUENTE_H__entry_Default(handle);
}

/* 'default' enter sequence for region x */
static void prefix_enseq_x_default(Prefix* handle)
{
	/* 'default' enter sequence for region x */
	prefix_react_x__entry_Default(handle);
}

/* 'default' enter sequence for region EJECUTAR_CONTROL */
static void prefix_enseq_x_TEMP_CALENTAR_EJECUTAR_CONTROL_default(Prefix* handle)
{
	/* 'default' enter sequence for region EJECUTAR_CONTROL */
	prefix_react_x_TEMP_CALENTAR_EJECUTAR_CONTROL__entry_Default(handle);
}

/* 'default' enter sequence for region ENVIAR_DATOS */
static void prefix_enseq_x_TEMP_CALENTAR_ENVIAR_DATOS_default(Prefix* handle)
{
	/* 'default' enter sequence for region ENVIAR_DATOS */
	prefix_react_x_TEMP_CALENTAR_ENVIAR_DATOS__entry_Default(handle);
}

/* 'default' enter sequence for region UART */
static void prefix_enseq_UART_default(Prefix* handle)
{
	/* 'default' enter sequence for region UART */
	prefix_react_UART__entry_Default(handle);
}

/* Default exit sequence for state DEBOUNCE */
static void prefix_exseq_BOTON_DEL_ENCODER_DEBOUNCE(Prefix* handle)
{
	/* Default exit sequence for state DEBOUNCE */
	handle->stateConfVector[0] = Prefix_last_state;
	handle->stateConfVectorPosition = 0;
	prefix_exact_BOTON_DEL_ENCODER_DEBOUNCE(handle);
}

/* Default exit sequence for state NO_OPRIMIDO */
static void prefix_exseq_BOTON_DEL_ENCODER_NO_OPRIMIDO(Prefix* handle)
{
	/* Default exit sequence for state NO_OPRIMIDO */
	handle->stateConfVector[0] = Prefix_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state OPRIMIDO */
static void prefix_exseq_BOTON_DEL_ENCODER_OPRIMIDO(Prefix* handle)
{
	/* Default exit sequence for state OPRIMIDO */
	handle->stateConfVector[0] = Prefix_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state VALIDACION */
static void prefix_exseq_BOTON_DEL_ENCODER_VALIDACION(Prefix* handle)
{
	/* Default exit sequence for state VALIDACION */
	handle->stateConfVector[0] = Prefix_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state REPOSO */
static void prefix_exseq_ENCODER_REPOSO(Prefix* handle)
{
	/* Default exit sequence for state REPOSO */
	handle->stateConfVector[1] = Prefix_last_state;
	handle->stateConfVectorPosition = 1;
}

/* Default exit sequence for state ROTACION_DERECHA */
static void prefix_exseq_ENCODER_ROTACION_DERECHA(Prefix* handle)
{
	/* Default exit sequence for state ROTACION_DERECHA */
	handle->stateConfVector[1] = Prefix_last_state;
	handle->stateConfVectorPosition = 1;
}

/* Default exit sequence for state ROTACION_IZQUIERDA */
static void prefix_exseq_ENCODER_ROTACION_IZQUIERDA(Prefix* handle)
{
	/* Default exit sequence for state ROTACION_IZQUIERDA */
	handle->stateConfVector[1] = Prefix_last_state;
	handle->stateConfVectorPosition = 1;
}

/* Default exit sequence for state MENU_PRINCIPAL */
static void prefix_exseq_LCD_MENU_PRINCIPAL(Prefix* handle)
{
	/* Default exit sequence for state MENU_PRINCIPAL */
	prefix_exseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL(handle);
}

/* Default exit sequence for state CONF_MOTORES */
static void prefix_exseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_MOTORES(Prefix* handle)
{
	/* Default exit sequence for state CONF_MOTORES */
	handle->stateConfVector[2] = Prefix_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state CONF_TEMP */
static void prefix_exseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP(Prefix* handle)
{
	/* Default exit sequence for state CONF_TEMP */
	handle->stateConfVector[2] = Prefix_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state CONF_WI_FI */
static void prefix_exseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_WI_FI(Prefix* handle)
{
	/* Default exit sequence for state CONF_WI_FI */
	handle->stateConfVector[2] = Prefix_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state EXTRUSION */
static void prefix_exseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION(Prefix* handle)
{
	/* Default exit sequence for state EXTRUSION */
	handle->stateConfVector[2] = Prefix_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state MENU_CONF_TEMP */
static void prefix_exseq_LCD_MENU_CONF_TEMP(Prefix* handle)
{
	/* Default exit sequence for state MENU_CONF_TEMP */
	prefix_exseq_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP(handle);
}

/* Default exit sequence for state CANCELAR */
static void prefix_exseq_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_CANCELAR(Prefix* handle)
{
	/* Default exit sequence for state CANCELAR */
	handle->stateConfVector[2] = Prefix_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state SETEAR_TEMP */
static void prefix_exseq_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_SETEAR_TEMP(Prefix* handle)
{
	/* Default exit sequence for state SETEAR_TEMP */
	handle->stateConfVector[2] = Prefix_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state ENFRIAR */
static void prefix_exseq_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR(Prefix* handle)
{
	/* Default exit sequence for state ENFRIAR */
	handle->stateConfVector[2] = Prefix_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state MENU_CONF_MOTORES */
static void prefix_exseq_LCD_MENU_CONF_MOTORES(Prefix* handle)
{
	/* Default exit sequence for state MENU_CONF_MOTORES */
	prefix_exseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES(handle);
}

/* Default exit sequence for state CANCELAR */
static void prefix_exseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_CANCELAR(Prefix* handle)
{
	/* Default exit sequence for state CANCELAR */
	handle->stateConfVector[2] = Prefix_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state START_EXTRUSION */
static void prefix_exseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION(Prefix* handle)
{
	/* Default exit sequence for state START_EXTRUSION */
	handle->stateConfVector[2] = Prefix_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state STOP_EXTRUSION */
static void prefix_exseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION(Prefix* handle)
{
	/* Default exit sequence for state STOP_EXTRUSION */
	handle->stateConfVector[2] = Prefix_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state START_RETRACT */
static void prefix_exseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT(Prefix* handle)
{
	/* Default exit sequence for state START_RETRACT */
	handle->stateConfVector[2] = Prefix_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state MENU_SET_TEMP */
static void prefix_exseq_LCD_MENU_SET_TEMP(Prefix* handle)
{
	/* Default exit sequence for state MENU_SET_TEMP */
	prefix_exseq_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP(handle);
}

/* Default exit sequence for state SELEC_TEMP */
static void prefix_exseq_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP(Prefix* handle)
{
	/* Default exit sequence for state SELEC_TEMP */
	handle->stateConfVector[2] = Prefix_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state MENU_WIFI */
static void prefix_exseq_LCD_MENU_WIFI(Prefix* handle)
{
	/* Default exit sequence for state MENU_WIFI */
	handle->stateConfVector[2] = Prefix_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state STOP */
static void prefix_exseq_PUENTE_H_STOP(Prefix* handle)
{
	/* Default exit sequence for state STOP */
	handle->stateConfVector[3] = Prefix_last_state;
	handle->stateConfVectorPosition = 3;
}

/* Default exit sequence for state H_ROTACION_HORARIO */
static void prefix_exseq_PUENTE_H_H_ROTACION_HORARIO(Prefix* handle)
{
	/* Default exit sequence for state H_ROTACION_HORARIO */
	handle->stateConfVector[3] = Prefix_last_state;
	handle->stateConfVectorPosition = 3;
}

/* Default exit sequence for state CONFIGURAR */
static void prefix_exseq_PUENTE_H_CONFIGURAR(Prefix* handle)
{
	/* Default exit sequence for state CONFIGURAR */
	handle->stateConfVector[3] = Prefix_last_state;
	handle->stateConfVectorPosition = 3;
}

/* Default exit sequence for state H_RETRACT */
static void prefix_exseq_PUENTE_H_H_RETRACT(Prefix* handle)
{
	/* Default exit sequence for state H_RETRACT */
	handle->stateConfVector[3] = Prefix_last_state;
	handle->stateConfVectorPosition = 3;
}

/* Default exit sequence for state TEMP_APAGADO */
static void prefix_exseq_x_TEMP_APAGADO(Prefix* handle)
{
	/* Default exit sequence for state TEMP_APAGADO */
	handle->stateConfVector[4] = Prefix_last_state;
	handle->stateConfVectorPosition = 4;
}

/* Default exit sequence for state TEMP_CALENTAR */
static void prefix_exseq_x_TEMP_CALENTAR(Prefix* handle)
{
	/* Default exit sequence for state TEMP_CALENTAR */
	prefix_exseq_x_TEMP_CALENTAR_EJECUTAR_CONTROL(handle);
	prefix_exseq_x_TEMP_CALENTAR_ENVIAR_DATOS(handle);
}

/* Default exit sequence for state TEMP_CONTROL */
static void prefix_exseq_x_TEMP_CALENTAR_EJECUTAR_CONTROL_TEMP_CONTROL(Prefix* handle)
{
	/* Default exit sequence for state TEMP_CONTROL */
	handle->stateConfVector[4] = Prefix_last_state;
	handle->stateConfVectorPosition = 4;
	prefix_exact_x_TEMP_CALENTAR_EJECUTAR_CONTROL_TEMP_CONTROL(handle);
}

/* Default exit sequence for state TEMP_ENVIAR_UART */
static void prefix_exseq_x_TEMP_CALENTAR_ENVIAR_DATOS_TEMP_ENVIAR_UART(Prefix* handle)
{
	/* Default exit sequence for state TEMP_ENVIAR_UART */
	handle->stateConfVector[5] = Prefix_last_state;
	handle->stateConfVectorPosition = 5;
	prefix_exact_x_TEMP_CALENTAR_ENVIAR_DATOS_TEMP_ENVIAR_UART(handle);
}

/* Default exit sequence for state TEMP_CONF */
static void prefix_exseq_x_TEMP_CONF(Prefix* handle)
{
	/* Default exit sequence for state TEMP_CONF */
	handle->stateConfVector[4] = Prefix_last_state;
	handle->stateConfVectorPosition = 4;
}

/* Default exit sequence for state UART_SEND_STATUS */
static void prefix_exseq_UART_UART_SEND_STATUS(Prefix* handle)
{
	/* Default exit sequence for state UART_SEND_STATUS */
	handle->stateConfVector[6] = Prefix_last_state;
	handle->stateConfVectorPosition = 6;
	prefix_exact_UART_UART_SEND_STATUS(handle);
}

/* Default exit sequence for region BOTON_DEL_ENCODER */
static void prefix_exseq_BOTON_DEL_ENCODER(Prefix* handle)
{
	/* Default exit sequence for region BOTON_DEL_ENCODER */
	/* Handle exit of all possible states (of prefix.BOTON_DEL_ENCODER) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Prefix_BOTON_DEL_ENCODER_DEBOUNCE :
		{
			prefix_exseq_BOTON_DEL_ENCODER_DEBOUNCE(handle);
			break;
		}
		case Prefix_BOTON_DEL_ENCODER_NO_OPRIMIDO :
		{
			prefix_exseq_BOTON_DEL_ENCODER_NO_OPRIMIDO(handle);
			break;
		}
		case Prefix_BOTON_DEL_ENCODER_OPRIMIDO :
		{
			prefix_exseq_BOTON_DEL_ENCODER_OPRIMIDO(handle);
			break;
		}
		case Prefix_BOTON_DEL_ENCODER_VALIDACION :
		{
			prefix_exseq_BOTON_DEL_ENCODER_VALIDACION(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region ENCODER */
static void prefix_exseq_ENCODER(Prefix* handle)
{
	/* Default exit sequence for region ENCODER */
	/* Handle exit of all possible states (of prefix.ENCODER) at position 1... */
	switch(handle->stateConfVector[ 1 ])
	{
		case Prefix_ENCODER_REPOSO :
		{
			prefix_exseq_ENCODER_REPOSO(handle);
			break;
		}
		case Prefix_ENCODER_ROTACION_DERECHA :
		{
			prefix_exseq_ENCODER_ROTACION_DERECHA(handle);
			break;
		}
		case Prefix_ENCODER_ROTACION_IZQUIERDA :
		{
			prefix_exseq_ENCODER_ROTACION_IZQUIERDA(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region LCD */
static void prefix_exseq_LCD(Prefix* handle)
{
	/* Default exit sequence for region LCD */
	/* Handle exit of all possible states (of prefix.LCD) at position 2... */
	switch(handle->stateConfVector[ 2 ])
	{
		case Prefix_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_MOTORES :
		{
			prefix_exseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_MOTORES(handle);
			break;
		}
		case Prefix_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP :
		{
			prefix_exseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP(handle);
			break;
		}
		case Prefix_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_WI_FI :
		{
			prefix_exseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_WI_FI(handle);
			break;
		}
		case Prefix_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION :
		{
			prefix_exseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION(handle);
			break;
		}
		case Prefix_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_CANCELAR :
		{
			prefix_exseq_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_CANCELAR(handle);
			break;
		}
		case Prefix_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_SETEAR_TEMP :
		{
			prefix_exseq_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_SETEAR_TEMP(handle);
			break;
		}
		case Prefix_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR :
		{
			prefix_exseq_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR(handle);
			break;
		}
		case Prefix_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_CANCELAR :
		{
			prefix_exseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_CANCELAR(handle);
			break;
		}
		case Prefix_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION :
		{
			prefix_exseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION(handle);
			break;
		}
		case Prefix_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION :
		{
			prefix_exseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION(handle);
			break;
		}
		case Prefix_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT :
		{
			prefix_exseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT(handle);
			break;
		}
		case Prefix_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP :
		{
			prefix_exseq_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP(handle);
			break;
		}
		case Prefix_LCD_MENU_WIFI :
		{
			prefix_exseq_LCD_MENU_WIFI(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL */
static void prefix_exseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL(Prefix* handle)
{
	/* Default exit sequence for region MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL */
	/* Handle exit of all possible states (of prefix.LCD.MENU_PRINCIPAL.MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL) at position 2... */
	switch(handle->stateConfVector[ 2 ])
	{
		case Prefix_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_MOTORES :
		{
			prefix_exseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_MOTORES(handle);
			break;
		}
		case Prefix_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP :
		{
			prefix_exseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP(handle);
			break;
		}
		case Prefix_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_WI_FI :
		{
			prefix_exseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_WI_FI(handle);
			break;
		}
		case Prefix_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION :
		{
			prefix_exseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP */
static void prefix_exseq_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP(Prefix* handle)
{
	/* Default exit sequence for region MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP */
	/* Handle exit of all possible states (of prefix.LCD.MENU_CONF_TEMP.MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP) at position 2... */
	switch(handle->stateConfVector[ 2 ])
	{
		case Prefix_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_CANCELAR :
		{
			prefix_exseq_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_CANCELAR(handle);
			break;
		}
		case Prefix_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_SETEAR_TEMP :
		{
			prefix_exseq_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_SETEAR_TEMP(handle);
			break;
		}
		case Prefix_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR :
		{
			prefix_exseq_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES */
static void prefix_exseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES(Prefix* handle)
{
	/* Default exit sequence for region MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES */
	/* Handle exit of all possible states (of prefix.LCD.MENU_CONF_MOTORES.MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES) at position 2... */
	switch(handle->stateConfVector[ 2 ])
	{
		case Prefix_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_CANCELAR :
		{
			prefix_exseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_CANCELAR(handle);
			break;
		}
		case Prefix_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION :
		{
			prefix_exseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION(handle);
			break;
		}
		case Prefix_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION :
		{
			prefix_exseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION(handle);
			break;
		}
		case Prefix_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT :
		{
			prefix_exseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP */
static void prefix_exseq_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP(Prefix* handle)
{
	/* Default exit sequence for region MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP */
	/* Handle exit of all possible states (of prefix.LCD.MENU_SET_TEMP.MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP) at position 2... */
	switch(handle->stateConfVector[ 2 ])
	{
		case Prefix_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP :
		{
			prefix_exseq_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region PUENTE_H */
static void prefix_exseq_PUENTE_H(Prefix* handle)
{
	/* Default exit sequence for region PUENTE_H */
	/* Handle exit of all possible states (of prefix.PUENTE_H) at position 3... */
	switch(handle->stateConfVector[ 3 ])
	{
		case Prefix_PUENTE_H_STOP :
		{
			prefix_exseq_PUENTE_H_STOP(handle);
			break;
		}
		case Prefix_PUENTE_H_H_ROTACION_HORARIO :
		{
			prefix_exseq_PUENTE_H_H_ROTACION_HORARIO(handle);
			break;
		}
		case Prefix_PUENTE_H_CONFIGURAR :
		{
			prefix_exseq_PUENTE_H_CONFIGURAR(handle);
			break;
		}
		case Prefix_PUENTE_H_H_RETRACT :
		{
			prefix_exseq_PUENTE_H_H_RETRACT(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region x */
static void prefix_exseq_x(Prefix* handle)
{
	/* Default exit sequence for region x */
	/* Handle exit of all possible states (of prefix.x) at position 4... */
	switch(handle->stateConfVector[ 4 ])
	{
		case Prefix_x_TEMP_APAGADO :
		{
			prefix_exseq_x_TEMP_APAGADO(handle);
			break;
		}
		case Prefix_x_TEMP_CALENTAR_EJECUTAR_CONTROL_TEMP_CONTROL :
		{
			prefix_exseq_x_TEMP_CALENTAR_EJECUTAR_CONTROL_TEMP_CONTROL(handle);
			break;
		}
		case Prefix_x_TEMP_CONF :
		{
			prefix_exseq_x_TEMP_CONF(handle);
			break;
		}
		default: break;
	}
	/* Handle exit of all possible states (of prefix.x) at position 5... */
	switch(handle->stateConfVector[ 5 ])
	{
		case Prefix_x_TEMP_CALENTAR_ENVIAR_DATOS_TEMP_ENVIAR_UART :
		{
			prefix_exseq_x_TEMP_CALENTAR_ENVIAR_DATOS_TEMP_ENVIAR_UART(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region EJECUTAR_CONTROL */
static void prefix_exseq_x_TEMP_CALENTAR_EJECUTAR_CONTROL(Prefix* handle)
{
	/* Default exit sequence for region EJECUTAR_CONTROL */
	/* Handle exit of all possible states (of prefix.x.TEMP_CALENTAR.EJECUTAR_CONTROL) at position 4... */
	switch(handle->stateConfVector[ 4 ])
	{
		case Prefix_x_TEMP_CALENTAR_EJECUTAR_CONTROL_TEMP_CONTROL :
		{
			prefix_exseq_x_TEMP_CALENTAR_EJECUTAR_CONTROL_TEMP_CONTROL(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region ENVIAR_DATOS */
static void prefix_exseq_x_TEMP_CALENTAR_ENVIAR_DATOS(Prefix* handle)
{
	/* Default exit sequence for region ENVIAR_DATOS */
	/* Handle exit of all possible states (of prefix.x.TEMP_CALENTAR.ENVIAR_DATOS) at position 5... */
	switch(handle->stateConfVector[ 5 ])
	{
		case Prefix_x_TEMP_CALENTAR_ENVIAR_DATOS_TEMP_ENVIAR_UART :
		{
			prefix_exseq_x_TEMP_CALENTAR_ENVIAR_DATOS_TEMP_ENVIAR_UART(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region UART */
static void prefix_exseq_UART(Prefix* handle)
{
	/* Default exit sequence for region UART */
	/* Handle exit of all possible states (of prefix.UART) at position 6... */
	switch(handle->stateConfVector[ 6 ])
	{
		case Prefix_UART_UART_SEND_STATUS :
		{
			prefix_exseq_UART_UART_SEND_STATUS(handle);
			break;
		}
		default: break;
	}
}

/* The reactions of state DEBOUNCE. */
static void prefix_react_BOTON_DEL_ENCODER_DEBOUNCE(Prefix* handle)
{
	/* The reactions of state DEBOUNCE. */
	if (prefix_check_BOTON_DEL_ENCODER_DEBOUNCE_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_BOTON_DEL_ENCODER_DEBOUNCE_tr0(handle);
	} 
}

/* The reactions of state NO_OPRIMIDO. */
static void prefix_react_BOTON_DEL_ENCODER_NO_OPRIMIDO(Prefix* handle)
{
	/* The reactions of state NO_OPRIMIDO. */
	if (prefix_check_BOTON_DEL_ENCODER_NO_OPRIMIDO_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_BOTON_DEL_ENCODER_NO_OPRIMIDO_tr0(handle);
	} 
}

/* The reactions of state OPRIMIDO. */
static void prefix_react_BOTON_DEL_ENCODER_OPRIMIDO(Prefix* handle)
{
	/* The reactions of state OPRIMIDO. */
	if (prefix_check_BOTON_DEL_ENCODER_OPRIMIDO_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_BOTON_DEL_ENCODER_OPRIMIDO_tr0(handle);
	} 
}

/* The reactions of state VALIDACION. */
static void prefix_react_BOTON_DEL_ENCODER_VALIDACION(Prefix* handle)
{
	/* The reactions of state VALIDACION. */
	if (prefix_check_BOTON_DEL_ENCODER_VALIDACION_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_BOTON_DEL_ENCODER_VALIDACION_tr0(handle);
	}  else
	{
		if (prefix_check_BOTON_DEL_ENCODER_VALIDACION_tr1_tr1(handle) == bool_true)
		{ 
			prefix_effect_BOTON_DEL_ENCODER_VALIDACION_tr1(handle);
		} 
	}
}

/* The reactions of state REPOSO. */
static void prefix_react_ENCODER_REPOSO(Prefix* handle)
{
	/* The reactions of state REPOSO. */
	if (prefix_check_ENCODER_REPOSO_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_ENCODER_REPOSO_tr0(handle);
	}  else
	{
		if (prefix_check_ENCODER_REPOSO_tr1_tr1(handle) == bool_true)
		{ 
			prefix_effect_ENCODER_REPOSO_tr1(handle);
		}  else
		{
			if (prefix_check_ENCODER_REPOSO_tr2_tr2(handle) == bool_true)
			{ 
				prefix_effect_ENCODER_REPOSO_tr2(handle);
			}  else
			{
				if (prefix_check_ENCODER_REPOSO_tr3_tr3(handle) == bool_true)
				{ 
					prefix_effect_ENCODER_REPOSO_tr3(handle);
				} 
			}
		}
	}
}

/* The reactions of state ROTACION_DERECHA. */
static void prefix_react_ENCODER_ROTACION_DERECHA(Prefix* handle)
{
	/* The reactions of state ROTACION_DERECHA. */
	if (prefix_check_ENCODER_ROTACION_DERECHA_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_ENCODER_ROTACION_DERECHA_tr0(handle);
	} 
}

/* The reactions of state ROTACION_IZQUIERDA. */
static void prefix_react_ENCODER_ROTACION_IZQUIERDA(Prefix* handle)
{
	/* The reactions of state ROTACION_IZQUIERDA. */
	if (prefix_check_ENCODER_ROTACION_IZQUIERDA_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_ENCODER_ROTACION_IZQUIERDA_tr0(handle);
	} 
}

/* The reactions of state CONF_MOTORES. */
static void prefix_react_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_MOTORES(Prefix* handle)
{
	/* The reactions of state CONF_MOTORES. */
	if (prefix_check_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_MOTORES_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_MOTORES_tr0(handle);
	}  else
	{
		if (prefix_check_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_MOTORES_tr1_tr1(handle) == bool_true)
		{ 
			prefix_effect_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_MOTORES_tr1(handle);
		}  else
		{
			if (prefix_check_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_MOTORES_tr2_tr2(handle) == bool_true)
			{ 
				prefix_effect_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_MOTORES_tr2(handle);
			} 
		}
	}
}

/* The reactions of state CONF_TEMP. */
static void prefix_react_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP(Prefix* handle)
{
	/* The reactions of state CONF_TEMP. */
	if (prefix_check_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP_tr0(handle);
	}  else
	{
		if (prefix_check_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP_tr1_tr1(handle) == bool_true)
		{ 
			prefix_effect_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP_tr1(handle);
		}  else
		{
			if (prefix_check_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP_tr2_tr2(handle) == bool_true)
			{ 
				prefix_effect_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP_tr2(handle);
			} 
		}
	}
}

/* The reactions of state CONF_WI_FI. */
static void prefix_react_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_WI_FI(Prefix* handle)
{
	/* The reactions of state CONF_WI_FI. */
	if (prefix_check_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_WI_FI_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_WI_FI_tr0(handle);
	}  else
	{
		if (prefix_check_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_WI_FI_tr1_tr1(handle) == bool_true)
		{ 
			prefix_effect_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_WI_FI_tr1(handle);
		}  else
		{
			if (prefix_check_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_WI_FI_tr2_tr2(handle) == bool_true)
			{ 
				prefix_effect_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_WI_FI_tr2(handle);
			} 
		}
	}
}

/* The reactions of state EXTRUSION. */
static void prefix_react_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION(Prefix* handle)
{
	/* The reactions of state EXTRUSION. */
	if (prefix_check_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION_tr0(handle);
	}  else
	{
		if (prefix_check_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION_tr1_tr1(handle) == bool_true)
		{ 
			prefix_effect_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION_tr1(handle);
		}  else
		{
			if (prefix_check_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION_tr2_tr2(handle) == bool_true)
			{ 
				prefix_effect_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION_tr2(handle);
			} 
		}
	}
}

/* The reactions of state CANCELAR. */
static void prefix_react_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_CANCELAR(Prefix* handle)
{
	/* The reactions of state CANCELAR. */
	if (prefix_check_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_CANCELAR_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_CANCELAR_tr0(handle);
	}  else
	{
		if (prefix_check_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_CANCELAR_tr1_tr1(handle) == bool_true)
		{ 
			prefix_effect_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_CANCELAR_tr1(handle);
		}  else
		{
			if (prefix_check_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_CANCELAR_tr2_tr2(handle) == bool_true)
			{ 
				prefix_effect_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_CANCELAR_tr2(handle);
			} 
		}
	}
}

/* The reactions of state SETEAR_TEMP. */
static void prefix_react_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_SETEAR_TEMP(Prefix* handle)
{
	/* The reactions of state SETEAR_TEMP. */
	if (prefix_check_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_SETEAR_TEMP_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_SETEAR_TEMP_tr0(handle);
	}  else
	{
		if (prefix_check_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_SETEAR_TEMP_tr1_tr1(handle) == bool_true)
		{ 
			prefix_effect_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_SETEAR_TEMP_tr1(handle);
		}  else
		{
			if (prefix_check_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_SETEAR_TEMP_tr2_tr2(handle) == bool_true)
			{ 
				prefix_effect_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_SETEAR_TEMP_tr2(handle);
			} 
		}
	}
}

/* The reactions of state ENFRIAR. */
static void prefix_react_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR(Prefix* handle)
{
	/* The reactions of state ENFRIAR. */
	if (prefix_check_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR_tr0(handle);
	}  else
	{
		if (prefix_check_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR_tr1_tr1(handle) == bool_true)
		{ 
			prefix_effect_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR_tr1(handle);
		}  else
		{
			if (prefix_check_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR_tr2_tr2(handle) == bool_true)
			{ 
				prefix_effect_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR_tr2(handle);
			} 
		}
	}
}

/* The reactions of state CANCELAR. */
static void prefix_react_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_CANCELAR(Prefix* handle)
{
	/* The reactions of state CANCELAR. */
	if (prefix_check_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_CANCELAR_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_CANCELAR_tr0(handle);
	}  else
	{
		if (prefix_check_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_CANCELAR_tr1_tr1(handle) == bool_true)
		{ 
			prefix_effect_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_CANCELAR_tr1(handle);
		}  else
		{
			if (prefix_check_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_CANCELAR_tr2_tr2(handle) == bool_true)
			{ 
				prefix_effect_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_CANCELAR_tr2(handle);
			} 
		}
	}
}

/* The reactions of state START_EXTRUSION. */
static void prefix_react_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION(Prefix* handle)
{
	/* The reactions of state START_EXTRUSION. */
	if (prefix_check_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION_tr0(handle);
	}  else
	{
		if (prefix_check_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION_tr1_tr1(handle) == bool_true)
		{ 
			prefix_effect_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION_tr1(handle);
		}  else
		{
			if (prefix_check_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION_tr2_tr2(handle) == bool_true)
			{ 
				prefix_effect_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_EXTRUSION_tr2(handle);
			} 
		}
	}
}

/* The reactions of state STOP_EXTRUSION. */
static void prefix_react_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION(Prefix* handle)
{
	/* The reactions of state STOP_EXTRUSION. */
	if (prefix_check_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION_tr0(handle);
	}  else
	{
		if (prefix_check_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION_tr1_tr1(handle) == bool_true)
		{ 
			prefix_effect_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION_tr1(handle);
		}  else
		{
			if (prefix_check_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION_tr2_tr2(handle) == bool_true)
			{ 
				prefix_effect_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION_tr2(handle);
			} 
		}
	}
}

/* The reactions of state START_RETRACT. */
static void prefix_react_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT(Prefix* handle)
{
	/* The reactions of state START_RETRACT. */
	if (prefix_check_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT_tr0(handle);
	}  else
	{
		if (prefix_check_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT_tr1_tr1(handle) == bool_true)
		{ 
			prefix_effect_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT_tr1(handle);
		}  else
		{
			if (prefix_check_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT_tr2_tr2(handle) == bool_true)
			{ 
				prefix_effect_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_START_RETRACT_tr2(handle);
			} 
		}
	}
}

/* The reactions of state SELEC_TEMP. */
static void prefix_react_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP(Prefix* handle)
{
	/* The reactions of state SELEC_TEMP. */
	if (prefix_check_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP_tr0(handle);
	}  else
	{
		if (prefix_check_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP_tr1_tr1(handle) == bool_true)
		{ 
			prefix_effect_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP_tr1(handle);
		}  else
		{
			if (prefix_check_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP_tr2_tr2(handle) == bool_true)
			{ 
				prefix_effect_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP_tr2(handle);
			} 
		}
	}
}

/* The reactions of state MENU_WIFI. */
static void prefix_react_LCD_MENU_WIFI(Prefix* handle)
{
	/* The reactions of state MENU_WIFI. */
	if (prefix_check_LCD_MENU_WIFI_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_LCD_MENU_WIFI_tr0(handle);
	} 
}

/* The reactions of state STOP. */
static void prefix_react_PUENTE_H_STOP(Prefix* handle)
{
	/* The reactions of state STOP. */
	if (prefix_check_PUENTE_H_STOP_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_PUENTE_H_STOP_tr0(handle);
	}  else
	{
		if (prefix_check_PUENTE_H_STOP_tr1_tr1(handle) == bool_true)
		{ 
			prefix_effect_PUENTE_H_STOP_tr1(handle);
		} 
	}
}

/* The reactions of state H_ROTACION_HORARIO. */
static void prefix_react_PUENTE_H_H_ROTACION_HORARIO(Prefix* handle)
{
	/* The reactions of state H_ROTACION_HORARIO. */
	if (prefix_check_PUENTE_H_H_ROTACION_HORARIO_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_PUENTE_H_H_ROTACION_HORARIO_tr0(handle);
	}  else
	{
		if (prefix_check_PUENTE_H_H_ROTACION_HORARIO_tr1_tr1(handle) == bool_true)
		{ 
			prefix_effect_PUENTE_H_H_ROTACION_HORARIO_tr1(handle);
		} 
	}
}

/* The reactions of state CONFIGURAR. */
static void prefix_react_PUENTE_H_CONFIGURAR(Prefix* handle)
{
	/* The reactions of state CONFIGURAR. */
	if (prefix_check_PUENTE_H_CONFIGURAR_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_PUENTE_H_CONFIGURAR_tr0(handle);
	} 
}

/* The reactions of state H_RETRACT. */
static void prefix_react_PUENTE_H_H_RETRACT(Prefix* handle)
{
	/* The reactions of state H_RETRACT. */
	if (prefix_check_PUENTE_H_H_RETRACT_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_PUENTE_H_H_RETRACT_tr0(handle);
	}  else
	{
		if (prefix_check_PUENTE_H_H_RETRACT_tr1_tr1(handle) == bool_true)
		{ 
			prefix_effect_PUENTE_H_H_RETRACT_tr1(handle);
		} 
	}
}

/* The reactions of state TEMP_APAGADO. */
static void prefix_react_x_TEMP_APAGADO(Prefix* handle)
{
	/* The reactions of state TEMP_APAGADO. */
	if (prefix_check_x_TEMP_APAGADO_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_x_TEMP_APAGADO_tr0(handle);
	} 
}

/* The reactions of state TEMP_CONTROL. */
static void prefix_react_x_TEMP_CALENTAR_EJECUTAR_CONTROL_TEMP_CONTROL(Prefix* handle)
{
	/* The reactions of state TEMP_CONTROL. */
	if (prefix_check_x_TEMP_CALENTAR_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_x_TEMP_CALENTAR_tr0(handle);
	}  else
	{
		if (prefix_check_x_TEMP_CALENTAR_EJECUTAR_CONTROL_TEMP_CONTROL_tr0_tr0(handle) == bool_true)
		{ 
			prefix_effect_x_TEMP_CALENTAR_EJECUTAR_CONTROL_TEMP_CONTROL_tr0(handle);
		} 
	}
}

/* The reactions of state TEMP_ENVIAR_UART. */
static void prefix_react_x_TEMP_CALENTAR_ENVIAR_DATOS_TEMP_ENVIAR_UART(Prefix* handle)
{
	/* The reactions of state TEMP_ENVIAR_UART. */
	if (prefix_check_x_TEMP_CALENTAR_ENVIAR_DATOS_TEMP_ENVIAR_UART_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_x_TEMP_CALENTAR_ENVIAR_DATOS_TEMP_ENVIAR_UART_tr0(handle);
	} 
}

/* The reactions of state TEMP_CONF. */
static void prefix_react_x_TEMP_CONF(Prefix* handle)
{
	/* The reactions of state TEMP_CONF. */
	if (prefix_check_x_TEMP_CONF_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_x_TEMP_CONF_tr0(handle);
	} 
}

/* The reactions of state UART_SEND_STATUS. */
static void prefix_react_UART_UART_SEND_STATUS(Prefix* handle)
{
	/* The reactions of state UART_SEND_STATUS. */
	if (prefix_check_UART_UART_SEND_STATUS_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_UART_UART_SEND_STATUS_tr0(handle);
	} 
}

/* Default react sequence for initial entry  */
static void prefix_react_BOTON_DEL_ENCODER__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_BOTON_DEL_ENCODER_NO_OPRIMIDO_default(handle);
}

/* Default react sequence for initial entry  */
static void prefix_react_ENCODER__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_ENCODER_REPOSO_default(handle);
}

/* Default react sequence for initial entry  */
static void prefix_react_LCD__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_LCD_MENU_PRINCIPAL_default(handle);
}

/* Default react sequence for initial entry  */
static void prefix_react_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP_default(handle);
}

/* Default react sequence for initial entry  */
static void prefix_react_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_ENFRIAR_default(handle);
}

/* Default react sequence for initial entry  */
static void prefix_react_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_EXTRUSION_default(handle);
}

/* Default react sequence for initial entry  */
static void prefix_react_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_LCD_MENU_SET_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_SET_TEMP_SELEC_TEMP_default(handle);
}

/* Default react sequence for initial entry  */
static void prefix_react_PUENTE_H__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_PUENTE_H_CONFIGURAR_default(handle);
}

/* Default react sequence for initial entry  */
static void prefix_react_x__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_x_TEMP_CONF_default(handle);
}

/* Default react sequence for initial entry  */
static void prefix_react_x_TEMP_CALENTAR_EJECUTAR_CONTROL__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_x_TEMP_CALENTAR_EJECUTAR_CONTROL_TEMP_CONTROL_default(handle);
}

/* Default react sequence for initial entry  */
static void prefix_react_x_TEMP_CALENTAR_ENVIAR_DATOS__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_x_TEMP_CALENTAR_ENVIAR_DATOS_TEMP_ENVIAR_UART_default(handle);
}

/* Default react sequence for initial entry  */
static void prefix_react_UART__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_UART_UART_SEND_STATUS_default(handle);
}


