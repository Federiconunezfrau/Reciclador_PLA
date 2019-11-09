
#ifndef PREFIX_H_
#define PREFIX_H_

#include "sc_types.h"
		
#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'prefix'.
*/

/*! Enumeration of all states */ 
typedef enum
{
	Prefix_BOTON_DEL_ENCODER_DEBOUNCE,
	Prefix_BOTON_DEL_ENCODER_NO_OPRIMIDO,
	Prefix_BOTON_DEL_ENCODER_OPRIMIDO,
	Prefix_BOTON_DEL_ENCODER_VALIDACION,
	Prefix_ENCODER_REPOSO,
	Prefix_ENCODER_ROTACION_DERECHA,
	Prefix_ENCODER_ROTACION_IZQUIERDA,
	Prefix_LCD_MENU_PRINCIPAL,
	Prefix_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_MOTORES,
	Prefix_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_TEMP,
	Prefix_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_CONF_WI_FI,
	Prefix_LCD_MENU_PRINCIPAL_MEMSAJE_MOSTRADO_EN_DISPLAY_MENU_PRINCIPAL_EXTRUSION,
	Prefix_LCD_MENU_CONF_TEMP,
	Prefix_LCD_MENU_CONF_TEMP_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_TEMP_CANCELAR,
	Prefix_LCD_MENU_CONF_MOTORES,
	Prefix_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_CANCELAR,
	Prefix_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_ROTAR_MOTOR_EXTRUSION,
	Prefix_LCD_MENU_CONF_MOTORES_MENSAJE_MOSTRADO_EN_DISPLAY_CONF_MOTORES_STOP_MOTOR_EXTRUSION,
	Prefix_PUENTE_H_STOP,
	Prefix_PUENTE_H_H_ROTACION_HORARIO,
	Prefix_PUENTE_H_CONFIGURAR,
	Prefix_last_state
} PrefixStates;

/*! Type definition of the data structure for the PrefixIface interface scope. */
typedef struct
{
	sc_boolean evEnc_rot_derecha_raised;
	sc_boolean evEnc_rot_izquierda_raised;
	sc_boolean evEnc_boton_raised;
	sc_boolean evTECXNoOprimido_raised;
	sc_boolean evTECXOprimido_raised;
	sc_boolean evPuente_h_alto_raised;
	sc_boolean evPuente_h_horario_raised;
	sc_boolean evPuente_h_antihorario_raised;
	sc_boolean evConf_Ready_raised;
} PrefixIface;

/* Declaration of constants for scope PrefixIface. */
extern const sc_integer PREFIX_PREFIXIFACE_MAX_DER_COUNT;
extern const sc_integer PREFIX_PREFIXIFACE_MAX_IZQ_COUNT;
extern const sc_integer PREFIX_PREFIXIFACE_TRUE_ID;
extern const sc_integer PREFIX_PREFIXIFACE_FALSE_ID;
extern const sc_boolean PREFIX_PREFIXIFACE_HORARIO;
extern const sc_boolean PREFIX_PREFIXIFACE_ANTIHORARIO;
extern const sc_string PREFIX_PREFIXIFACE_MSJ_MENU_PRINCIPAL;
extern const sc_string PREFIX_PREFIXIFACE_MSJ_MENU_CONF_MOTORES;
extern const sc_string PREFIX_PREFIXIFACE_MSJ_MENU_CONF_WI_FI;
extern const sc_string PREFIX_PREFIXIFACE_MSJ_MENU_EXTRUIR;
extern const sc_string PREFIX_PREFIXIFACE_MSJ_MENU_CONF_TEMP;
extern const sc_string PREFIX_PREFIXIFACE_MSJ_MENU_CANCELAR;
extern const sc_string PREFIX_PREFIXIFACE_MSJ_MENU_MOTOR_EXTRUSION;
extern const sc_string PREFIX_PREFIXIFACE_MSJ_MENU_MOTOR_EXTRUSION_STOP;

/*! Type definition of the data structure for the PrefixInternal interface scope. */
typedef struct
{
	sc_integer viEnc_count_der;
	sc_integer viEnc_count_izq;
	sc_integer viEnc_volver;
	sc_integer viTecla;
	sc_boolean siDespl_derecha_raised;
	sc_boolean siDespl_izquierda_raised;
	sc_boolean siEntrar_raised;
	sc_boolean siStop_puente_h_raised;
	sc_boolean siStart_puente_h_raised;
} PrefixInternal;

/*! Type definition of the data structure for the PrefixTimeEvents interface scope. */
typedef struct
{
	sc_boolean prefix_BOTON_DEL_ENCODER_DEBOUNCE_tev0_raised;
} PrefixTimeEvents;


/*! Define dimension of the state configuration vector for orthogonal states. */
#define PREFIX_MAX_ORTHOGONAL_STATES 4

/*! 
 * Type definition of the data structure for the Prefix state machine.
 * This data structure has to be allocated by the client code. 
 */
