#ifndef __I2C_H__
#define __I2C_H__

#include <stdint.h>
#include <string.h>
#include <nrf_gpio.h>

//#define  IIC_SDA_TSM12   29       
//#define  IIC_SCL_TSM12   30   



//#define  SCL_H_TSM12      		nrf_gpio_pin_set(IIC_SCL_TSM12)  
//#define  SCL_L_TSM12          nrf_gpio_pin_clear(IIC_SCL_TSM12)
//#define  SDA_H_TSM12          nrf_gpio_pin_set(IIC_SDA_TSM12)
//#define  SDA_L_TSM12          nrf_gpio_pin_clear(IIC_SDA_TSM12)

//#define SDA_read_tsm12       nrf_gpio_pin_read(IIC_SDA_TSM12)   


#define  IIC_SDA_PCF8563   30       
#define  IIC_SCL_PCF8563   29         

#define  GH3220_RESET_PIN      22   

#define  SCL_H_PCF8563      		nrf_gpio_pin_set(IIC_SCL_PCF8563)  
#define  SCL_L_PCF8563          nrf_gpio_pin_clear(IIC_SCL_PCF8563)
#define  SDA_H_PCF8563         nrf_gpio_pin_set(IIC_SDA_PCF8563)
#define  SDA_L_PCF8563          nrf_gpio_pin_clear(IIC_SDA_PCF8563)
#define SDA_read_pcf8563       nrf_gpio_pin_read(IIC_SDA_PCF8563)   


//#define  IIC_SDA_AT24C02   17       
//#define  IIC_SCL_AT24C02   18         

//#define  SCL_H_AT24C02      		nrf_gpio_pin_set(IIC_SCL_AT24C02)  
//#define  SCL_L_AT24C02          nrf_gpio_pin_clear(IIC_SCL_AT24C02)
//#define  SDA_H_AT24C02          nrf_gpio_pin_set(IIC_SDA_AT24C02)
//#define  SDA_L_AT24C02          nrf_gpio_pin_clear(IIC_SDA_AT24C02)
//#define SDA_read_at24c02        nrf_gpio_pin_read(IIC_SDA_AT24C02)   

///********************************************************/
//void I2CStart_tsm12(void);
//void I2CStop_tsm12(void);
//void I2CAck_tsm12(void);
//void I2CNoAck_tsm12(void);
//uint8_t I2CWaitAck_tsm12(void);
//uint8_t I2CSendByte_tsm12(uint8_t SendByte); //数据从高位到低位
//uint8_t I2CReceiveByte_tsm12(void);

///*******I2C多字节连续读写函数********/
//uint8_t I2CWriteSerial_tsm12(uint8_t DeviceAddress,uint8_t Address,uint8_t *ps,uint8_t length);
//uint8_t I2CReadSerial_tsm12(uint8_t DeviceAddress,uint8_t Address,uint8_t *ps,uint8_t length);

///*********I2C端口初始化函数*********/
//void IIC_Init_tsm12(void);

void I2CStart_pcf8563(void);
void I2CStop_pcf8563(void);
void I2CAck_pcf8563(void);
void I2CNoAck_pcf8563(void);
uint8_t I2CWaitAck_pcf8563(void);
uint8_t I2CSendByte_pcf8563(uint8_t SendByte); //数据从高位到低位
uint8_t I2CReceiveByte_pcf8563(void);

/*******I2C多字节连续读写函数********/
uint8_t I2CWriteSerial_pcf8563(uint8_t DeviceAddress,uint16_t Address,uint8_t *ps,uint8_t length);
uint8_t I2CReadSerial_pcf8563(uint8_t DeviceAddress,uint16_t Address,uint8_t *ps,uint8_t length);

/*********I2C端口初始化函数*********/
void IIC_Init_pcf8563(void);


//void I2CStart_at24c02(void);
//void I2CStop_at24c02(void);
//void I2CAck_at24c02(void);
//void I2CNoAck_at24c02(void);
//uint8_t I2CWaitAck_at24c02(void);
//uint8_t I2CSendByte_at24c02(uint8_t SendByte); //数据从高位到低位
//uint8_t I2CReceiveByte_at24c02(void);

///*******I2C多字节连续读写函数********/
//uint8_t I2CWriteSerial_at24c02(uint8_t DeviceAddress,uint8_t Address,uint8_t *ps,uint8_t length);
//uint8_t I2CReadSerial_at24c02(uint8_t DeviceAddress,uint8_t Address,uint8_t *ps,uint8_t length);

///*********I2C端口初始化函数*********/
//void IIC_Init_at24c02(void);

#endif /* __RTC_H */
