#include <stdio.h>
#include "perf.h"

int main() {
    CDN_ETH_TIME_BEGIN(0);
    int i;
    for (i=0; i<100000000; i++);
    CDN_ETH_TIME_END(0, "just checking");
    return 0;
}
