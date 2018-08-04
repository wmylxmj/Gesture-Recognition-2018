/*
 * WMY_MUSIC.c
 *
 *  Created on: 2018��4��17��
 *      Author: wmy
 */

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/pin_map.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/pwm.h"
#include "driverlib/interrupt.h"
#include "driverlib/fpu.h"
#include "time.h"
#include "inc/hw_i2c.h"
#include "driverlib/rom.h"
#include "driverlib/adc.h"
#include "driverlib/uart.h"
#include "inc/hw_gpio.h"
#include "inc/hw_ints.h"
#include "string.h"
#include "driverlib/timer.h"

#include "WMY_SONG001.h"
#include "WMY_MUSIC.h"

//����88����ӦƵ��
#define A0 27.500
#define A0_B0 29.135
#define B0 30.868
#define C1 32.703
#define C1_D1 34.648
#define D1 36.708
#define D1_E1 38.891
#define E1 41.203
#define F1 43.654
#define F1_G1 46.249
#define G1 48.999
#define G1_A1 51.913
#define A1 55.000
#define A1_B1 58.270
#define B1 61.735
#define C2 65.406
#define C2_D2 69.296
#define D2 73.416
#define D2_E2 77.782
#define E2 82.407
#define F2 87.307
#define F2_G2 92.499
#define G2 97.999
#define G2_A2 103.83
#define A2 110.00
#define A2_B2 116.54
#define B2 123.47
#define C3 130.81
#define C3_D3 138.59
#define D3 146.83
#define D3_E3 155.56
#define E3 164.81
#define F3 174.61
#define F3_G3 185.00
#define G3 196.00
#define G3_A3 207.65
#define A3 220.00
#define A3_B3 233.08
#define B3 246.94
#define C4 261.63
#define C4_D4 277.18
#define D4 293.67
#define D4_E4 311.13
#define E4 329.63
#define F4 349.23
#define F4_G4 369.99
#define G4 392.00
#define G4_A4 415.30
#define A4 440.00
#define A4_B4 466.16
#define B4 493.88
#define C5 523.25
#define C5_D5 554.37
#define D5 587.33
#define D5_E5 622.25
#define E5 659.26
#define F5 698.46
#define F5_G5 739.99
#define G5 783.99
#define G5_A5 830.61
#define A5 880.00
#define A5_B5 932.33
#define B5 987.77
#define C6 1046.5
#define C6_D6 1108.7
#define D6 1174.7
#define D6_E6 1244.5
#define E6 1318.5
#define F6 1396.9
#define F6_G6 1480.0
#define G6 1568.0
#define G6_A6 1661.2
#define A6 1760.0
#define A6_B6 1864.7
#define B6 1975.5
#define C7 2093.0
#define C7_D7 2217.5
#define D7 2349.3
#define D7_E7 2489.0
#define E7 2637.0
#define F7 2793.0
#define F7_G7 2960.0
#define G7 3136.0
#define G7_A7 3322.4
#define A7 3520.0
#define A7_B7 3729.3
#define B7 3951.1
#define C8 4186.0
//����88����ӦƵ��

#define PWM_BEEP_CLOCK 1250000

void PWM1_PF1_GEN2_Beep_Init(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPinConfigure(GPIO_PF1_M1PWM5);
    GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_1);
    PWMGenConfigure(PWM1_BASE,PWM_GEN_2,PWM_GEN_MODE_DOWN|PWM_GEN_MODE_NO_SYNC);
    SysCtlPWMClockSet(SYSCTL_PWMDIV_32);
    PWMGenPeriodSet(PWM1_BASE, PWM_GEN_2, 1);//Numb=system clock/PWM frequency
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_5, 1);//number=Numb*%x
    PWMOutputState(PWM1_BASE,PWM_OUT_5_BIT,true);
    PWMGenDisable(PWM1_BASE, PWM_GEN_2);
}

