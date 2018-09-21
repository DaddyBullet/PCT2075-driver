#include "PCT2075.h"

float PCT2075readTemperature(uint8_t device_addr)
{
	float result_temperature = 85;
  // Reading the temerature regiser
  int16_t temp_word = (int16_t)PTC2075readWord(device_addr, PCT2075_TEMP_REG);
	temp_word >>= 5;

	// Make temperature data true negative if it is
	if(temp_word & (1 << 10))
	{
		temp_word |= (0b11111 << 11);
	}

  // Convert to degrees
  result_temperature = (float)temp_word * 0.125;
#ifdef FAHRENHEIT
  result_temperature = result_temperature * 1.8 + 32;
#endif /* FAHRENHEIT */
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
  /*
    TODO: Write your device specific i2c comunication
  */
	return;
}

uint8_t PTC2075readByte(uint8_t device_addr, uint8_t pointer)
{
	uint8_t retval = 0xFF;
  /*
    TODO: Write your device specific i2c comunication
  */
	return retval;
}

void PTC2075writeWord(uint8_t device_addr, uint8_t pointer, uint16_t data_word)
{
  /*
    TODO: Write your device specific i2c comunication
  */
	return;
}

uint16_t PTC2075readWord(uint8_t device_addr, uint8_t pointer)
{
	uint16_t retval = 0xFFFF;
  /*
    TODO: Write your device specific i2c comunication
  */
	return 	retval;
}
