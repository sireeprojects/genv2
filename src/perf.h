#ifndef _PERF_H_
#define _PERF_H_


#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif


#include <stdio.h>
#include <time.h>
#include "msg.h"


double cdn_eth_ts_to_secs(struct timespec* ts) {
    return (double)ts->tv_sec + (double)ts->tv_nsec / 1000000000.0;
}


#define CDN_ETH_TIME_BEGIN(tag) \
    struct timespec start##tag; \
    struct timespec end##tag; \
    double elapsedSeconds##tag; \
    clock_gettime (CLOCK_MONOTONIC, &start##tag);


#define CDN_ETH_TIME_END(tag, str) \
    clock_gettime(CLOCK_MONOTONIC, &end##tag); \
    elapsedSeconds##tag = \
        cdn_eth_ts_to_secs(&end##tag) - \
        cdn_eth_ts_to_secs(&start##tag); \
    INFO("Time Taken for %s (%s): %f", \
        #str, #tag, elapsedSeconds##tag);


#endif
