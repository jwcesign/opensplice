#ifndef OS__PROCESS_H
#define OS__PROCESS_H

#include "os_process.h"

void os_processModuleInit(void);
void os_processModuleExit(void);
void os_procCallExitHandlers(void);

#endif /*OS__PROCESS_H*/