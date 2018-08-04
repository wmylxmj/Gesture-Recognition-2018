/*
 * WMY_MUSIC.h
 *
 *  Created on: 2018��4��17��
 *      Author: wmy
 */

#ifndef MUSIC_WMY_MUSIC_H_
#define MUSIC_WMY_MUSIC_H_

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

extern void PWM1_PF1_GEN2_Beep_Init(void);
extern void PWM1_PF3_GEN3_Beep_Init(void);
extern void System_Clock_Init(void);
extern void Timer2AIntHandler(void);
extern void Timer2A_Init(void);

#endif /* MUSIC_WMY_MUSIC_H_ */
