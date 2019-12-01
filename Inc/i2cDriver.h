#pragma  once

#include <stdint.h>
#include <stdbool.h>

#define TSL25721_ADDR   	((uint8_t)0x72)
#define HTS221_ADDR   	((uint8_t)0xBE)

enum TSL25721_registers
{
	TSL25721_ENABLE_REGISTER = 0x00,
	TSL25721_ALS_TIME_REGISTER = 0x01,
	TSL25721_WAIT_TIME_REGISTER = 0x03,
	TSL25721_AILTL = 0x04, // ALS Interrupt Threshold Registers (x04 − 0x07) ALS low threshold lower byte
	TSL25721_AILTH = 0x05, // ALS low threshold upper byte
	TSL25721_AIHTL = 0x06, // ALS high threshold lower byte
	TSL25721_AIHTH = 0x07, // ALS high threshold upper byte
	TSL25721_PERSISTANCE_FILTER_REGISTER = 0x0C,
	TSL25721_CONFIGURATION_REGISTER  = 0x0D,
	TSL25721_CONTROL_REGISTER = 0x0F,
	TSL25721_ID_REGISTER = 0x12,
	TSL25721_STATUS_REGISTER = 0x13,
	TSL25721_C0DATA = 0x14, // ADC Channel Data Registers (0x14 − 0x17) ALS CH0 data low byte
	TSL25721_C0DATAH = 0x15, // ALS CH0 data high byte
	TSL25721_C1DATA= 0x16, // ALS CH1 data low byte
	TSL25721_C1DATAH = 0x17, // ALS CH1 data high byte
};

void i2c_driver_init(void);

bool i2cReadReg(uint8_t i2cDeviceAddress, uint8_t i2cRegisterAddres, uint8_t data[], uint16_t len);
bool i2cWriteReg(uint8_t i2cDeviceAddress, uint8_t i2cRegisterAddres, uint8_t data[], uint16_t len);
bool i2cWriteByte(uint8_t i2cDeviceAddress, uint8_t i2cRegisterAddres, uint8_t data);

bool i2cIsDeviceReady(uint8_t i2cDeviceAddress);
