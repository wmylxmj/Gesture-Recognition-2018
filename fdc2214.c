/*
 * fdc2214.c
 *
 *  Created on: 2018年7月21日
 *      Author: wmy
 */

#include "fdc2214.h"
#include "I2C_Init.h"


#include <stdint.h>
#include <stdbool.h>

#include "driverlib/pin_map.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "driverlib/i2c.h"
#include "driverlib/debug.h"
#include "driverlib/fpu.h"

#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "inc/hw_ints.h"
#include "inc/hw_i2c.h"

float capacitance_0 = 0.0f , capacitance_1 = 0.0f, capacitance_2 = 0.0f ,capacitance_3 = 0.0f ;
float capacitance_4 = 0.0f , capacitance_5 = 0.0f ;

void ConfigI2C_0(void)
{

    //Enable Peripheral:I2C0 Module and GPIOB
    SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);

    //Use I2C0 module--PB2 PB3;GPIO复用
    GPIOPinConfigure(GPIO_PB2_I2C0SCL);
    GPIOPinConfigure(GPIO_PB3_I2C0SDA);
    GPIOPinTypeI2CSCL(GPIO_PORTB_BASE,GPIO_PIN_2);      //SCL
    GPIOPinTypeI2C(GPIO_PORTB_BASE,GPIO_PIN_3);         //SDA

    //基址BASE;I2C时钟;速度:true:400Kbps(fast) /false:100Kbps(standard)
    I2CMasterInitExpClk(I2C0_BASE,SysCtlClockGet(),true);
}
void ConfigI2C_1()
{
    //Enable Peripheral:I2C1 Module and GPIOA
    SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C1);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

    //Use I2C1 module--PA6 PA7;GPIO复用
    GPIOPinConfigure(GPIO_PA6_I2C1SCL);
    GPIOPinConfigure(GPIO_PA7_I2C1SDA);
    GPIOPinTypeI2CSCL(GPIO_PORTA_BASE,GPIO_PIN_6);      //SCL
    GPIOPinTypeI2C(GPIO_PORTA_BASE,GPIO_PIN_7);         //SDA

    //基址BASE;I2C时钟;速度:true:400Kbps(fast) /false:100Kbps(standard)
    I2CMasterInitExpClk(I2C1_BASE,SysCtlClockGet(),true);
}
void FDC_Configure_0(void)
{
    while( I2CWriteTwoByte(I2C0_BASE, FDC2214_ADDR_L,
                               FDC2214_CONFIG, 0x1601 ) != 0)//外部时钟；0x1c81内部
                    ;

    while( I2CWriteTwoByte(I2C0_BASE, FDC2214_ADDR_L,
                           FDC2214_SETTLECOUNT_CH0, 0x000A ) != 0)
                    ;
    while( I2CWriteTwoByte(I2C0_BASE, FDC2214_ADDR_L,
                           FDC2214_RCOUNT_CH0, 0x8329 ) != 0)
                    ;
    while( I2CWriteTwoByte(I2C0_BASE, FDC2214_ADDR_L,
                           FDC2214_CLOCK_DIVIDERS_CH0, 0x2002 ) != 0)
                    ;
    while( I2CWriteTwoByte(I2C0_BASE, FDC2214_ADDR_L,
                           FDC2214_DRIVE_CURRENT_CH0, 0x7C00 ) != 0)
                    ;

    while( I2CWriteTwoByte(I2C0_BASE, FDC2214_ADDR_L,
                               FDC2214_SETTLECOUNT_CH1, 0x000A ) != 0)
                    ;
    while( I2CWriteTwoByte(I2C0_BASE, FDC2214_ADDR_L,
                           FDC2214_RCOUNT_CH1, 0x8329 ) != 0)
                    ;
    while( I2CWriteTwoByte(I2C0_BASE, FDC2214_ADDR_L,
                           FDC2214_CLOCK_DIVIDERS_CH1, 0x2002 ) != 0)
                    ;
    while( I2CWriteTwoByte(I2C0_BASE, FDC2214_ADDR_L,
                           FDC2214_DRIVE_CURRENT_CH1, 0x7C00 ) != 0)
                    ;

    while( I2CWriteTwoByte(I2C0_BASE, FDC2214_ADDR_L,
                               FDC2214_SETTLECOUNT_CH2, 0x000A ) != 0)
                    ;
    while( I2CWriteTwoByte(I2C0_BASE, FDC2214_ADDR_L,
                           FDC2214_RCOUNT_CH2, 0x8329 ) != 0)
                    ;
    while( I2CWriteTwoByte(I2C0_BASE, FDC2214_ADDR_L,
                           FDC2214_CLOCK_DIVIDERS_CH2, 0x2002 ) != 0)
                    ;
    while( I2CWriteTwoByte(I2C0_BASE, FDC2214_ADDR_L,
                           FDC2214_DRIVE_CURRENT_CH2, 0x7C00 ) != 0)
                    ;

    while( I2CWriteTwoByte(I2C0_BASE, FDC2214_ADDR_L,
                           FDC2214_SETTLECOUNT_CH3, 0x000A ) != 0)
                    ;
    while( I2CWriteTwoByte(I2C0_BASE, FDC2214_ADDR_L,
                           FDC2214_RCOUNT_CH3, 0x8329 ) != 0)
                    ;
    while( I2CWriteTwoByte(I2C0_BASE, FDC2214_ADDR_L,
                           FDC2214_CLOCK_DIVIDERS_CH3, 0x2002 ) != 0)
                    ;
    while( I2CWriteTwoByte(I2C0_BASE, FDC2214_ADDR_L,
                           FDC2214_DRIVE_CURRENT_CH3, 0x7C00 ) != 0)
                    ;

    while( I2CWriteTwoByte(I2C0_BASE, FDC2214_ADDR_L,
                           FDC2214_MUX_CONFIG, 0xA20D ) != 0)
                    ;

    while( I2CWriteTwoByte(I2C0_BASE, FDC2214_ADDR_L,
                           FDC2214_STATUS_CONFIG, 0x0000 ) != 0)
                    ;


}
void FDC_Configure_1()
{
    while( I2CWriteTwoByte(I2C1_BASE, FDC2214_ADDR_L,
                                   FDC2214_CONFIG, 0x1601 ) != 0)//外部时钟；0x1c81内部
                        ;

        while( I2CWriteTwoByte(I2C1_BASE, FDC2214_ADDR_L,
                               FDC2214_SETTLECOUNT_CH0, 0x000A ) != 0)
                        ;
        while( I2CWriteTwoByte(I2C1_BASE, FDC2214_ADDR_L,
                               FDC2214_RCOUNT_CH0, 0x8329 ) != 0)
                        ;
        while( I2CWriteTwoByte(I2C1_BASE, FDC2214_ADDR_L,
                               FDC2214_CLOCK_DIVIDERS_CH0, 0x2002 ) != 0)
                        ;
        while( I2CWriteTwoByte(I2C1_BASE, FDC2214_ADDR_L,
                               FDC2214_DRIVE_CURRENT_CH0, 0x7C00 ) != 0)
                        ;

        while( I2CWriteTwoByte(I2C1_BASE, FDC2214_ADDR_L,
                                   FDC2214_SETTLECOUNT_CH1, 0x000A ) != 0)
                        ;
        while( I2CWriteTwoByte(I2C1_BASE, FDC2214_ADDR_L,
                               FDC2214_RCOUNT_CH1, 0x8329 ) != 0)
                        ;
        while( I2CWriteTwoByte(I2C1_BASE, FDC2214_ADDR_L,
                               FDC2214_CLOCK_DIVIDERS_CH1, 0x2002 ) != 0)
                        ;
        while( I2CWriteTwoByte(I2C1_BASE, FDC2214_ADDR_L,
                               FDC2214_DRIVE_CURRENT_CH1, 0x7C00 ) != 0)
                        ;

        while( I2CWriteTwoByte(I2C1_BASE, FDC2214_ADDR_L,
                                   FDC2214_SETTLECOUNT_CH2, 0x000A ) != 0)
                        ;
        while( I2CWriteTwoByte(I2C1_BASE, FDC2214_ADDR_L,
                               FDC2214_RCOUNT_CH2, 0x8329 ) != 0)
                        ;
        while( I2CWriteTwoByte(I2C1_BASE, FDC2214_ADDR_L,
                               FDC2214_CLOCK_DIVIDERS_CH2, 0x2002 ) != 0)
                        ;
        while( I2CWriteTwoByte(I2C1_BASE, FDC2214_ADDR_L,
                               FDC2214_DRIVE_CURRENT_CH2, 0x7C00 ) != 0)
                        ;

        while( I2CWriteTwoByte(I2C1_BASE, FDC2214_ADDR_L,
                               FDC2214_SETTLECOUNT_CH3, 0x000A ) != 0)
                        ;
        while( I2CWriteTwoByte(I2C1_BASE, FDC2214_ADDR_L,
                               FDC2214_RCOUNT_CH3, 0x8329 ) != 0)
                        ;
        while( I2CWriteTwoByte(I2C1_BASE, FDC2214_ADDR_L,
                               FDC2214_CLOCK_DIVIDERS_CH3, 0x2002 ) != 0)
                        ;
        while( I2CWriteTwoByte(I2C1_BASE, FDC2214_ADDR_L,
                               FDC2214_DRIVE_CURRENT_CH3, 0x7C00 ) != 0)
                        ;

        while( I2CWriteTwoByte(I2C1_BASE, FDC2214_ADDR_L,
                               FDC2214_MUX_CONFIG, 0xA20D ) != 0)
                        ;

        while( I2CWriteTwoByte(I2C1_BASE, FDC2214_ADDR_L,
                               FDC2214_STATUS_CONFIG, 0x0000 ) != 0)
                        ;
}

