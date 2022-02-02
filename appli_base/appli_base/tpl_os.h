/**
 * @file tpl_os.h
 *
 * @section File description
 *
 * This file gathers system call declarations.
 *
 * Generated from application my_cpu
 * Automatically generated by goil on Wed Feb  2 11:05:34 2022
 * from root OIL file appli_base.oil
 *
 * @section File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#ifndef TPL_OS_H
#define TPL_OS_H


#ifdef __cplusplus
extern "C" {
#endif

#include "tpl_os_definitions.h"
#include "tpl_os_application_def.h"
#include "tpl_os_error.h"

/*--------------------------------------------------------------------------*
 * os system calls.
 * corresponding kernel implementation is in files
 * tpl_os_os_kernel.h and tpl_os_os_kernel.c
 * tpl_os_os.h and tpl_os_os.c
 *--------------------------------------------------------------------------*/
#include "tpl_os_os.h"

/*
 * GetActiveApplicationMode
 *
 * This service returns the current application mode. It may be used to 
 * write mode dependent code. 
 *
 * Return value:
 * The active application mode 
 */
FUNC(AppModeType, OS_CODE) GetActiveApplicationMode(void);

/*
 * ShutdownOS
 *
 * The user can call this system service to abort the overall system 
 * (e.g. emergency off). The operating system also calls this function 
 * internally, if it has reached an undefined internal state and is no 
 * longer ready to run. 
 *
 * error: The error that occured 
 */
FUNC(void, OS_CODE) ShutdownOS(
  CONST(StatusType, AUTOMATIC) error);


/*--------------------------------------------------------------------------*
 * interrupt system calls.
 * corresponding kernel implementation is in files
 * tpl_os_interrupt_kernel.h and tpl_os_interrupt_kernel.c
 *--------------------------------------------------------------------------*/
#include "tpl_os_interrupt.h"

/*
 * EnableAllInterrupts
 *
 * This service restores the state saved by DisableAllInterrupts. 
 */
FUNC(void, OS_CODE) EnableAllInterrupts(void);

/*
 * DisableAllInterrupts
 *
 * This service disables all interrupts for which the hardware supports 
 * disabling. The state before is saved for the EnableAllInterrupts call. 
 */
FUNC(void, OS_CODE) DisableAllInterrupts(void);

/*
 * ResumeAllInterrupts
 *
 * This service restores the recognition status of all interrupts saved 
 * by the SuspendAllInterrupts service. 
 */
FUNC(void, OS_CODE) ResumeAllInterrupts(void);

/*
 * SuspendAllInterrupts
 *
 * This service saves the recognition status of all interrupts and 
 * disables all interrupts for which the hardware supports disabling. 
 */
FUNC(void, OS_CODE) SuspendAllInterrupts(void);

/*
 * ResumeOSInterrupts
 *
 * This service restores the recognition status of interrupts saved by 
 * the SuspendOSInterrupts service. 
 */
FUNC(void, OS_CODE) ResumeOSInterrupts(void);

/*
 * SuspendOSInterrupts
 *
 * This service saves the recognition status of interrupts of category 2 
 * and disables the recognition of these interrupts. 
 */
FUNC(void, OS_CODE) SuspendOSInterrupts(void);


/*--------------------------------------------------------------------------*
 * task system calls.
 * corresponding kernel implementation is in files
 * tpl_os_task_kernel.h and tpl_os_task_kernel.c
 *--------------------------------------------------------------------------*/
#include "tpl_os_task.h"

/*
 * ActivateTask
 *
 * Activate a task 
 *
 * task_id: The identifier of the task to activate 
 *
 * Return value:
 * E_OK: No error (Standard & Extended) 
 * E_OS_LIMIT: Too many activations of <task_id> (Standard & Extended) 
 * E_OS_ID: <task_id> is invalid (Extended) 
 */
FUNC(StatusType, OS_CODE) ActivateTask(
  CONST(TaskType, AUTOMATIC) task_id);

/*
 * TerminateTask
 *
 * Terminate the calling task 
 *
 * Return value:
 * E_OS_RESOURCE: The calling task still occupies a resource (Extended) 
 * E_OS_CALLEVEL: Call at interrupt level (Extended) 
 */
FUNC(StatusType, OS_CODE) TerminateTask(void);

/*
 * ChainTask
 *
 * Terminate the calling task and activate task task_id 
 *
 * task_id: The identifier of the task to chain to 
 *
 * Return value:
 * E_OS_LIMIT: Too many activations of <task_id> (Standard & Extended) 
 * E_OS_ID: <task_id> is invalid (Extended) 
 * E_OS_RESOURCE: The calling task still occupies a resource (Extended) 
 * E_OS_CALLEVEL: Call at interrupt level (Extended) 
 */
FUNC(StatusType, OS_CODE) ChainTask(
  CONST(TaskType, AUTOMATIC) task_id);

/*
 * Schedule
 *
 * Call the scheduler 
 *
 * Return value:
 * E_OK: No error (Standard & Extended) 
 * E_OS_RESOURCE: The calling task still occupies a resource (Extended) 
 * E_OS_CALLEVEL: Call at interrupt level (Extended) 
 */
FUNC(StatusType, OS_CODE) Schedule(void);

/*
 * GetTaskID
 *
 * Get the id of the calling task 
 *
 * task_id: A pointer to the var where the identifier of the task will be 
 *           stored 
 *
 * Return value:
 * E_OK: No error (Standard & Extended) 
 */
FUNC(StatusType, OS_CODE) GetTaskID(
  VAR(TaskRefType, AUTOMATIC) task_id);