typedef struct
{
	PrefixStates stateConfVector[PREFIX_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	PrefixIface iface;
	PrefixInternal internal;
	PrefixTimeEvents timeEvents;
} Prefix;

/*! Initializes the Prefix state machine data structures. Must be called before first usage.*/
extern void prefix_init(Prefix* handle);

/*! Activates the state machine */
extern void prefix_enter(Prefix* handle);

/*! Deactivates the state machine */
extern void prefix_exit(Prefix* handle);

/*! Performs a 'run to completion' step. */
extern void prefix_runCycle(Prefix* handle);

/*! Raises a time event. */
extern void prefix_raiseTimeEvent(const Prefix* handle, sc_eventid evid);

/*! Raises the in event 'evEnc_rot_derecha' that is defined in the default interface scope. */ 
extern void prefixIface_raise_evEnc_rot_derecha(Prefix* handle);

/*! Raises the in event 'evEnc_rot_izquierda' that is defined in the default interface scope. */ 
extern void prefixIface_raise_evEnc_rot_izquierda(Prefix* handle);

/*! Raises the in event 'evEnc_boton' that is defined in the default interface scope. */ 
extern void prefixIface_raise_evEnc_boton(Prefix* handle);

/*! Raises the in event 'evTECXNoOprimido' that is defined in the default interface scope. */ 
extern void prefixIface_raise_evTECXNoOprimido(Prefix* handle);

/*! Raises the in event 'evTECXOprimido' that is defined in the default interface scope. */ 
extern void prefixIface_raise_evTECXOprimido(Prefix* handle);

/*! Gets the value of the variable 'MAX_DER_COUNT' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_mAX_DER_COUNT(const Prefix* handle);
/*! Gets the value of the variable 'MAX_IZQ_COUNT' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_mAX_IZQ_COUNT(const Prefix* handle);
/*! Gets the value of the variable 'TRUE' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_tRUE(const Prefix* handle);
/*! Gets the value of the variable 'FALSE' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_fALSE(const Prefix* handle);
/*! Raises the in event 'evPuente_h_alto' that is defined in the default interface scope. */ 
extern void prefixIface_raise_evPuente_h_alto(Prefix* handle);

/*! Raises the in event 'evPuente_h_horario' that is defined in the default interface scope. */ 
extern void prefixIface_raise_evPuente_h_horario(Prefix* handle);

/*! Raises the in event 'evPuente_h_antihorario' that is defined in the default interface scope. */ 
extern void prefixIface_raise_evPuente_h_antihorario(Prefix* handle);

/*! Raises the in event 'evConf_Ready' that is defined in the default interface scope. */ 
extern void prefixIface_raise_evConf_Ready(Prefix* handle);

/*! Gets the value of the variable 'horario' that is defined in the default interface scope. */ 
extern const sc_boolean prefixIface_get_horario(const Prefix* handle);
/*! Gets the value of the variable 'antihorario' that is defined in the default interface scope. */ 
extern const sc_boolean prefixIface_get_antihorario(const Prefix* handle);
/*! Gets the value of the variable 'Msj_menu_principal' that is defined in the default interface scope. */ 
extern const sc_string prefixIface_get_msj_menu_principal(const Prefix* handle);
/*! Gets the value of the variable 'Msj_menu_conf_motores' that is defined in the default interface scope. */ 
extern const sc_string prefixIface_get_msj_menu_conf_motores(const Prefix* handle);
/*! Gets the value of the variable 'Msj_menu_conf_Wi_Fi' that is defined in the default interface scope. */ 
extern const sc_string prefixIface_get_msj_menu_conf_Wi_Fi(const Prefix* handle);
/*! Gets the value of the variable 'Msj_menu_extruir' that is defined in the default interface scope. */ 
extern const sc_string prefixIface_get_msj_menu_extruir(const Prefix* handle);
/*! Gets the value of the variable 'Msj_menu_conf_temp' that is defined in the default interface scope. */ 
extern const sc_string prefixIface_get_msj_menu_conf_temp(const Prefix* handle);
/*! Gets the value of the variable 'Msj_menu_cancelar' that is defined in the default interface scope. */ 
extern const sc_string prefixIface_get_msj_menu_cancelar(const Prefix* handle);
/*! Gets the value of the variable 'Msj_menu_motor_extrusion' that is defined in the default interface scope. */ 
extern const sc_string prefixIface_get_msj_menu_motor_extrusion(const Prefix* handle);
/*! Gets the value of the variable 'Msj_menu_motor_extrusion_stop' that is defined in the default interface scope. */ 
extern const sc_string prefixIface_get_msj_menu_motor_extrusion_stop(const Prefix* handle);

/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean prefix_isActive(const Prefix* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean prefix_isFinal(const Prefix* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean prefix_isStateActive(const Prefix* handle, PrefixStates state);

#ifdef __cplusplus
}
#endif 

#endif /* PREFIX_H_ */
