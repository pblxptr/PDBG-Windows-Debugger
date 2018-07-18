#ifndef DEBUGGER_STARTED
#define DEBUGGER_STARTED 7001
#endif

#ifndef DEBUGGER_ERROR_OCCURED
#define DEBUGGER_ERROR_OCCURED 7002
#endif

#ifndef SINGLE_STEP_SET
#define SINGLE_STEP_SET 7003
#endif

#ifndef BREAKPOINT_ADDED
#define BREAKPOINT_ADDED 7004
#endif

#ifndef BREAKPOINT_REMOVED
#define BREAKPOINT_REMOVED 7005
#endif

//DEBUG Events
#ifndef PROCESS_CREATED
#define PROCESS_CREATED 8001
#endif

#ifndef PROCESS_EXITED
#define PROCESS_EXITED 8002
#endif

#ifndef THREAD_CREATED
#define THREAD_CREATED 8003
#endif

#ifndef THREAD_EXITED
#define THREAD_EXITED 8004
#endif

#ifndef DLL_LOADED
#define DLL_LOADED 8005
#endif

#ifndef DLL_UNLOADED
#define DLL_UNLOADED 8006
#endif

#ifndef DEBUG_STRING_RECEIVED
#define DEBUG_STRING_RECEIVED 8007
#endif



///////////////////////////////////////////////////////////
// ERROR CODE ////////////////////////////////////////////
/////////////////////////////////////////////////////////

#ifndef CANNOT_CREATE_PROCESS
#define CANNOT_CREATE_PROCESS 9001
#endif

#ifndef THREAD_NOT_EXIST
#define THREAD_NOT_EXIST 9002
#endif

#ifndef CANNOT_SET_CONTEXT
#define CANNOT_SET_CONTEXT 9003
#endif

#ifndef CANNOT_GET_CONTEXT
#define CANNOT_GET_CONTEXT 9004
#endif

#ifndef CANNOT_READ_PROCESS_MEMORY
#define CANNOT_READ_PROCESS_MEMORY 9005
#endif

#ifndef CANNOT_WRITE_PROCESS_MEMORY
#define CANNOT_WRITE_PROCESS_MEMORY 9005
#endif

#ifndef BREAKPOINT_NOT_EXIST
#define BREAKPOINT_NOT_EXIST 9006
#endif