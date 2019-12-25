/*
 * Handler.c
 *
 *  Created on: Sep 22, 2018
 *      Author: maanu
 */

#include "stdbool.h"
#include "stdint.h"
#include "HalInterrupt.h"

// __attribute__는 GCC의 확장 기능을 사용하겠다는 지시어.

 __attribute__ ((interrupt ("IRQ"))) void Irq_Handler(void)
{
    Hal_interrupt_run_handler();
}

 __attribute__ ((interrupt ("FIQ"))) void Fiq_Handler(void)
{
    while(true);
}
