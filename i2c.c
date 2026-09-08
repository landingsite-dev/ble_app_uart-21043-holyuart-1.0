#include "i2c.h"
#include "nrf_delay.h"

/*********************************************
 * 函数名：I2Cdelay
 * 描  述：I2C延时函数
 * 输  入：无
 * 输  出：无
 ********************************************/
void I2Cdelay(void)
{	
		nrf_delay_us(2);	
}

/*********************************************
 * 函数名：IIC_Init
 * 描  述：I2C端口初始化
 * 输  入：无
 * 输  出：无
 ********************************************/
//void IIC_Init_tsm12(void)
//{
//  /* GPIO configuration */
//		nrf_gpio_cfg_output(IIC_SCL_TSM12);		
//		nrf_gpio_cfg_output(IIC_SDA_TSM12);
//		I2Cdelay();
//	
//		SDA_H_TSM12;
//    SCL_H_TSM12;
//		I2Cdelay();

//}

///*********************************************
// * 函数名：I2CStart
// * 描  述：开启I2C总线
// * 输  入：无
// * 输  出：TRUE:操作成功，FALSE:操作失败
// ********************************************/
//void I2CStart_tsm12(void)
//{
//		nrf_gpio_cfg_output(IIC_SDA_TSM12);
//		I2Cdelay();
//	
//    SDA_H_TSM12;
//		I2Cdelay();
//    SCL_H_TSM12;
//    I2Cdelay();
//    SDA_L_TSM12;
//    I2Cdelay();
//    SCL_L_TSM12;
//    I2Cdelay();
//}


///*********************************************
// * 函数名：I2CStop
// * 描  述：释放I2C总线
// * 输  入：无
// * 输  出：无
// ********************************************/
//void I2CStop_tsm12(void)
//{
//		nrf_gpio_cfg_output(IIC_SDA_TSM12);
//    I2Cdelay();
////    SCL_L;
////    I2Cdelay();
//	
//    SDA_L_TSM12;
//    I2Cdelay();
//    SCL_H_TSM12;
//    I2Cdelay();
//    SDA_H_TSM12;
//    I2Cdelay();
//}

///*********************************************
// * 函数名：I2CAck
// * 描  述：发送ASK
// * 输  入：无
// * 输  出：无
// ********************************************/
//void I2CAck_tsm12(void)      //主机发送
//{
//		nrf_gpio_cfg_output(IIC_SDA_TSM12);
//    I2Cdelay();
//	
//    SCL_L_TSM12;
//    I2Cdelay();
//    SDA_L_TSM12;
//    I2Cdelay();
//    SCL_H_TSM12;
//    I2Cdelay();
//    SCL_L_TSM12;
//    I2Cdelay();
//}

///*********************************************
// * 函数名：I2CNoAck
// * 描  述：发送NOASK
// * 输  入：无
// * 输  出：无
// ********************************************/
//void I2CNoAck_tsm12(void)             //主机发送
//{
//		nrf_gpio_cfg_output(IIC_SDA_TSM12);
//    I2Cdelay();
//	
//    SCL_L_TSM12;
//    I2Cdelay();
//    SDA_H_TSM12;
//    I2Cdelay();
//    SCL_H_TSM12;
//    I2Cdelay();
//    SCL_L_TSM12;
//    I2Cdelay();
//}

///*********************************************
// * 函数名：I2CWaitAck
// * 描  述：读取ACK信号
// * 输  入：无
// * 输  出：TRUE=有ACK,FALSE=无ACK
// ********************************************/
//uint8_t I2CWaitAck_tsm12(void)          //主机接收
//{
//		uint16_t i=0;
//    SCL_L_TSM12;	
//    I2Cdelay();
//	
//		nrf_gpio_cfg_input(IIC_SDA_TSM12,NRF_GPIO_PIN_NOPULL);
//    I2Cdelay();
//	
//    SCL_H_TSM12;
//    I2Cdelay();
//		while((SDA_read_tsm12)&&(i<100))
//		{
//				i++;
//				I2Cdelay();
//		}		
//		SCL_L_TSM12;
//		I2Cdelay();
//	
//    if(i<99)
//    {
//			return 1;
//    }
//		else
//		{
//			return 0;
//		}
//}


///*********************************************
// * 函数名：I2CSendByte
// * 描  述：MCU发送一个字节
// * 输  入：无
// * 输  出：无
// ********************************************/
//uint8_t I2CSendByte_tsm12(uint8_t SendByte) //数据从高位到低位
//{
//		nrf_gpio_cfg_output(IIC_SDA_TSM12);
//		I2Cdelay();
//    uint8_t i=0;
//		for(i=0;i<8;i++)
//		{
//			SCL_L_TSM12;
//			I2Cdelay();
//			if(SendByte&0x80)
//			SDA_H_TSM12;  
//			else 
//			SDA_L_TSM12;   
//			SendByte<<=1;
//			I2Cdelay();
//			SCL_H_TSM12;
//			I2Cdelay();
//		}
//    SCL_L_TSM12;
//		I2Cdelay();
//		if(!I2CWaitAck_tsm12())
//		{
//				I2CStop_tsm12(); return 0;
//		}
//		else
//		{
//				return 1; 
//		}
//		
//}

