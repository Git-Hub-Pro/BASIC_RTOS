/*
 * armcpu.c
 *
 *  Created on: Sep 22, 2018
 *      Author: maanu
 *  studied by Hyun
 */

/*
cspr을 제어하려면 어셈블리어를 사용할 수밖에 없습니다. GCC가 아닌 ARM 사에서
제공하는 ARMCC는 아무래도 ARM을 만든 회사에서 제공하는 컴파일러라 그런지 컴파일러라
그런지 컴파일러의 빌트인 변수로 cspr에 접근할 수 있는데, GCC는 그렇지 않습니다. 따라서
Entry.S 처럼 어셈블리어 소스 파일을 만들거나 C언어 함수 속에서 인라인 어셈블리어를 사용하는
방법이 있습니다.
*/

#include "armcpu.h"

void enable_irq(void)
{
    __asm__ ("PUSH {r0, r1}");
    __asm__ ("MRS  r0, cpsr");
    __asm__ ("BIC  r1, r0, #0x80");
    __asm__ ("MSR  cpsr, r1");
    __asm__ ("POP {r0, r1}");
}

void enable_fiq(void)
{
    __asm__ ("PUSH {r0, r1}");
    __asm__ ("MRS  r0, cpsr");
    __asm__ ("BIC  r1, r0, #0x40");
    __asm__ ("MSR  cpsr, r1");
    __asm__ ("POP {r0, r1}");
}

void disable_irq(void)
{
    __asm__ ("PUSH {r0, r1}");
    __asm__ ("MRS  r0, cpsr");
    __asm__ ("ORR  r1, r0, #0x80");
    __asm__ ("MSR  cpsr, r1");
    __asm__ ("POP {r0, r1}");
}

void disable_fiq(void)
{
    __asm__ ("PUSH {r0, r1}");
    __asm__ ("MRS  r0, cpsr");
    __asm__ ("ORR  r1, r0, #0x40");
    __asm__ ("MSR  cpsr, r1");
    __asm__ ("POP {r0, r1}");
}
