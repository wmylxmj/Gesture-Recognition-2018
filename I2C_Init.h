/*************
 坂本制作
I2C的配置文件

 2018.2.10
**************/
#ifndef IIC_Init_H_
#define IIC_Init_H_

#include <stdint.h>
#include <stdbool.h>
#include "driverlib/pin_map.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "driverlib/i2c.h"
#include "driverlib/debug.h"

#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "inc/hw_ints.h"
#include "inc/hw_i2c.h"

typedef struct
{
    uint32_t    SYSCTL_PERIPH_I2C;
    uint32_t    SYSCTL_PERIPH_GPIO_I2C;

    uint32_t    GPIO_PORT_I2C_BASE;
    uint32_t    GPIO_I2C_SCL;
    uint32_t    GPIO_I2C_SDA;
    uint8_t     GPIO_PIN_I2C_SCL;
    uint8_t     GPIO_PIN_I2C_SDA;

    uint32_t    I2C_BASE;
}i2c_data_t;

extern i2c_data_t i2c_array[4];

extern uint32_t I2CWriteOneByte(uint32_t ui32I2CBase,uint8_t ui8SlaAddr,
        uint8_t ui8RegAddr, uint8_t ui8RegData);
extern uint32_t I2CWriteTwoByte(uint32_t ui32I2CBase,uint8_t ui8SlaAddr,
        uint8_t ui8RegAddr, uint16_t ui16RegData);
extern uint32_t I2CWriteMultiByte(uint32_t ui32I2CBase,uint8_t ui8SlaAddr,
        uint8_t ui8RegAddr, uint8_t *pui8RegData, uint32_t ui32WriteCount);


extern uint32_t I2CReadOneByte(uint32_t ui32I2CBase, uint8_t ui8SlaAddr,
        uint8_t ui8RegAddr, uint8_t *pui8RegData);
extern uint32_t I2CReadTwoByte(uint32_t ui32I2CBase, uint8_t ui8SlaAddr,
        uint8_t ui8RegAddr, uint16_t *pui16RegData);
extern uint32_t I2CReadMultiByte(uint32_t ui32I2CBase, uint8_t ui8SlaAddr,
        uint8_t ui8RegAddr,uint8_t *pui8RegData, uint32_t ui32ReadCount);

extern void ConfigureI2C(int mode,void (* I2C_Handler)(void));

#endif
