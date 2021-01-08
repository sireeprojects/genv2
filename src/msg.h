#ifndef __MSG__
#define __MSG__

#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

#define RST  "\x1B[0m"
#define KRED  "\x1B[1;31m"
#define KGRN  "\x1B[1;32m"
#define KYEL  "\x1B[1;33m"
#define KBLU  "\x1B[1;34m"
#define KMAG  "\x1B[1;35m"
#define KCYN  "\x1B[1;36m"
#define KWHT  "\x1B[1;39m"

#define FRED(...) KRED __VA_ARGS__
#define FGRN(...) KGRN __VA_ARGS__
#define FYEL(...) KYEL __VA_ARGS__
#define FBLU(...) KBLU __VA_ARGS__
#define FMAG(...) KMAG __VA_ARGS__
#define FCYN(...) KCYN __VA_ARGS__
#define FWHT(...) KWHT __VA_ARGS__

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
    printf(FRED("%s",msgBuf)); \
    printf("\n"); \
    fprintf (msgFile, msgBuf); \
    fprintf (msgFile, "\n"); \
}

#define WARNING(...) { \
    sprintf(msgBuf, "WARNING : "); \
    sprintf(msgBuf+10, __VA_ARGS__); \
    printf(FYEL("%s",msgBuf)); \
    printf("\n"); \
    fprintf (msgFile, msgBuf); \
    fprintf (msgFile, "\n"); \
}

#define INFO(...) { \
    sprintf(msgBuf, "INFO    : "); \
    sprintf(msgBuf+10, __VA_ARGS__); \
    printf(FWHT("%s",msgBuf)); \
    printf("\n"); \
    fprintf (msgFile, msgBuf); \
    fprintf (msgFile, "\n"); \
}

#define DEBUG(...) { \
    sprintf(msgBuf, "DEBUG   : "); \
    sprintf(msgBuf+10, __VA_ARGS__); \
    printf(FBLU("%s",msgBuf)); \
    printf("\n"); \
    fprintf (msgFile, msgBuf); \
    fprintf (msgFile, "\n"); \
}

#endif
