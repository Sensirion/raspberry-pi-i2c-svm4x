# Sensirion Raspberry Pi I2C SVM41 Driver

This document explains how to set up the [SEK-SVM41](https://www.sensirion.com/my-sgp-ek/) sensor module to run on a
Raspberry Pi using the provided code.

[<center><img src="images/SVM4x.png" width="500px"></center>](https://www.sensirion.com/my-sgp-ek/)

## Setup Guide

### Connecting the Sensor

Your sensor has the five different connectors: VCC, GND, SDA, SCL, SEL (the sixth connector will not be used for now).
Use the following pins to connect your SVM41:

*SVM41*  |    *Raspberry Pi*            |   *Jumper Wire*   |
 :------: | :-------------------------: | :---------------: |
VCC    |        Pin 1 or 2 (3.3V or 5V) |   Red             |
GND    |        Pin 6                   |   Black           |
SDA    |        Pin 3                   |   Green           |
SCL    |        Pin 5                   |   Yellow          |
SEL    |        Pin 9 (GND for I2C)     |   Blue            |

<center><img src="images/GPIO-Pinout-Diagram.png" width="900px"></center>

If you don't have a suitable cable at hand, please find the SEK-SVM41 pinout listed below, or in
the [technical documentation](https://www.sensirion.com/fileadmin/user_upload/customers/sensirion/Dokumente/9_Gas_Sensors/Sensirion_Gas_Sensors_SEK-SVM41_Technical_Description_D1.pdf):

| *Pin* | *Cable Color* | *Name* | *Description* | *Comments* |
|-------|---------------|--------|---------------|------------|
| 1     | Red           | VDD    | Supply Voltage | 3.3 or 5.0 V
| 2     | Black         | Ground |
| 3     | Green         | RX     | UART: Receiving pin for communication |
|       |               | SDA    | I2C: Serial data, bidirectional |
| 4     | Yellow        | TX     | UART: Transmission pin for communication |
|       |               | SCL    | I2C: Serial clock |
| 5     | Blue          | SEL    | Interface select | Leave floating or pull to VDD to select UART
|       |               |        |  | Pull to GND to select I2C
| 6     | Purple        | NC     | Do not connect |

### Raspberry Pi

- [Install the Raspberry Pi OS on to your Raspberry Pi](https://projects.raspberrypi.org/en/projects/raspberry-pi-setting-up)
- [Enable the I2C interface in the raspi-config](https://www.raspberrypi.org/documentation/configuration/raspi-config.md)
- Download the driver for the [Sensirion Github Page](https://github.com/Sensirion/raspberry-pi-i2c-SVM41) and extract
  the `.zip` on your Raspberry Pi
- Compile the driver
    1. Open a [terminal](https://www.raspberrypi.org/documentation/usage/terminal/?)
    2. Navigate to the driver directory. E.g. `cd ~/raspberry-pi-i2c-svm41`
    3. Run the `make` command to compile the driver

       Output:
       ```
       rm -f svm41_i2c_example_usage
       cc -Os -Wall -fstrict-aliasing -Wstrict-aliasing=1 -Wsign-conversion -fPIC -I. -o svm41_i2c_example_usage  svm41_i2c.h svm41_i2c.c sensirion_i2c_hal.h sensirion_i2c.h sensirion_i2c.c \
         sensirion_i2c_hal.c sensirion_config.h sensirion_common.h sensirion_common.c svm41_i2c_example_usage.c
       ```
- Test your connected sensor
    - Run `./svm41_i2c_example_usage` in the same directory you used to compile the driver.

      Output:
      ```
      Serial number: 0FA3F1F7000003392A3D0240
      Firmware: 3.0 Debug: 0
      Hardware: 3.0
      Protocol: 1.0
      Temperature Offset: 0.00 °C
      Humidity: 47.34 % RH
      Temperature: 28.95 °C
      VOC index: 101.0 VOC index
      NOx index: 1.0 NOx index
      Humidity: 47.35 % RH
      Temperature: 28.98 °C
      VOC index: 101.0 VOC index
      NOx index: 1.0 NOx index
      ...
      ```

## Troubleshooting

### Initialization failed

- Ensure that you connected the sensor correctly: All cables are fully plugged in and connected to the correct pin.
- Ensure that I2C is enabled on the Raspberry Pi. For this redo the steps on
  "Enable the I2C interface in the raspi-config" in the guide above.
- Ensure that your user account has read and write access to the I2C device. If it only works with user
  root (`sudo ./svm41_i2c_example_usage`), it's typically due to wrong permission settings.
