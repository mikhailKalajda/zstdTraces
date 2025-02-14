#pragma once

#define TIMING_ON

#ifdef TIMING_ON
#include <time.h>
#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif
#endif

#ifdef TIMING_ON
void TimeStampStopMeasure(struct timespec *start_time, const char* func_name);
#define TIMING_START  {struct timespec _start_timing={0,0}; clock_gettime(CLOCK_REALTIME, &_start_timing);
#define TIMING_STOP TimeStampStopMeasure(&_start_timing, __func__);}
#define TIMING_RET TimeStampStopMeasure(&_start_timing, __func__);
#else
#define TIMING_START
#define TIMING_STOP
#define TIMING_RET
#endif

