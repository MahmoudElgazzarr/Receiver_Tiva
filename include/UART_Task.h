/*
 * UART_Task.h
 *
 *  Created on: Mar 19, 2019
 *      Author: AVE-LAP-040
 */

#ifndef INCLUDE_UART_TASK_H_
#define INCLUDE_UART_TASK_H_


extern volatile int32_t data;
extern volatile uint8_t data_To_LCD;
extern volatile uint8_t data_recived_flag;
extern volatile uint8_t Flag_To_LCD;
void Recive_Task();



#endif /* INCLUDE_UART_TASK_H_ */
