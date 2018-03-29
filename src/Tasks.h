/*
 * Startup.h
 *
 *  Created on: 26 Mar 2018
 *      Author: David
 */

#ifndef SRC_TASKS_H_
#define SRC_TASKS_H_

#include "RepRapFirmware.h"
#include "MessageType.h"

#ifdef RTOS
typedef void *TaskHandle_t;			// copy of the FreeRTOS definition, to avoid having to include the FreeRTOS files here
#endif

void setup();
void loop();

namespace Tasks
{
#ifdef RTOS
	void GetHandlerStackUsage(uint32_t* maxStack, uint32_t* neverUsed);
	void TaskDiagnostics(MessageType mtype, TaskHandle_t ct);
	void CurrentTaskDiagnostics(MessageType mtype);
#else
	void GetStackUsage(uint32_t* currentStack, uint32_t* maxStack, uint32_t* neverUsed);
#endif
}

#endif /* SRC_TASKS_H_ */
