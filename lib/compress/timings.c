#include "../timings.h"
#include <stdio.h>

void TimeStampStopMeasure(struct timespec *start_time,const char * const seg_path, const char *const measure_name){
    FILE *fp = fopen("/home/mike/zstd_log/zstd.log", "ab");
    if (fp != NULL)
    {
        char buf[10000];
        sprintf(buf, "%s %s\n", seg_path, measure_name);
        fputs(buf, fp);
        fclose(fp);
    }
}
