#include <stdio.h>
#include <stdlib.h>
#include "msg.h"

int main() {
    system("clear");
    ERROR("This is a error message");
    WARNING("This is a warning message");
    INFO("This is a Info message");
    DEBUG("This is a debug message");
    return 0;
}
