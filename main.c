
#include <FreeRTOS.h>
#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"
#include "Task.h"
#include "Buzzer_Task.h"
#include "led_task.h"
#include "Button_Task.h"
#include "LCD_Task.h"
#include "UART5.h"
#include "UART_Task.h"


//
// The error routine that is called if the driver library encounters an error.
//
//*****************************************************************************
#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
}

#endif

void
vApplicationStackOverflowHook(xTaskHandle *pxTask, char *pcTaskName)
{
    //
    // This function can not return, so loop forever.  Interrupts are disabled
    // on entry to this function, so no processor interrupts will interrupt
    // this loop.
    //
    while(1)
    {
    }
}

//*****************************************************************************
//
// Initialize FreeRTOS and start the initial set of tasks.
//
//*****************************************************************************
int main(void)
{
    UART5_init();
    // Set the clocking to run at 50 MHz from the PLL.
    //
    //ROM_SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ |
                       //SYSCTL_OSC_MAIN);
    UART5_init();
    /*Create init Task For Switch*/
    xTaskCreate(Switch_init_Task, (const portCHAR *)"switch_Init", 128, NULL, 14 , NULL);
    /*Create init Task For LCD*/
    xTaskCreate(init_LCD_Task, (const portCHAR *)"LCD_Init", 128, NULL, 16 , NULL);
    /*Create Init Task For Led*/
    xTaskCreate(LEDS_Task_init, (const portCHAR *)"LED_Init", 128, NULL, 15 , NULL);

    /*Buzzer Task*/
    xTaskCreate(Buzzer_init_Task, (const portCHAR *)"Buzzer_Init", 128, NULL, 13 , NULL);
    xTaskCreate(Buzzer_Task, (const portCHAR *)"Buzzer", 50, NULL, 6 , NULL);


     /*add Task 1 for led*/
     xTaskCreate(LED_Task, (const portCHAR *)"LED1", 50, NULL, 3 , NULL);
     /*Create a Task For The Button*/
     xTaskCreate(Read_Button0_Task, (const portCHAR *)"Read_Button0", 128, NULL, 5 , NULL);
     xTaskCreate(Read_Button1_Task, (const portCHAR *)"Read_Button1", 128, NULL, 6 , NULL);
     /*Create Task For LCD*/
     xTaskCreate(LCD_Display_Task, (const portCHAR *)"LCD_APP", 128, NULL, 7 , NULL);
     /*Create Task For UART*/
     xTaskCreate(Recive_Task, (const portCHAR *)"Recive_UART", 128, NULL, 8 , NULL);
     vTaskStartScheduler();
     while(1)
     {
     }
	return 0;
}
