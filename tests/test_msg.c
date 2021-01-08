#include <stdio.h>
#include <stdlib.h>
#include "msg.h"
#include "perf.h"

int main() {
    CDN_ETH_TIME_BEGIN(0);
    system("clear");
    ERROR("This is a error message");
    WARNING("This is a warning message");
    INFO("This is a Info message");
    DEBUG("This is a debug message");
    CDN_ETH_TIME_END(0, "just checking");
    return 0;
}
