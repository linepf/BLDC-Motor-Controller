#include "UART.h"


int UART_print(char *format, ...) {
    char buffer[256];

    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    HAL_UART_Transmit(&UART, (uint8_t*)buffer, strlen(buffer), HAL_MAX_DELAY);

    return 0;
}



