#include "../timings.h"
#include <stdio.h>

void TimeStampStopMeasure(struct timespec *start_time,const char * const seg_path, const char *const measure_name){
    FILE *fp = fopen("/home/mike/src/zstd.log", "ab");
    if (fp != NULL)
    {
        fputs(measure_name, fp);
        fclose(fp);
    }
}
