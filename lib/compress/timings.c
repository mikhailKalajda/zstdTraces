#include "../timings.h"
#include <stdio.h>
#include <time.h>
#include <sys/types.h>

void TimeStampStopMeasure(struct timespec *start_time, const char* func_name){
    FILE *fp = fopen("/home/mike/zstd_log/zstd.log", "ab");
    if (fp != NULL)
    {
        struct timespec end_time={0,0};
        clock_gettime(CLOCK_REALTIME, &end_time);

        double diff =  (((double)   (end_time.tv_sec) + 1.0e-9*(double)   (end_time.tv_nsec))
                    - ((double)(start_time->tv_sec) + 1.0e-9*(double)(start_time->tv_nsec)));
        //long ldiff = end_time.tv_nsec - start_time->tv_nsec;
        
        char buf[10000];
        sprintf(buf, "%lf\t%s\n", diff, func_name);
        fputs(buf, fp);
        fclose(fp);
    }
}
