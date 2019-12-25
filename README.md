# BASIC_RTOS
임베디드 OS 개발 프로젝트_이만우 지음 교재에 있는 오픈 Navilos 소스입니다. 공부를 하면서 추가적으로 주석을 처리하였습니다.
전체적인 코드는 기존과 같습니다.

구조는

- boot 
      - Entry.S (리셋 벡터.)
      - Handler.c (익셉션을 처리하는 코드.) *익셉션이란 주변장치 등에서 발생한 신호를 처리하기 위해 진행하던 프로그램 수행을 끊는 것.
      - Main.c (메인 함수,주로 프로그래머가 작성. 관습적 c언어의 시작 지점.)
      
- hal (여러 플랫폼을 지원하기 위한 구조, ex) hal/rasppi
      - HalInterrupt.h
      - HalTimer.h
      - HalUart.h
      - rvpb
        - Interrupt.c (인터럽트 코드)
        - Interrupt.h (인터럽트 헤더 파일)
        - Regs.c (PL011 레지스터)
        - Timer.c (SP804 타이머 코드/목표 카운트 레지스터 와 측정 카운트 레지스터 조합)
        - Timer.h (타이머 헤더파일,레지스터를 구조체로 표현)
        - Uart.c (universal Asynchronous Receiver/Transmitter)
        - Uart.h (PL011의 레지스터 헤드,구조체로 구현)
      
- include
  - ARMv7AR.h (동작모드 전환값/ARM의 current program status register에 값을 설정)
  - memio.h 
  - MemoryMap.h (익센션 모드별 스택 시작 메모리 주소와 스택 크리,스택 꼭대기 메모리 주소)
  - stdarg.h 
  - stdint.h (standard 자료형)

- kernel
  - event.c (이벤트 플래그 함수 구현)
  - event.h (비트맵 구현)
  - Kernel.c (태스크가 커널에 스케줄링 요청하는 동작 yield() 함수 구현)
  - Kernel.h (컨텍스트 스위칭, yield 함수)
  - msg.c (메세지 큐 함수 구현)
  - msg.h
  - synch.c (동기화 함수 세마포어,뮤텍스 구현)
  - synch.h (세마포어,뮤텍스 구현)
  - task.c(태스크 컨트롤 블록과 관련 정의)
  (태스크라는 용어는 리눅스 같은 운영체제에서는 프로그램 혹은 프로세스라고 봐도됩니다.)
  - task.h(스케줄러 및 태스크 생성 헤더 파일)
- lib
  - armcpu.c (cspr 제어 코드, 어셈블리어만 가능)
  - armcpu.h (헤더 파일)
  - stdio.c (표준입출력)
  - stdio.h (표준입출력 헤더)
  - stlib.c (표준라이브러리)
  - stdlib.h (표준라이브러리 헤더)
- Makefile   (빌드 자동화 파일)
- navilos.ld (링커,여러 오브젝트 파일을 묶어서(linking) 하나의 실행 파일로 만드는 프로그램.)

      
