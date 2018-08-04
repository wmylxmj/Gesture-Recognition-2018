/*
 * WMY_SONG001.c
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

#include "WMY_MUSIC.h"
#include "WMY_SONG001.h"
//�����߶�
double PITCH001_H[]={20000,
                     C5,D5,D5_E5,F5,G5,
                     C5,C6,D5_E5,G5,F5,
                     D5_E5,D5,C5,D5,D5_E5,
                     G5,F5,A4_B4,A5_B5,G5_A5,
                     G5,F5,D5,C5,A4_B4,
                     C5,D5,F5,D5_E5,G4_A4,
                     G5_A5,C5,D5_E5,G4_A4,D5,
                     C5,A4_B4,C5,D5,D5_E5,
                     F5,A4_B4,A5_B5,C6,G5,
                     F5,G5,B4,B5,D6,
                     G5,F5,
                     0};
//��������
double DURATION001_H[]={12,
                        12,12,12,12,12,
                        12,12,12,12,12,
                        12,12,12,12,12,
                        12,12,12,12,12,
                        12,12,12,12,12,
                        12,12,12,12,12,
                        12,12,12,12,12,
                        12,12,12,12,12,
                        12,12,12,12,12,
                        12,12,12,12,12,
                        12,12,
                        12};
//����ǿ��
double INTENSITY001_H[]={50,
                         50,50,50,50,50,
                         50,50,50,50,50,
                         50,50,50,50,50,
                         50,50,50,50,50,
                         50,50,50,50,50,
                         50,50,50,50,50,
                         50,50,50,50,50,
                         50,50,50,50,50,
                         50,50,50,50,50,
                         50,50,50,50,50,
                         50,50,
                         50};

double PITCH001_L[]={20000,C4,D4,E4,F4,G4,A4,B4,C5,0};
double DURATION001_L[]={25,25,25,25,25,25,25,25,25,25};
double INTENSITY001_L[]={50,50,50,50,50,50,50,50,50,50};
