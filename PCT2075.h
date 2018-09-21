#ifndef PCT2075_H
#define PCT2075_H

// Include your device specific libraries
#include "config.h"
#include "i2c_driver.h"

#define PCT2075_TEMP_REG 	0
#define PCT2075_CONF_REG 	1
#define PCT2075_THYST_REG 2
#define PCT2075_TOS_REG 	3
#define PCT2075_TIDLE_REG 4

#define PCT2075_OS_F_QUE_1 	(0b00 << 3)
#define PCT2075_OS_F_QUE_2	(0b01 << 3)
#define PCT2075_OS_F_QUE_4	(0b10 << 3)
#define PCT2075_OS_F_QUE_6	(0b11 << 3)

#define PCT2075_OS_POL_MASK 			(1 << 2)
#define PCT2075_OS_COMP_INT_MASK 	(1 << 1)
#define PCT2075_OS_SHUTDOWN_MASK 	(1 << 0)

float PTC2075readTemperature(uint8_t device_addr);

void PTC2075writeByte(uint8_t device_addr, uint8_t pointer, uint8_t data_byte);
uint8_t PTC2075readByte(uint8_t device_addr, uint8_t pointer);

void PTC2075writeWord(uint8_t device_addr, uint8_t pointer, uint16_t data_word);
uint16_t PTC2075readWord(uint8_t device_addr, uint8_t pointer);

void PTC2075shutDown(uint8_t device_addr);
void PTC2075wakeUp(uint8_t device_addr);

#endif /* PCT2075_H */