///*********************************************
// * 函数名：I2CReceiveByte
// * 描  述：MCU读入一个字节
// * 输  入：无
// * 输  出：ReceiveByte
// ********************************************/
//uint8_t I2CReceiveByte_tsm12(void)
//{
//	
//		nrf_gpio_cfg_input(IIC_SDA_TSM12,NRF_GPIO_PIN_NOPULL);
//    I2Cdelay();
//	
//    uint8_t ReceiveByte=0;

//    uint8_t i=0;
//		for(i=0;i<8;i++)
//    {
//      ReceiveByte<<=1;         
//      SCL_L_TSM12;
//      I2Cdelay();
//      SCL_H_TSM12;
//      I2Cdelay();	
//      if(SDA_read_tsm12)
//      {
//        ReceiveByte|=0x1;
//      }
//    }
//    SCL_L_TSM12;
//		I2Cdelay();	
//    return ReceiveByte;   
//}


///*********************************************
// * 函数名     ：I2CWriteSerial
// * 描  述     ：I2C在指定地址写一字节数据
// * Device_Addr：I2C设备地址
// * Address    ：内部地址
// * length     ：字节长度
// * ps         ：缓存区指针
// * 输出       ：TRUE 成功，FALSE 失败
// ********************************************/	
//uint8_t I2CWriteSerial_tsm12(uint8_t DeviceAddress, uint8_t Address, uint8_t *ps, uint8_t length)
//{

//		I2CStart_tsm12();
//		I2CSendByte_tsm12(DeviceAddress);   
//		I2CSendByte_tsm12(Address);			
//    uint8_t i=0;
//		for(i=0;i<length;i++)
//		{ 	
//				I2CSendByte_tsm12(*(ps++));							
//		}
//		I2CStop_tsm12(); 

//		return	1;
//}

///*********************************************
// * 函数名     ：I2CReadSerial
// * 描  述     ：I2C在指定地址写一字节数据
// * Device_Addr：I2C设备地址
// * Address    ：内部地址
// * length     ：字节长度
// * ps         ：缓存区指针
// * 输出       ：TRUE 成功，FALSE 失败
// ********************************************/	
//uint8_t I2CReadSerial_tsm12(uint8_t DeviceAddress, uint8_t Address, uint8_t *ps, uint8_t length)
//{
//		I2CStart_tsm12();
//		I2CSendByte_tsm12(DeviceAddress);      
//		I2CSendByte_tsm12(Address);
//		I2CStart_tsm12();	
//		I2CSendByte_tsm12(DeviceAddress+1);
//    uint8_t i=0;
//		for(i=0;i<length-1;i++)
//		{
//			*(ps+i) = I2CReceiveByte_tsm12();
//			I2CAck_tsm12();
//		}
//		*(ps+i) = I2CReceiveByte_tsm12();	
//		I2CNoAck_tsm12();
//		I2CStop_tsm12(); 
//		return	1;
//}