void FDC2214_Data_Anl_0(void)
{
    uint16_t ui16rawdata_0_MSB = 0 , ui16rawdata_0_LSB = 0;
    uint16_t ui16rawdata_1_MSB = 0 , ui16rawdata_1_LSB = 0;
    uint16_t ui16rawdata_2_MSB = 0 , ui16rawdata_2_LSB = 0;
    uint32_t ui32rawdata_0 = 0 , ui32rawdata_1 = 0,ui32rawdata_2 = 0;
    float fsensor_0 = 0.0f , fsensor_1 = 0.0f,fsensor_2 = 0.0f;
    // MSB first for coherence
    while( I2CReadTwoByte(I2C0_BASE, FDC2214_ADDR_L,
                     FDC2214_DATA_CH0, &ui16rawdata_0_MSB)!= 0 )
        ;
    while( I2CReadTwoByte(I2C0_BASE, FDC2214_ADDR_L,
                     FDC2214_DATA_LSB_CH0, &ui16rawdata_0_LSB)!= 0 )
        ;
    ui32rawdata_0 =((ui16rawdata_0_MSB & 0x0FFF) << 16) | ui16rawdata_0_LSB;
    SysCtlDelay(10*(SysCtlClockGet()/3000));

    while( I2CReadTwoByte(I2C0_BASE, FDC2214_ADDR_L,
                     FDC2214_DATA_CH1, &ui16rawdata_1_MSB)!= 0 )
        ;
    while( I2CReadTwoByte(I2C0_BASE, FDC2214_ADDR_L,
                     FDC2214_DATA_LSB_CH1, &ui16rawdata_1_LSB)!= 0 )
        ;
    ui32rawdata_1 =((ui16rawdata_1_MSB & 0x0FFF) << 16) | ui16rawdata_1_LSB;
    SysCtlDelay(10*(SysCtlClockGet()/3000));

//
    while( I2CReadTwoByte(I2C0_BASE, FDC2214_ADDR_L,
                     FDC2214_DATA_CH2, &ui16rawdata_2_MSB)!= 0 )
        ;
    while( I2CReadTwoByte(I2C0_BASE, FDC2214_ADDR_L,
                     FDC2214_DATA_LSB_CH2, &ui16rawdata_2_LSB)!= 0 )
        ;
    ui32rawdata_2 =((ui16rawdata_2_MSB & 0x0FFF) << 16) | ui16rawdata_2_LSB;
    SysCtlDelay(10*(SysCtlClockGet()/3000));

    // 0.298023 = 2 * 40,000,000 / 2^28
    fsensor_0 = (float)(ui32rawdata_0 * 0.298023);
    fsensor_1 = (float)(ui32rawdata_1 * 0.298023);
    fsensor_2 = (float)(ui32rawdata_2 * 0.298023);

    // 1407.238661 = 1/ (2 * pi^2) * 18 * 10^(-6)
    capacitance_3 = 1407.238661 * 1.0e+12 / (fsensor_0*fsensor_0);
    capacitance_4 = 1407.238661 * 1.0e+12 / (fsensor_1*fsensor_1);
    capacitance_5 = 1407.238661 * 1.0e+12 / (fsensor_2*fsensor_2);

}
void FDC2214_Data_Anl_1()
{
    uint16_t ui16rawdata_0_MSB = 0 , ui16rawdata_0_LSB = 0;
    uint16_t ui16rawdata_1_MSB = 0 , ui16rawdata_1_LSB = 0;
    uint16_t ui16rawdata_2_MSB = 0 , ui16rawdata_2_LSB = 0;
    uint32_t ui32rawdata_0 = 0 , ui32rawdata_1 = 0,ui32rawdata_2 = 0;
    float fsensor_0 = 0.0f , fsensor_1 = 0.0f,fsensor_2 = 0.0f;
    // MSB first for coherence
    while( I2CReadTwoByte(I2C1_BASE, FDC2214_ADDR_L,
                     FDC2214_DATA_CH0, &ui16rawdata_0_MSB)!= 0 )
        ;
    while( I2CReadTwoByte(I2C1_BASE, FDC2214_ADDR_L,
                     FDC2214_DATA_LSB_CH0, &ui16rawdata_0_LSB)!= 0 )
        ;
    ui32rawdata_0 =((ui16rawdata_0_MSB & 0x0FFF) << 16) | ui16rawdata_0_LSB;
    SysCtlDelay(10*(SysCtlClockGet()/3000));

    while( I2CReadTwoByte(I2C1_BASE, FDC2214_ADDR_L,
                     FDC2214_DATA_CH1, &ui16rawdata_1_MSB)!= 0 )
        ;
    while( I2CReadTwoByte(I2C1_BASE, FDC2214_ADDR_L,
                     FDC2214_DATA_LSB_CH1, &ui16rawdata_1_LSB)!= 0 )
        ;
    ui32rawdata_1 =((ui16rawdata_1_MSB & 0x0FFF) << 16) | ui16rawdata_1_LSB;
    SysCtlDelay(10*(SysCtlClockGet()/3000));

//
    while( I2CReadTwoByte(I2C1_BASE, FDC2214_ADDR_L,
                     FDC2214_DATA_CH2, &ui16rawdata_2_MSB)!= 0 )
        ;
    while( I2CReadTwoByte(I2C1_BASE, FDC2214_ADDR_L,
                     FDC2214_DATA_LSB_CH2, &ui16rawdata_2_LSB)!= 0 )
        ;
    ui32rawdata_2 =((ui16rawdata_2_MSB & 0x0FFF) << 16) | ui16rawdata_2_LSB;
    SysCtlDelay(10*(SysCtlClockGet()/3000));


    // 0.298023 = 2 * 40,000,000 / 2^28
    fsensor_0 = (float)(ui32rawdata_0 * 0.298023);
    fsensor_1 = (float)(ui32rawdata_1 * 0.298023);
    fsensor_2 = (float)(ui32rawdata_2 * 0.298023);

    // 1407.238661 = 1/ (2 * pi^2) * 18 * 10^(-6)
    capacitance_0 = 1407.238661 * 1.0e+12 / (fsensor_0*fsensor_0);
    capacitance_1 = 1407.238661 * 1.0e+12 / (fsensor_1*fsensor_1);
    capacitance_2 = 1407.238661 * 1.0e+12 / (fsensor_2*fsensor_2);
}
