/*
 * UART_Task.c
 *
 *  Created on: Mar 19, 2019
 *      Author: AVE-LAP-040
 */
#include"FreeRTOS.h"
#include "task.h"
#include "UART5.h"

volatile int32_t data;
volatile uint8_t data_To_LCD;
volatile uint8_t Flag_To_LCD = 0;
void Recive_Task()
{
    while(1)
    {
       data = UART5_receive();
       if(data_recived_flag == 1)
       {
           data_To_LCD = (uint8_t)data;
           data_recived_flag = 0;
           Flag_To_LCD = 1;
       }
       vTaskDelay(20);
    }
}
