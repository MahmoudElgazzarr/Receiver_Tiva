/*
 * LCD_Task.c
 *
 *  Created on: Mar 19, 2019
 *      Author: AVE-LAP-040
 */

#include "LCD.h"
#include "LCD_Task.h"
#include "FreeRTOS.h"
#include "task.h"
#include "UART_Task.h"


void init_LCD_Task()
{
    while(1)
    {
    LCD_init();
    vTaskSuspend(NULL);
    }
}

void LCD_Display_Task()
{
    while(1)
    {
    if( Flag_To_LCD == 1)
      {
        Flag_To_LCD = 0;
        LCD_displayChar(data_To_LCD);
      }
        vTaskDelay(250);
    }
}