/*
void IIC_Init_at24c02(void)
{
		nrf_gpio_cfg_output(IIC_SCL_AT24C02);		
		nrf_gpio_cfg_output(IIC_SDA_AT24C02);
    I2Cdelay();
	
		SDA_H_AT24C02;
    SCL_H_AT24C02;
		I2Cdelay();
	
}

void I2CStart_at24c02(void)
{
		nrf_gpio_cfg_output(IIC_SDA_AT24C02);
		I2Cdelay();
	
    SDA_H_AT24C02;
		I2Cdelay();
    SCL_H_AT24C02;
    I2Cdelay();
    SDA_L_AT24C02;
    I2Cdelay();
    SCL_L_AT24C02;
    I2Cdelay();
}

void I2CStop_at24c02(void)
{
		nrf_gpio_cfg_output(IIC_SDA_AT24C02);
    I2Cdelay();
//    SCL_L;
//    I2Cdelay();
	
    SDA_L_AT24C02;
    I2Cdelay();
    SCL_H_AT24C02;
    I2Cdelay();
    SDA_H_AT24C02;
    I2Cdelay();
}

void I2CAck_at24c02(void)          //主机发送
{
		nrf_gpio_cfg_output(IIC_SDA_AT24C02);
    I2Cdelay();
	
    SCL_L_AT24C02;
    I2Cdelay();
    SDA_L_AT24C02;
    I2Cdelay();
    SCL_H_AT24C02;
    I2Cdelay();
    SCL_L_AT24C02;
    I2Cdelay();
}


void I2CNoAck_at24c02(void)          //主机发送
{
		nrf_gpio_cfg_output(IIC_SDA_AT24C02);
    I2Cdelay();
	
    SCL_L_AT24C02;
    I2Cdelay();
    SDA_H_AT24C02;
    I2Cdelay();
    SCL_H_AT24C02;
    I2Cdelay();
    SCL_L_AT24C02;
    I2Cdelay();
}

uint8_t I2CWaitAck_at24c02(void)            //主机接收
{
		uint16_t i=0;
    SCL_L_AT24C02;	
    I2Cdelay();
	
		nrf_gpio_cfg_input(IIC_SDA_AT24C02,NRF_GPIO_PIN_NOPULL);
    I2Cdelay();
	
    SCL_H_AT24C02;
    I2Cdelay();
		while((SDA_read_at24c02)&&(i<100))
		{
				i++;
				I2Cdelay();
		}		
		SCL_L_AT24C02;
		I2Cdelay();
	
    if(i<99)
    {
			return 1;
    }
		else
		{
			return 0;
		}
}

uint8_t I2CSendByte_at24c02(uint8_t SendByte) //数据从高位到低位
{
		nrf_gpio_cfg_output(IIC_SDA_AT24C02);
		I2Cdelay();
    uint8_t i=0;
		for(i=0;i<8;i++)
		{
			SCL_L_AT24C02;
			I2Cdelay();
			if(SendByte&0x80)
			SDA_H_AT24C02;  
			else 
			SDA_L_AT24C02;   
			SendByte<<=1;
			I2Cdelay();
			SCL_H_AT24C02;
			I2Cdelay();
		}
    SCL_L_AT24C02;
		I2Cdelay();
		if(!I2CWaitAck_at24c02())
		{
				I2CStop_at24c02(); return 0;
		}
		else
		{
				return 1; 
		}	
}

uint8_t I2CReceiveByte_at24c02(void)
{	
		nrf_gpio_cfg_input(IIC_SDA_AT24C02,NRF_GPIO_PIN_NOPULL);
    I2Cdelay();
	
    uint8_t ReceiveByte=0;

    uint8_t i=0;
		for(i=0;i<8;i++)
		{
      ReceiveByte<<=1;         
      SCL_L_AT24C02;
      I2Cdelay();
      SCL_H_AT24C02;
      I2Cdelay();	
      if(SDA_read_at24c02)
      {
        ReceiveByte|=0x1;
      }
    }
    SCL_L_AT24C02;
		I2Cdelay();	
    return ReceiveByte;   
}

uint8_t I2CWriteSerial_at24c02(uint8_t DeviceAddress, uint8_t Address, uint8_t *ps, uint8_t length)//
{

		I2CStart_at24c02();
		I2CSendByte_at24c02(DeviceAddress);   
		I2CSendByte_at24c02(Address);		
    uint8_t i=0;
		for(i=0;i<length;i++)
		{
				I2CSendByte_at24c02(*(ps++));							
		}
		I2CStop_at24c02(); 

		return	1;
}

uint8_t I2CReadSerial_at24c02(uint8_t DeviceAddress, uint8_t Address, uint8_t *ps, uint8_t length)
{
		I2CStart_at24c02();
		I2CSendByte_at24c02(DeviceAddress);      
		I2CSendByte_at24c02(Address);
		I2CStart_at24c02();	
		I2CSendByte_at24c02(DeviceAddress+1);
	
    uint8_t i=0;
		for(i=0;i<length-1;i++)
		{
			*(ps+i) = I2CReceiveByte_at24c02();
			I2CAck_at24c02();
		}
		*(ps+i) = I2CReceiveByte_at24c02();
		I2CNoAck_at24c02();
		I2CStop_at24c02(); 
		return	1;
}
*/

void IIC_Init_pcf8563(void)
{
		nrf_gpio_cfg_output(IIC_SCL_PCF8563);		
		nrf_gpio_cfg_output(IIC_SDA_PCF8563);
    I2Cdelay();
	
		SDA_H_PCF8563;
    SCL_H_PCF8563;
		I2Cdelay();
	
}

void I2CStart_pcf8563(void)
{
		nrf_gpio_cfg_output(IIC_SDA_PCF8563);
		I2Cdelay();
	
    SDA_H_PCF8563;
		I2Cdelay();
    SCL_H_PCF8563;
    I2Cdelay();
    SDA_L_PCF8563;
    I2Cdelay();
    SCL_L_PCF8563;
    I2Cdelay();
}

