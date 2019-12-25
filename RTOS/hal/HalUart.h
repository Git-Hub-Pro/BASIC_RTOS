/*
 * HalUart.h
 *
 *  Created on: Sep 8, 2018
 *      Author: maanu
 *  Dec ,2019
 *       JiHyun studied 
 */

#ifndef HAL_HALUART_H_
#define HAL_HALUART_H_

void Hal_uart_init(void); // UART 하드웨어를 초기화 
void Hal_uart_put_char(uint8_t ch); // 알파벳 한글자를 보냄
uint8_t Hal_uart_get_char(void);

#endif /* HAL_HALUART_H_ */
