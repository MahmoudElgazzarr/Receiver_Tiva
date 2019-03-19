/*
 * UART.h
 *
 *  Created on: Mar 12, 2019
 *      Author: AVE-LAP-016
 */

#ifndef UART_H_
#define UART_H_


#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/uart.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"

extern volatile uint8_t data_recived_flag;
void uart0_init(void);
void UART0_send(uint8_t ch);
uint8_t UART0_receive(void);
void UART0_disable();

void UART5_init(void);
void UART5_send(uint8_t ch);
uint8_t UART5_receive(void);
void UART5_disable();

#endif /* UART_H_ */