void PWM1_PF3_GEN3_Beep_Init(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPinConfigure(GPIO_PF3_M1PWM7);
    GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_3);
    PWMGenConfigure(PWM1_BASE,PWM_GEN_3,PWM_GEN_MODE_DOWN|PWM_GEN_MODE_NO_SYNC);
    SysCtlPWMClockSet(SYSCTL_PWMDIV_32);
    PWMGenPeriodSet(PWM1_BASE, PWM_GEN_3, 1);//Numb=system clock/PWM frequency
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_7, 1);//number=Numb*%x
    PWMOutputState(PWM1_BASE,PWM_OUT_7_BIT,true);
    PWMGenDisable(PWM1_BASE, PWM_GEN_3);
}

void System_Clock_Init(void)
{
    SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL |SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);//40Mhz
    FPUEnable();
    FPULazyStackingEnable();
}

void Timer2AIntHandler(void)
{
    uint32_t ui32Status;
    static uint32_t L_COUNT=1;
    static uint32_t H_COUNT=1;
    static int i=0;
    static int j=0;
    ui32Status=TimerIntStatus(TIMER2_BASE,true);
    TimerIntClear(TIMER2_BASE,ui32Status);
    if(H_COUNT>DURATION001_H[i])
    {
        H_COUNT=1;
        if(PITCH001_H[i+1]!=0)
        {
            PWMGenPeriodSet(PWM1_BASE, PWM_GEN_2, PWM_BEEP_CLOCK/PITCH001_H[i+1]);//Numb=system clock/PWM frequency
            PWMPulseWidthSet(PWM1_BASE, PWM_OUT_5, (PWM_BEEP_CLOCK/PITCH001_H[i+1])*(100-INTENSITY001_H[i+1])/100);//number=Numb*%x
            i++;
        }
        else
        {
            i=0;
            PWMGenPeriodSet(PWM1_BASE, PWM_GEN_2, PWM_BEEP_CLOCK/20000);//Numb=system clock/PWM frequency
        }
    }
    if(L_COUNT>DURATION001_L[j])
    {
        if(PITCH001_L[j+1]!=0)
         {
            L_COUNT=1;
            PWMGenPeriodSet(PWM1_BASE, PWM_GEN_3, PWM_BEEP_CLOCK/PITCH001_L[j+1]);//Numb=system clock/PWM frequency
            PWMPulseWidthSet(PWM1_BASE, PWM_OUT_7, (PWM_BEEP_CLOCK/PITCH001_L[j+1])*(100-INTENSITY001_L[j+1])/100);//number=Numb*%x
            j++;
         }
        else
        {
            j=0;
            PWMGenPeriodSet(PWM1_BASE, PWM_GEN_3, PWM_BEEP_CLOCK/20000);//Numb=system clock/PWM frequency
        }
    }
    H_COUNT++;
    L_COUNT++;
}

void Timer2A_Init(void)//10ms
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER2);
    TimerClockSourceSet(TIMER2_BASE,TIMER_CLOCK_SYSTEM);
    TimerPrescaleSet(TIMER2_BASE,TIMER_A,8-1);//Ԥ��Ƶ
    TimerConfigure(TIMER2_BASE,TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_PERIODIC);//���幤����ʽ
    TimerLoadSet(TIMER2_BASE,TIMER_A,(SysCtlClockGet())/((TimerPrescaleGet(TIMER2_BASE,TIMER_A)+1)/100)-1);//װ��ֵ
    IntMasterEnable();//ʹ�����ж�
    TimerIntEnable(TIMER2_BASE,TIMER_TIMA_TIMEOUT);//��������װ��ֵ���ж�
    IntPrioritySet(INT_TIMER2A, 0x0);
    TimerIntRegister(TIMER2_BASE, TIMER_A, Timer2AIntHandler);
    TimerDisable(TIMER2_BASE,TIMER_A);//����������ϵͳʱ��
}
