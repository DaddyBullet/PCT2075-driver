#ifndef PCT2075_H
#define PCT2075_H

// Uncoment it if you want to recieve data in FAHRENHEIT
// #define FAHRENHEIT

// Include your device specific libraries here
/*
  Your libraries
*/

#define PCT2075_TEMP_REG 	0
#define PCT2075_CONF_REG 	1
#define PCT2075_THYST_REG 2
#define PCT2075_TOS_REG 	3
#define PCT2075_TIDLE_REG 4

#define PCT2075_OS_F_QUE_OFFSET 3
#define PCT2075_OS_F_QUE_1 	(0b00 << PCT2075_OS_F_QUE_OFFSET)
#define PCT2075_OS_F_QUE_2	(0b01 << PCT2075_OS_F_QUE_OFFSET)
#define PCT2075_OS_F_QUE_4	(0b10 << PCT2075_OS_F_QUE_OFFSET)
#define PCT2075_OS_F_QUE_6	(0b11 << PCT2075_OS_F_QUE_OFFSET)

#define PCT2075_OS_POL_MASK 			(1 << 2)
#define PCT2075_OS_COMP_INT_MASK 	(1 << 1)
#define PCT2075_OS_SHUTDOWN_MASK 	(1 << 0)

/* Returns the most recent temperature which was read from the sensor
in defined degrees system*/
/* Note: this function should not be called immediately after POR or wake-up.
The first valid value will be in temperature registr after 28ms*/
/* param: device_addr: sensors i2c bus addres*/
float PTC2075readTemperature(uint8_t device_addr);

/* Puts device into shutdown mode*/
/* param: device_addr: sensors i2c bus addres*/
void PTC2075shutDown(uint8_t device_addr);

/* Puts device into shutdown mode*/
/* param: device_addr: sensors i2c bus addres*/
void PTC2075wakeUp(uint8_t device_addr);


void PTC2075writeByte(uint8_t device_addr, uint8_t pointer, uint8_t data_byte);
uint8_t PTC2075readByte(uint8_t device_addr, uint8_t pointer);
void PTC2075writeWord(uint8_t device_addr, uint8_t pointer, uint16_t data_word);
uint16_t PTC2075readWord(uint8_t device_addr, uint8_t pointer);

#endif /* PCT2075_H */
