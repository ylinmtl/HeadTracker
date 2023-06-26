#pragma once

#include <stdint.h>

#include "boardsdefs.h"

// Pull up pin mode
#define INPUT_PULLUP (GPIO_INPUT | GPIO_PULL_UP)

// Board Features
#define HAS_3DIODE_RGB
#define HAS_NOTIFYLED
#define HAS_MPU6500
#define HAS_CENTERBTN
#define HAS_PPMIN
#define HAS_PPMOUT

// Pins (name, number, description)
// NOTE: These pins are an enum entry. e.g. IO_D2 = 0
//     - Use PIN_NAME_TO_NUM(IO_D2) to get actual the pin number
//     - The pin number can be converted back into the NRF port/pin
//       using functions PIN_TO_NRFPORT & PIN_TO_NRFPIN
//     - The string descrition for D2 would be StrPins[IO_D2]

#define PIN_X \
  PIN(CENTER_BTN,   NRFPIN(0,  2), "J5-4[A0] Center Button") \
  PIN(SPICS,        NRFPIN(0,  3), "J3-5 SPI CS") \
  PIN(PPMOUT,       NRFPIN(0, 28), "J5-3[A2] PPM OUT") \
  PIN(PPMIN,        NRFPIN(0, 29), "J5-2[A4] PPM IN") \
  PIN(SDA,          NRFPIN(0,  4), "J2-3 I2C SDA") \
  PIN(SCL,          NRFPIN(0,  5), "J2-5 I2C SCL") \
  PIN(TX,           NRFPIN(1, 11), "J1-3 UART TX") \
  PIN(RX,           NRFPIN(1, 12), "J1-2 UART RX") \
  PIN(EXT_SCK,      NRFPIN(1, 13), "J3-2 SPI CLOCK") \
  PIN(EXT_MISO,     NRFPIN(1, 14), "J3-3 SPI MISO") \
  PIN(EXT_MOSI,     NRFPIN(1, 15), "J3-4 SPI MOSI") \
  PIN(LEDR,         NRFPIN(0, 26), "Red LED") \
  PIN(LEDG,         NRFPIN(0, 30), "Green LED") \
  PIN(LEDB,         NRFPIN(0,  6), "Blue LED") \
  PIN(LED,          NRFPIN(0, 14), "Notification LED") \
  PIN(TXINV,        NRFPIN(0, 19), "UART TX, Inv Pin") \
  PIN(RXINVO,       NRFPIN(0, 10), "UART RX, Out Inv") \
  PIN(RXINVI,       NRFPIN(0,  9), "UART RX, Inp Inv") \
  PIN(AN0,          NRFPIN(0, 31), "Analog Battery Voltage") \
  PIN(ANBATT_ENA,   NRFPIN(0, 14), "Battery Monitor Enable") \
  PIN(SCK,          NRFPIN(0, 21), "SPI Clock - Flash") \
  PIN(MOSI,         NRFPIN(0, 20), "SPI Data Out - Flash") \
  PIN(MISO,         NRFPIN(0, 24), "SPI Data In - Flash") \
  PIN(FLSH_WP,      NRFPIN(0, 22), "Flash Write Protect") \
  PIN(FLSH_HLD,     NRFPIN(0, 23), "Flash Hold") \
  PIN(LSM6DS3PWR,   NRFPIN(1,  8), "LSM6DS3 Power 6DPWR") \
  PIN(LSM6DS3INT,   NRFPIN(0, 11), "LSM6DS3 Interrupt") \
  PIN(I2CSCL,       NRFPIN(0, 27), "I2C - SCL") \
  PIN(I2CSDA,       NRFPIN(0,  7), "I2C - SDA") \
  END_IO_PINS \

typedef enum {
#define PIN(NAME, PINNO, DESC) IO_##NAME,
  PIN_X
#undef PIN
} pins_e;

const int8_t PinNumber[] = {
#define PIN(NAME, PINNO, DESC) PINNO,
    PIN_X
#undef PIN
};

// Required pin setting functions
#define pinMode(pin, mode) gpio_pin_configure(gpios[PIN_TO_NRFPORT(PIN_NAME_TO_NUM(pin))], PIN_TO_NRFPIN(PIN_NAME_TO_NUM(pin)), mode)
#define digitalWrite(pin, value) gpio_pin_set(gpios[PIN_TO_NRFPORT(PIN_NAME_TO_NUM(pin))], PIN_TO_NRFPIN(PIN_NAME_TO_NUM(pin)), value)
#define digitalRead(pin) gpio_pin_get(gpios[PIN_TO_NRFPORT(PIN_NAME_TO_NUM(pin))], PIN_TO_NRFPIN(PIN_NAME_TO_NUM(pin)))

// TODO Find good values here
// Values below were determined by plotting Gyro Output (See sense.cpp, gyroCalibration())
#define GYRO_STABLE_DIFF 200.0f
#define ACC_STABLE_DIFF 2.5f
