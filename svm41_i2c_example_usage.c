/*
 * Copyright (c) 2021, Sensirion AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of Sensirion AG nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>  // printf

#include "sensirion_common.h"
#include "sensirion_i2c_hal.h"
#include "svm41_i2c.h"

/*
 * TO USE CONSOLE OUTPUT (PRINTF) YOU MAY NEED TO ADAPT THE INCLUDE ABOVE OR
 * DEFINE IT ACCORDING TO YOUR PLATFORM:
 * #define printf(...)
 */

int main(void) {
    int16_t error = 0;

    sensirion_i2c_hal_init();

    error = svm41_device_reset();
    if (error) {
        printf("Error executing svm41_device_reset(): %i\n", error);
    }

    unsigned char serial_number[26];
    uint8_t serial_number_size = 26;
    error = svm41_get_serial_number(serial_number, serial_number_size);
    if (error) {
        printf("Error executing svm41_get_serial_number(): %i\n", error);
    } else {
        printf("Serial number: %s\n", serial_number);
    }

    uint8_t firmware_major;
    uint8_t firmware_minor;
    bool firmware_debug;
    uint8_t hardware_major;
    uint8_t hardware_minor;
    uint8_t protocol_major;
    uint8_t protocol_minor;
    error = svm41_get_version(&firmware_major, &firmware_minor, &firmware_debug,
                              &hardware_major, &hardware_minor, &protocol_major,
                              &protocol_minor);

    if (error) {
        printf("Error executing svm41_get_version(): %i\n", error);
    } else {
        printf("Firmware: %i.%i Debug: %i\n", firmware_major, firmware_minor,
               firmware_debug);
        printf("Hardware: %i.%i\n", hardware_major, hardware_minor);
        printf("Protocol: %i.%i\n", protocol_major, protocol_minor);
    }

    float t_offset;
    error = svm41_get_temperature_offset_for_rht_measurements(&t_offset);
    if (error) {
        printf("Error executing "
               "svm41_get_temperature_offset_for_rht_measurements(): %i\n",
               error);
    } else {
        printf("Temperature Offset: %.2f °C\n", t_offset);
    }

    // Start Measurement
    error = svm41_start_measurement();
    if (error) {
        printf("Error executing svm41_start_measurement(): %i\n", error);
    }

    for (;;) {
        // Read Measurement
        sensirion_i2c_hal_sleep_usec(1000000);
        float humidity;
        float temperature;
        float voc_index;
        float nox_index;
        error = svm41_read_measured_values(&humidity, &temperature, &voc_index,
                                           &nox_index);
        if (error) {
            printf("Error executing svm41_read_measured_values_as_integers(): "
                   "%i\n",
                   error);
        } else {
            printf("Humidity: %.2f %% RH\n", humidity);
            printf("Temperature: %.2f °C\n", temperature);
            printf("VOC index: %.1f VOC index\n", voc_index);
            printf("NOx index: %.1f NOx index\n", nox_index);
        }
    }

    error = svm41_stop_measurement();

    if (error) {
        printf("Error executing svm41_stop_measurement(): %i\n", error);
    }

    return 0;
}
