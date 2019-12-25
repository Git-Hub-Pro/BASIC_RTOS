/*
 * HalInterrupt.h
 *
 *  Created on: Sep 21, 2018
 *      Author: maanu
 *  studied by Hyun
 * 초기화 함수, 인터럽트 활성화 함수, 인터럽트 비활성화 함수
 * 인터럽트 핸들러 등록 함수, 인터럽트 핸들러 호출 함수.
 */

#ifndef HAL_HALINTERRUPT_H_
#define HAL_HALINTERRUPT_H_

#define INTERRUPT_HANDLER_NUM   255

typedef void (*InterHdlr_fptr)(void);

void Hal_interrupt_init(void);
void Hal_interrupt_enable(uint32_t interrupt_num);
void Hal_interrupt_disable(uint32_t interrupt_num);
void Hal_interrupt_register_handler(InterHdlr_fptr handler, uint32_t interrupt_num);
void Hal_interrupt_run_handler(void);

#endif /* HAL_HALINTERRUPT_H_ */


