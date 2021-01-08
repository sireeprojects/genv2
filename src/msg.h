#ifndef __MSG__
#define __MSG__

#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

#define RST  "\x1B[0m"
#define ERED  "\x1B[1;31m"
#define EGRN  "\x1B[1;32m"
#define EYEL  "\x1B[1;33m"
#define EBLU  "\x1B[1;34m"
#define EMAG  "\x1B[1;35m"
#define ECYN  "\x1B[1;36m"
#define EWHT  "\x1B[1;39m"

#define FRED(...) ERED __VA_ARGS__
#define FGRN(...) EGRN __VA_ARGS__
#define FYEL(...) EYEL __VA_ARGS__
#define FBLU(...) EBLU __VA_ARGS__
#define FMAG(...) EMAG __VA_ARGS__
#define FCYN(...) ECYN __VA_ARGS__
#define FWHT(...) EWHT __VA_ARGS__

#define BOLD(x) "\x1B[1m" x RST
#define UNDL(x) "\x1B[4m" x RST

char     msgBuf[1000];
uint32_t msgVerbosity;
FILE *   msgFile;

static void __attribute__((constructor, used)) func(void) {
    msgFile = fopen ("run.log", "w");
}

#define ERROR(...) { \
    sprintf(msgBuf, "ERROR   : "); \
    sprintf(msgBuf+10, __VA_ARGS__); \
    printf(FRED("%s" RST,msgBuf)); \
    printf("\n"); \
    fprintf (msgFile, msgBuf); \
    fprintf (msgFile, "\n"); \
}

#define WARNING(...) { \
    sprintf(msgBuf, "WARNING : "); \
    sprintf(msgBuf+10, __VA_ARGS__); \
    printf(FYEL("%s" RST,msgBuf)); \
    printf("\n"); \
    fprintf (msgFile, msgBuf); \
    fprintf (msgFile, "\n"); \
}

#define INFO(...) { \
    sprintf(msgBuf, "INFO    : "); \
    sprintf(msgBuf+10, __VA_ARGS__); \
    printf(FWHT("%s" RST,msgBuf)); \
    printf("\n"); \
    fprintf (msgFile, msgBuf); \
    fprintf (msgFile, "\n"); \
}

#define DEBUG(...) { \
    sprintf(msgBuf, "DEBUG   : "); \
    sprintf(msgBuf+10, __VA_ARGS__); \
    printf(FBLU("%s" RST,msgBuf)); \
    printf("\n"); \
    fprintf (msgFile, msgBuf); \
    fprintf (msgFile, "\n"); \
}

#endif
