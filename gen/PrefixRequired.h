
#ifndef PREFIXREQUIRED_H_
#define PREFIXREQUIRED_H_

#include "sc_types.h"
#include "Prefix.h"

#ifdef __cplusplus
extern "C"
{
#endif 

/*! \file This header defines prototypes for all functions that are required by the state machine implementation.

This is a state machine uses time events which require access to a timing service. Thus the function prototypes:
	- prefix_setTimer and
	- prefix_unsetTimer
are defined.

This state machine makes use of operations declared in the state machines interface or internal scopes. Thus the function prototypes:
	- prefixIface_opStart_puente_h
	- prefixIface_opStop_puente_h
	- prefixIface_opConfig_puente_h
	- prefixIface_opRetract_puente_h
	- prefixIface_opMostrar_msj
	- prefixIface_opMostrar_num
	- prefixIface_opConfig_control_temp
	- prefixIface_opApagar_control_temp
	- prefixIface_opControlar_temp
	- prefixIface_opEnviar_UART
	- prefixInternal_opSend_Status
are defined.

These functions will be called during a 'run to completion step' (runCycle) of the statechart. 
There are some constraints that have to be considered for the implementation of these functions:
	- never call the statechart API functions from within these functions.
	- make sure that the execution time is as short as possible.
 
*/
extern void prefixIface_opStart_puente_h(const Prefix* handle);
extern void prefixIface_opStop_puente_h(const Prefix* handle);
extern void prefixIface_opConfig_puente_h(const Prefix* handle);
extern void prefixIface_opRetract_puente_h(const Prefix* handle);
extern void prefixIface_opMostrar_msj(const Prefix* handle, const sc_string Mensaje, const sc_integer fil, const sc_integer col);
extern void prefixIface_opMostrar_num(const Prefix* handle, const sc_integer Numero, const sc_integer fil, const sc_integer col);
extern void prefixIface_opConfig_control_temp(const Prefix* handle);
extern void prefixIface_opApagar_control_temp(const Prefix* handle);
extern sc_integer prefixIface_opControlar_temp(const Prefix* handle, const sc_integer ref);
extern void prefixIface_opEnviar_UART(const Prefix* handle, const sc_integer num);

extern void prefixInternal_opSend_Status(const Prefix* handle, const sc_integer st, const sc_integer temp, const sc_integer setpoint);


/*!
 * This is a timed state machine that requires timer services
 */ 

/*! This function has to set up timers for the time events that are required by the state machine. */
/*! 
	This function will be called for each time event that is relevant for a state when a state will be entered.
	\param evid An unique identifier of the event.
	\time_ms The time in milli seconds
	\periodic Indicates the the time event must be raised periodically until the timer is unset 
*/
extern void prefix_setTimer(Prefix* handle, const sc_eventid evid, const sc_integer time_ms, const sc_boolean periodic);

/*! This function has to unset timers for the time events that are required by the state machine. */
/*! 
	This function will be called for each time event taht is relevant for a state when a state will be left.
	\param evid An unique identifier of the event.
*/
extern void prefix_unsetTimer(Prefix* handle, const sc_eventid evid);



#ifdef __cplusplus
}
#endif 

#endif /* PREFIXREQUIRED_H_ */
