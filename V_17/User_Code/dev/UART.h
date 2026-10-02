/*
 * UART.h
 *
 *  Created on: Jan 26, 2026
 *      Author: JJH
 */

#ifndef INC_UART_H_
#define INC_UART_H_

#include "user_main.h"
#include "stdio.h"
#include <stdarg.h>
#include <string.h>

#define UART		huart1  			// 사용할 UART 핸들러 입력

int UART_print(char *format, ...);

#endif /* INC_UART_H_ */
