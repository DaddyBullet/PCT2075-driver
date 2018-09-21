#include "PCT2075.h"

float PCT2075readTemperature(uint8_t device_addr)
{
	float result_temperature = 85;
	int16_t temp_word = (int16_t)PTC2075readWord(device_addr, PCT2075_TEMP_REG);
	temp_word >>= 5;
	
	// Make temp negative
	if(temp_word & (1 << 10))
	{
		temp_word |= (0b11111 << 11);
	}
	
	result_temperature = (float)temp_word * 0.125;
	return result_temperature;
}

void PTC2075shutDown(uint8_t device_addr)
{
	uint8_t config = 0;
	config = PTC2075readByte(device_addr, PCT2075_CONF_REG);
	config |= PCT2075_OS_SHUTDOWN_MASK;
	PTC2075writeByte(device_addr, PCT2075_CONF_REG, config);
	return;
}

void PTC2075wakeUp(uint8_t device_addr)
{
	uint8_t config = 0;
	config = PTC2075readByte(device_addr, PCT2075_CONF_REG);
	config &= ~PCT2075_OS_SHUTDOWN_MASK;
	PTC2075writeByte(device_addr, PCT2075_CONF_REG, config);
	return;
}

void PTC2075writeByte(uint8_t device_addr, uint8_t pointer, uint8_t data_byte)
{
	i2c_setByte(device_addr, pointer, data_byte);
	return;
}

uint8_t PTC2075readByte(uint8_t device_addr, uint8_t pointer)
{
	uint8_t retval = 0xFF;
	retval = i2c_getByte(device_addr, pointer);
	return retval;
}

void PTC2075writeWord(uint8_t device_addr, uint8_t pointer, uint16_t data_word)
{
	// TODO: Write fast i2c transmition
	uint8_t data[] = {(uint8_t)(data_word >> 8), (uint8_t)data_word};
	return;
}

uint16_t PTC2075readWord(uint8_t device_addr, uint8_t pointer)
{
	uint8_t temp_bytes[2];
	i2c_getDataFast(device_addr, 0, temp_bytes, 2);
	
	uint16_t retval = 0xFFFF;
	retval = (((uint16_t)(temp_bytes[0]) << 8) | temp_bytes[1]);
	return 	retval;
}


