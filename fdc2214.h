/*
 * fdc2214.h
 *
 *  Created on: 2018年7月8日
 *      Author: 83456
 */

#ifndef FDC2214_H_
#define FDC2214_H_

//宏定义FDC2214地址
#define FDC2214_ADDR_L              0x2A
#define FDC2214_ADDR_H              0x2B

//宏定义寄存器地址
#define FDC2214_DATA_CH0            0x00
#define FDC2214_DATA_LSB_CH0        0x01
#define FDC2214_DATA_CH1            0x02
#define FDC2214_DATA_LSB_CH1        0x03
#define FDC2214_DATA_CH2            0x04
#define FDC2214_DATA_LSB_CH2        0x05
#define FDC2214_DATA_CH3            0x06
#define FDC2214_DATA_LSB_CH3        0x07

#define FDC2214_RCOUNT_CH0          0x08
#define FDC2214_RCOUNT_CH1          0x09
#define FDC2214_RCOUNT_CH2          0x0A
#define FDC2214_RCOUNT_CH3          0x0B

#define FDC2114_OFFSET_CH0          0x0C
#define FDC2114_OFFSET_CH1          0x0D
#define FDC2114_OFFSET_CH2          0x0E
#define FDC2114_OFFSET_CH3          0x0F

#define FDC2214_SETTLECOUNT_CH0     0x10
#define FDC2214_SETTLECOUNT_CH1     0x11
#define FDC2214_SETTLECOUNT_CH2     0x12
#define FDC2214_SETTLECOUNT_CH3     0x13

#define FDC2214_CLOCK_DIVIDERS_CH0  0x14
#define FDC2214_CLOCK_DIVIDERS_CH1  0x15
#define FDC2214_CLOCK_DIVIDERS_CH2  0x16
#define FDC2214_CLOCK_DIVIDERS_CH3  0x17

#define FDC2214_STATUS              0x18
#define FDC2214_STATUS_CONFIG       0x19
#define FDC2214_CONFIG              0x1A
#define FDC2214_MUX_CONFIG          0x1B
#define FDC2214_RESET_DEV           0x1C

#define FDC2214_DRIVE_CURRENT_CH0   0x1E
#define FDC2214_DRIVE_CURRENT_CH1   0x1F
#define FDC2214_DRIVE_CURRENT_CH2   0x20

#define FDC2214_DRIVE_CURRENT_CH3   0x21
#define FDC2214_MANUFACTURER_ID     0x7E
#define FDC2214_DEVICE_ID           0x7F


/************CONFIG REGISTER*****************/
#define ACTIVE_CHAN_CH0             0x0000              //从CH0开始
#define ACTIVE_CHAN_CH1             0x4000
#define ACTIVE_CHAN_CH2             0x8000
#define ACTIVE_CHAN_CH3             0xC000

#define SLEEP_MODE_EN               0x2000
#define SLEEP_MODE_DIS              0x0000          //

#define SENSOR_ACTIVATE_SEL_FULL    0x0000         //
#define SENSOR_ACTIVATE_SEL_LOW     0x0800

#define REF_CLK_SRC_IN              0x0000
#define REF_CLK_SRC_EX              0x0200               //

#define INTB_DIS                    0x0000             //
#define INTB_EN                     0x0080

#define HIGH_CURRENT_DRV            0x0040
#define NORMAL_CURRENT_DRV          0x0000       //

#define CONFIG_RESERVED             0x1401


/************MUX_CONFIG REGISTER*****************/
#define AUTOSCAN_EN                 0x8000          //
#define AUTOSCAN_DIS                0x0000

#define RR_SEQUENCE_01              0x0000           //
#define RR_SEQUENCE_012             0x2000       //2114,2214 ONLY
#define RR_SEQUENCE_0123            0x4000       //2114,2214 ONLY

#define DEGLITCH_1M                 0x0001
#define DEGLITCH_3_3M               0x0004
#define DEGLITCH_10M                0x0005     //
#define DEGLITCH_33M                0x0007

