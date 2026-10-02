#ifndef INC_UART_H_
#define INC_UART_H_

#include "user_main.h"
#include "stdio.h"
#include <stdarg.h>
#include <string.h>

#define UART		huart1

int UART_print(char *format, ...);

#endif /* INC_UART_H_ */