/*
 * GetTaskState
 *
 * Get the task state of a task 
 *
 * task_id: The identifier of the task 
 *
 * state: A pointer to the var where the state of the task will be stored 
 *
 * Return value:
 * E_OK: No error (Standard & Extended) 
 * E_OS_ID: <alarm_id> is invalid (Extended) 
 */
FUNC(StatusType, OS_CODE) GetTaskState(
  CONST(TaskType, AUTOMATIC) task_id,
  VAR(TaskStateRefType, AUTOMATIC) state);


/*--------------------------------------------------------------------------*
 * resource system calls.
 * corresponding kernel implementation is in files
 * tpl_os_resource_kernel.h and tpl_os_resource_kernel.c
 *--------------------------------------------------------------------------*/
#include "tpl_os_resource.h"

/*
 * GetResource
 *
 * Get resource res_id. As a result, the priority of the caller may be 
 * raised to the priority of the resource if the latter is higher 
 *
 * res_id: The id of the resource to get. 
 *
 * Return value:
 * E_OK: No error (Standard & Extended) 
 * E_OS_ID: <res_id> is invalid (Extended) 
 */
FUNC(StatusType, OS_CODE) GetResource(
  CONST(ResourceType, AUTOMATIC) res_id);

/*
 * ReleaseResource
 *
 * Release resource res_id. The priority of the caller returns to the 
 * priority it had before getting the resource 
 *
 * res_id: The id of the resource to release. 
 *
 * Return value:
 * E_OK: No error (Standard & Extended) 
 * E_OS_ID: <res_id> is invalid (Extended) 
 * E_OS_ACCESS: Attempt to get a resource which is already occupied by 
 *     any task or ISR, or the statically assigned priority of the 
 *     calling task or interrupt routine is higher than the calculated 
 *     ceiling priority (Extended) 
 */
FUNC(StatusType, OS_CODE) ReleaseResource(
  CONST(ResourceType, AUTOMATIC) res_id);


/*--------------------------------------------------------------------------*
 * event system calls.
 * corresponding kernel implementation is in files
 * tpl_os_event_kernel.h and tpl_os_event_kernel.c
 *--------------------------------------------------------------------------*/
#include "tpl_os_event.h"

/*
 * SetEvent
 *
 * The events of task <task_id> are set according to the event mask 
 * <event>. Calling SetEvent causes the task <task_id> to be transferred 
 * to the ready state, if it was waiting for at least one of the events 
 * specified in <event> 
 *
 * task_id: Reference to the task for which one or several events are to 
 *           be set. 
 *
 * event: Mask of the events to be set 
 *
 * Return value:
 * E_OK: No error (Standard & Extended) 
 * E_OS_ID: <task_id> is invalid (Extended) 
 * E_OS_ACCESS: <task_id> task is not an extended task (Extended) 
 * E_OS_STATE: Events can not be set because <task_id> is in the 
 *     suspended state (Extended) 
 */
FUNC(StatusType, OS_CODE) SetEvent(
  CONST(TaskType, AUTOMATIC) task_id,
  CONST(EventMaskType, AUTOMATIC) event);

/*
 * ClearEvent
 *
 * The events of the extended task calling ClearEvent are cleared 
 * according to the event mask <event>. 
 *
 * event: The event mask to clear. 
 *
 * Return value:
 * E_OK: No error (Standard & Extended) 
 * E_OS_ACCESS: The calling task is not an extended task (Extended) 
 * E_OS_CALLEVEL: Call at interrupt level (Extended) 
 */
FUNC(StatusType, OS_CODE) ClearEvent(
  CONST(EventMaskType, AUTOMATIC) event);

/*
 * GetEvent
 *
 * This service returns the current state of all event bits of the task 
 * <task_id>, not the events that the task is waiting for. The service 
 * may be called from interrupt service routines, task level and some 
 * hook routines. The current status of the event mask of task <task_id> 
 * is copied to <event>. 
 *
 * task_id: Task whose event mask is to be returned. 
 *
 * event: Pointer to the data where the event mask is to be stored. 
 *
 * Return value:
 * E_OK: No error (Standard & Extended) 
 * E_OS_ID: <task_id> is invalid (Extended) 
 * E_OS_ACCESS: <task_id> task is not an extended task (Extended) 
 * E_OS_STATE: Events can not be set because <task_id> is in the 
 *     suspended state (Extended) 
 */
FUNC(StatusType, OS_CODE) GetEvent(
  CONST(TaskType, AUTOMATIC) task_id,
  CONST(EventMaskRefType, AUTOMATIC) event);

/*
 * WaitEvent
 *
 * The state of the calling task is set to waiting, unless at least one 
 * of the events specified in <event> has already been set. 
 *
 * event: Mask of the events waited for. 
 *
 * Return value:
 * E_OK: No error (Standard & Extended) 
 * E_OS_ACCESS: The calling task is not an extended task (Extended) 
 * E_OS_RESOURCE: The calling task still occupies a resource (Extended) 
 * E_OS_CALLEVEL: Call at interrupt level (Extended) 
 */
FUNC(StatusType, OS_CODE) WaitEvent(
  CONST(EventMaskType, AUTOMATIC) event);


/*
 * Objects declared in the OIL/ARXML file
 */
DeclareApplicationMode(std);
DeclareTask(T_1);
DeclareTask(T_2);
DeclareTask(T_3);
DeclareTask(T_master);
DeclareEvent(ev1);
DeclareEvent(ev2);
DeclareEvent(ev3);

#ifdef __cplusplus
}
#endif




/* TPL_OS_H */
#endif

/* End of file tpl_os.h */