void I2CStop_pcf8563(void)
{
		nrf_gpio_cfg_output(IIC_SDA_PCF8563);
    I2Cdelay();
//    SCL_L;
//    I2Cdelay();
	
    SDA_L_PCF8563;
    I2Cdelay();
    SCL_H_PCF8563;
    I2Cdelay();
    SDA_H_PCF8563;
    I2Cdelay();
}

void I2CAck_pcf8563(void)          //主机发送
{
		nrf_gpio_cfg_output(IIC_SDA_PCF8563);
    I2Cdelay();
	
    SCL_L_PCF8563;
    I2Cdelay();
    SDA_L_PCF8563;
    I2Cdelay();
    SCL_H_PCF8563;
    I2Cdelay();
    SCL_L_PCF8563;
    I2Cdelay();
}

void I2CNoAck_pcf8563(void)          //主机发送
{
		nrf_gpio_cfg_output(IIC_SDA_PCF8563);
    I2Cdelay();
	
    SCL_L_PCF8563;
    I2Cdelay();
    SDA_H_PCF8563;
    I2Cdelay();
    SCL_H_PCF8563;
    I2Cdelay();
    SCL_L_PCF8563;
    I2Cdelay();
}

uint8_t I2CWaitAck_pcf8563(void)            //主机接收
{
		uint16_t i=0;
    SCL_L_PCF8563;	
    I2Cdelay();
	
		nrf_gpio_cfg_input(IIC_SDA_PCF8563,NRF_GPIO_PIN_NOPULL);
    I2Cdelay();
	
    SCL_H_PCF8563;
    I2Cdelay();
		while((SDA_read_pcf8563)&&(i<100))
		{
				i++;
				I2Cdelay();
		}		
		SCL_L_PCF8563;
		I2Cdelay();
	
    if(i<99)
    {
			return 1;
    }
		else
		{
			return 0;
		}
}

uint8_t I2CSendByte_pcf8563(uint8_t SendByte) //数据从高位到低位
{
		nrf_gpio_cfg_output(IIC_SDA_PCF8563);
		I2Cdelay();
    uint8_t i=0;
		for(i=0;i<8;i++)
		{
			SCL_L_PCF8563;
			I2Cdelay();
			if(SendByte&0x80)
			SDA_H_PCF8563;  
			else 
			SDA_L_PCF8563;   
			SendByte<<=1;
			I2Cdelay();
			SCL_H_PCF8563;
			I2Cdelay();
		}
    SCL_L_PCF8563;
		I2Cdelay();
		if(!I2CWaitAck_pcf8563())
		{
				I2CStop_pcf8563(); return 0;
		}
		else
		{
				return 1; 
		}	
}

uint8_t I2CReceiveByte_pcf8563(void)
{
	
		nrf_gpio_cfg_input(IIC_SDA_PCF8563,NRF_GPIO_PIN_NOPULL);
    I2Cdelay();
	
    uint8_t ReceiveByte=0;

    uint8_t i=0;
		for(i=0;i<8;i++)
    {
      ReceiveByte<<=1;         
      SCL_L_PCF8563;
      I2Cdelay();
      SCL_H_PCF8563;
      I2Cdelay();	
      if(SDA_read_pcf8563)
      {
        ReceiveByte|=0x1;
      }
    }
    SCL_L_PCF8563;
		I2Cdelay();	
    return ReceiveByte;   
}

uint8_t I2CWriteSerial_pcf8563(uint8_t DeviceAddress, uint16_t Address, uint8_t *ps, uint8_t length)
{

		I2CStart_pcf8563();
		I2CSendByte_pcf8563(DeviceAddress);   
		I2CSendByte_pcf8563(Address/256);
		I2CSendByte_pcf8563(Address%256);
		uint8_t i=0;
		for(i=0;i<length;i++)
		{ 	
				I2CSendByte_pcf8563(*(ps++));							
		}
		I2CStop_pcf8563(); 

		return	1;
}

uint8_t I2CReadSerial_pcf8563(uint8_t DeviceAddress, uint16_t Address, uint8_t *ps, uint8_t length)
{
		I2CStart_pcf8563();
		I2CSendByte_pcf8563(DeviceAddress);      
		I2CSendByte_pcf8563(Address/256);
		I2CSendByte_pcf8563(Address%256);
		I2CStart_pcf8563();	
		I2CSendByte_pcf8563(DeviceAddress+1);
    uint8_t i=0;
		for(i=0;i<length-1;i++)
		{
			*(ps+i) = I2CReceiveByte_pcf8563();
			I2CAck_pcf8563();
		}
		*(ps+i) = I2CReceiveByte_pcf8563();	
		I2CNoAck_pcf8563();
		I2CStop_pcf8563(); 
		return	1;
}

/*********************************************END OF FILE**********************/
