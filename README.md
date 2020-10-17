# PCT2075-driver
This is super lite HAL driver for PCT2075 temperature sensor

To make this work you need to write your device specific i2c communication layer in PCT2075.c file
according to its datasheet: https://www.nxp.com/docs/en/data-sheet/PCT2075.pdf

To read the temperature you need to implement only PTC2075readWord function

Eventualy I will implement all the functionality but now you can:
  * Get temperature in Celcius or Fahrenheit
  * Shut it down 
  * Wake it up

This code tested with Nuvoton NANO130SE3BN