#define MUX_CONFIG_RESERVED         0x0208


/************RCOUNT_CHx REGISTER*****************
 * conversion time is : 1/N * (TSAMPLE – settling time – channel switching delay)
 *                      = 1/2 (10,000 – 4 – 1) = 4.9975 ms
 * Conversion Time (tCx)= (CHx_RCOUNT*16)/fREFx
 * CHx_RCOUNT = tCx * fREFx /16 = (4.9975 * 40 * 10^3) /16 = 12493 (ENOB > 13 bits)
 * */

#define CHx_RCOUNT                  0x30CD   //Use CH0 CH1


/************OFFSET_CHx REGISTER*****************/
#define CHx_OFFSET                  0x0000  //not used


/************SETTLECOUNT_CHx REGISTER*****************
 * CHx_SETTLECOUNT > Vpk × fREFx × C × π2 / (32 × IDRIVEX) --> 7.5 -->10
 * Vpk = 1.68V fREFx = 40MHz C = 53pF IDRIVEX = 0.146mA
 * settling time =  (CHx_SETTLECOUNT*16) ÷ fREFx = 4 us
 * */
#define CHx_SETTLECOUNT             0x000A


/************CLOCK_DIVIDERS_CHx REGISTER*****************/
#define CHx_FIN_SEL_DIV_1           0x1000
#define CHx_FIN_SEL_DIV_2           0x2000     // fSENSORx = 5.15 MHz single-end

#define CHx_FREF_DIVIDER            0x0001     // fREFx > 4*fSENSORx = 20.6 MHz --> 40MHz
                                               // fREFx = fClk / CHx_FREF_DIVIDER

#define CLOCK_DIVIDERS_CHx_RESERVED 0x0000


/************STATUS REGISTER*****************/
//For interrupt, not used


/************STATUS_CONFIG REGISTER*****************/
//For interrupt, not used


/************RESET_DEV REGISTER*****************/
#define RESET_DEV                   0x8000

//FDC2112 2114 ONLY
#define OUTPUT_GAIN_1               0x0000      //
#define OUTPUT_GAIN_4               0x0200
#define OUTPUT_GAIN_8               0x0400
#define OUTPUT_GAIN_16              0x0600


/************DRIVE_CURRENT_CHx REGISTER*****************/
#define CHx_IDRIVE                  0x7800      // IDRIVE =0.146mA for Vpk = 1.68V

/************CONFIGURATION*****************/
#define CLOCK_DIVIDERS_CHx_CONFIG           ( CHx_FIN_SEL_DIV_2 \
                                    | CHx_FREF_DIVIDER | CLOCK_DIVIDERS_CHx_RESERVED )

#define DRIVE_CURRENT_CHx_CONFIG    CHx_IDRIVE

#define SETTLECOUNT_CHx_CONFIG      CHx_SETTLECOUNT

#define RCOUNT_CHx_CONFIG           CHx_RCOUNT

#define MUX_CONFIG                           ( AUTOSCAN_EN | MUX_CONFIG_RESERVED \
                                    | RR_SEQUENCE_01 | DEGLITCH_10M )

#define CONFIG                               ( ACTIVE_CHAN_CH0 | SLEEP_MODE_DIS \
                                    | SENSOR_ACTIVATE_SEL_FULL | REF_CLK_SRC_EX \
                                    | CONFIG_RESERVED )

//****************************************************************************

extern void ConfigI2C_1(void);
extern void FDC_Configure_1(void);
extern void FDC2214_Data_Anl_1(void);
extern void ConfigI2C_0(void);
extern void FDC_Configure_0(void);
extern void FDC2214_Data_Anl_0(void);
extern float capacitance_0  , capacitance_1 , capacitance_2  ,capacitance_3  ;
extern float capacitance_4  , capacitance_5  ;

//****************************************************************************

#endif /* FDC2214_H_ */
