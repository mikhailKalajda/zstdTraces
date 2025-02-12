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
void TimeStampStopMeasure(struct timespec *start_time, const char * const seg_path, const char *measure_name);
#define TIMING_START(measure)  {struct timespec _start_timing ## measure={0,0}; clock_gettime(CLOCK_REALTIME, &_start_timing ## measure);
#define TIMING_STOP(path, measure) TimeStampStopMeasure(&_start_timing ## measure, path, #measure);}
#else
#define TIMING_START(measure)
#define TIMING_STOP(path, measure)
#endif

