#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "configops.h"
#include "metadataops.h"
#include "datatypes.h"
#include "simtimer.h"
#include "StandardConstants.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef enum {
              NEW,
              READY,
              RUNNING,
              EXITING
           } ProcessStates;

typedef enum {
              MEM_START,
              MEM_FAILURE,
              MEM_SUCCESS,
              STATE_CHANGE,
              OP_COMMAND,
              PROCESS_CHANGE,
              PRINT_MESSAGE,
              PROC_END,
              SYS_START,
              SYS_END,
              SIM_END
           } DisplayFlags;

typedef enum {
              ALLOCATE,
              ACCESS
           } MemOpType;

// Function Prototypes
ProcessType *buildPCB( OpCodeType *metaDataMstrPtr, ConfigDataType *configPtr );
ProcessType *clearPCB( ProcessType *localPtr );
OpCodeType *findNextOpCode( ProcessType *process );
ProcessType *findNextProcess( ProcessType *currentProcess, ProcessType *pcbHead, int cpuSchedMode, bool procComplete );
void freeMemBlock( MMU *mmu, ProcessType *process );
void manageDisplay( ProcessType *process, int displayFlag, char *opMessage );
bool manageMemory( ProcessType *process, MMU *mmu, MemOpType memFlag );
void runOpCode( OpCodeType *opCode, int cycleRate );
void runSim( ConfigDataType *configPtr, OpCodeType *metaDataMstrPtr );
void *runTimerHere( void *time );
void setState( ProcessType *process, int state, bool allFlag );
void stateToString( int state , char *stateStr);

#endif  // SIMULATOR_H
