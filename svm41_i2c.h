/*
 * THIS FILE IS AUTOMATICALLY GENERATED
 *
 * I2C-Generator: 0.2.0
 * Yaml Version: 0.4.0
 * Template Version: 0.7.0-20-gf035cde
 */
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

#ifndef SVM41_I2C_H
#define SVM41_I2C_H

#ifdef __cplusplus
extern "C" {
#endif

#include "sensirion_config.h"

/**
 * svm41_start_measurement() - Starts measurement in polling mode.
 *
 * @note This command is only available in idle mode.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t svm41_start_measurement(void);

/**
 * svm41_stop_measurement() - Stops the measurement mode and returns to idle
 * mode.
 *
 * @note This command is only available in measurement mode.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t svm41_stop_measurement(void);

/**
 * svm41_read_measured_values_as_integers() - Returns the new measurement
 * results as integers.
 *
 * @note This command is only available in measurement mode. The firmware
 * updates the measurement values every second. Polling data with a faster
 * sampling rate will return the same values. The first measurement is available
 * 1 second after the start measurement command is issued. Any readout prior to
 * this will return zero initialized values.
 *
 * @param humidity Compensated ambient humidity in % RH with a scaling factor of
 * 100.
 *
 * @param temperature Compensated ambient temperature in degrees celsius with a
 * scaling of 200.
 *
 * @param voc_index VOC algorithm output with a scaling value of 10.
 *
 * @param nox_index NOx algorithm output with a scaling value of 10.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t svm41_read_measured_values_as_integers(int16_t* humidity,
                                               int16_t* temperature,
                                               int16_t* voc_index,
                                               int16_t* nox_index);

/**
 * svm41_read_measured_values() - Returns the new measurement
 * results.
 *
 * @note This command is only available in measurement mode. The firmware
 * updates the measurement values every second. Polling data with a faster
 * sampling rate will return the same values. The first measurement is available
 * 1 second after the start measurement command is issued. Any readout prior to
 * this will return zero initialized values.
 *
 * @param humidity Compensated ambient humidity in % RH.
 *
 * @param temperature Compensated ambient temperature in degrees celsius.
 *
 * @param voc_index VOC algorithm output.
 *
 * @param nox_index NOx algorithm output.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t svm41_read_measured_values(float* humidity, float* temperature,
                                   float* voc_index, float* nox_index);

/**
 * svm41_read_measured_raw_values() - Returns the measured raw values.
 *
 * @note This command is only available in measurement mode. The firmware
 * updates the measurement values every second. Polling data with a faster
 * sampling rate will return the same values. The first measurement is available
 * 1 second after the start measurement command is issued. Any readout prior to
 * this will return zero initialized values.
 *
 * @param raw_humidity Uncompensated raw humidity in % RH as read from the SHT40
 * with a scaling factor of 100.
 *
 * @param raw_temperature Uncompensated raw temperature in degrees celsius as
 * read from the SHT40 with a scaling of 200.
 *
 * @param raw_voc_ticks Raw VOC output ticks as read from the SGP sensor.
 *
 * @param raw_nox_ticks Raw NOx output ticks as read from the SGP sensor.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t svm41_read_measured_raw_values(int16_t* raw_humidity,
                                       int16_t* raw_temperature,
                                       uint16_t* raw_voc_ticks,
                                       uint16_t* raw_nox_ticks);

/**
 * svm41_set_temperature_offset_for_rht_measurements_ticks() - Sets the T-Offset
 * for the temperature compensation of the RHT algorithm.
 *
 * @param t_offset Temperature offset in degrees celsius with a scaling of 200.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t
svm41_set_temperature_offset_for_rht_measurements_ticks(int16_t t_offset);

/**
 * svm41_set_temperature_offset_for_rht_measurements() - Sets the T-Offset for
 * the temperature compensation of the RHT algorithm.
 *
 * @param t_offset Temperature offset in degrees celsius.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t svm41_set_temperature_offset_for_rht_measurements(float t_offset);

/**
 * svm41_get_temperature_offset_for_rht_measurements_ticks() - Gets the T-Offset
 * for the temperature compensation of the RHT algorithm.
 *
 * @param t_offset Temperature offset in degrees celsius with a scaling of 200.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t
svm41_get_temperature_offset_for_rht_measurements_ticks(int16_t* t_offset);

/**
 * svm41_get_temperature_offset_for_rht_measurements() - Gets the T-Offset for
 * the temperature compensation of the RHT algorithm.
 *
 * @param t_offset Temperature offset in degrees celsius.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t svm41_get_temperature_offset_for_rht_measurements(float* t_offset);

/**
 * svm41_set_voc_algorithm_tuning_parameters() - Sets the parameters to
 * customize the VOC algorithm. This command is only available in idle mode.
 *
 * @param voc_index_offset VOC index representing typical (average) conditions.
 * The default value is 100.
 *
 * @param learning_time_offset_hours Time constant to estimate the VOC Algorithm
 * offset from the history in hours. Past events will be forgotten after about
 * twice the learning time. The default value is 12 hours.
 *
 * @param learning_time_gain_hours Time constant to estimate the VOC Algorithm
 * gain from the history in hours. Past events will be forgotten after about
 * twice the learning time. The default value is 12 hours.
 *
 * @param gating_max_duration_minutes Maximum duration of gating in minutes
 * (freeze of estimator during high VOC index signal). Set to zero to disable
 * the gating. The default value is 180 minutes.
 *
 * @param std_initial Initial estimate for standard deviation. Lower value
 * boosts events during initial learning period, but may result in larger
 * device-to-device variations. The default value is 50.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t svm41_set_voc_algorithm_tuning_parameters(
    int16_t voc_index_offset, int16_t learning_time_offset_hours,
    int16_t learning_time_gain_hours, int16_t gating_max_duration_minutes,
    int16_t std_initial);

/**
 * svm41_get_voc_algorithm_tuning_parameters() - Gets the currently set
 * parameters for customizing the VOC algorithm
 *
 * @param voc_index_offset VOC index representing typical (average) conditions.
 * The default value is 100.
 *
 * @param learning_time_offset_hours Time constant to estimate the VOC Algorithm
 * offset from the history in hours. Past events will be forgotten after about
 * twice the learning time. The default value is 12 hours.
 *
 * @param learning_time_gain_hours Time constant to estimate the VOC Algorithm
 * gain from the history in hours. Past events will be forgotten after about
 * twice the learning time. The default value is 12 hours.
 *
 * @param gating_max_duration_minutes Maximum duration of gating in minutes
 * (freeze of estimator during high VOC index signal). Zero disables the gating.
 * The default value is 180 minutes.
 *
 * @param std_initial Initial estimate for standard deviation. Lower value
 * boosts events during initial learning period, but may result in larger
 * device-to-device variations. The default value is 50.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t svm41_get_voc_algorithm_tuning_parameters(
    int16_t* voc_index_offset, int16_t* learning_time_offset_hours,
    int16_t* learning_time_gain_hours, int16_t* gating_max_duration_minutes,
    int16_t* std_initial);

/**
 * svm41_set_nox_algorithm_tuning_parameters() - Sets the parameters to
 * customize the NOx algorithm. This command is only available in idle mode.
 *
 * @param nox_index_offset NOx index representing typical (average) conditions.
 * The default value is 1.
 *
 * @param learning_time_offset_hours Time constant to estimate the NOx Algorithm
 * offset from the history in hours. Past events will be forgotten after about
 * twice the learning time. The default value is 12 hours.
 *
 * @param learning_time_gain_hours Time constant to estimate the NOx Algorithm
 * gain from the history in hours. Past events will be forgotten after about
 * twice the learning time. The default value is 12 hours.
 *
 * @param gating_max_duration_minutes Maximum duration of gating in minutes
 * (freeze of estimator during high NOx index signal). Set to zero to disable
 * the gating. The default value is 30 minutes.
 *
 * @param std_initial Initial estimate for standard deviation. Lower value
 * boosts events during initial learning period, but may result in larger
 * device-to-device variations. The default value is 50.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t svm41_set_nox_algorithm_tuning_parameters(
    int16_t nox_index_offset, int16_t learning_time_offset_hours,
    int16_t learning_time_gain_hours, int16_t gating_max_duration_minutes,
    int16_t std_initial);

/**
 * svm41_get_nox_algorithm_tuning_parameters() - Gets the currently set
 * parameters for customizing the NOx algorithm
 *
 * @param nox_index_offset NOx index representing typical (average) conditions.
 * The default value is 1.
 *
 * @param learning_time_offset_hours Time constant to estimate the NOx Algorithm
 * offset from the history in hours. Past events will be forgotten after about
 * twice the learning time. The default value is 12 hours.
 *
 * @param learning_time_gain_hours Time constant to estimate the NOx Algorithm
 * gain from the history in hours. Past events will be forgotten after about
 * twice the learning time. The default value is 12 hours.
 *
 * @param gating_max_duration_minutes Maximum duration of gating in minutes
 * (freeze of estimator during high NOx index signal). Zero disables the gating.
 * The default value is 30 minutes.
 *
 * @param std_initial Initial estimate for standard deviation. Lower value
 * boosts events during initial learning period, but may result in larger
 * device-to-device variations. The default value is 50.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t svm41_get_nox_algorithm_tuning_parameters(
    int16_t* nox_index_offset, int16_t* learning_time_offset_hours,
    int16_t* learning_time_gain_hours, int16_t* gating_max_duration_minutes,
    int16_t* std_initial);

/**
 * svm41_store_nv_data() - Stores all algorithm parameters to the non-volatile
 * memory.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t svm41_store_nv_data(void);

/**
 * svm41_set_voc_algorithm_state() - Sets the VOC algorithm state. This command
 * is only available in idle mode.
 *
 * @param state Current VOC algorithm state.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t svm41_set_voc_algorithm_state(const uint8_t* state, uint8_t state_size);

/**
 * svm41_get_voc_algorithm_state() - Gets the current VOC algorithm state.
 *
 * @param state Current VOC algorithm state.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t svm41_get_voc_algorithm_state(uint8_t* state, uint8_t state_size);

/**
 * svm41_set_nox_algorithm_state() - Sets the NOx algorithm state. This command
 * is only available in idle mode.
 *
 * @param state Current NOx algorithm state.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t svm41_set_nox_algorithm_state(const uint8_t* state, uint8_t state_size);

/**
 * svm41_get_nox_algorithm_state() - Gets the current NOx algorithm state.
 *
 * @param state Current NOx algorithm state.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t svm41_get_nox_algorithm_state(uint8_t* state, uint8_t state_size);

/**
 * svm41_get_version() - Gets the version information for the hardware, firmware
 * and protocol.
 *
 * @param firmware_major Firmware major version number.
 *
 * @param firmware_minor Firmware minor version number.
 *
 * @param firmware_debug Firmware debug state. If the debug state is set, the
 * firmware is in development.
 *
 * @param hardware_major Hardware major version number.
 *
 * @param hardware_minor Hardware minor version number.
 *
 * @param protocol_major Protocol major version number.
 *
 * @param protocol_minor Protocol minor version number.
 *
 * @param padding Padding byte, ignore this.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t svm41_get_version(uint8_t* firmware_major, uint8_t* firmware_minor,
                          bool* firmware_debug, uint8_t* hardware_major,
                          uint8_t* hardware_minor, uint8_t* protocol_major,
                          uint8_t* protocol_minor);

/**
 * svm41_get_serial_number() - Gets the serial number from the device.
 *
 * @param serial_number Ascii string containing the serial number. The string
 * has the null-termination character included.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t svm41_get_serial_number(unsigned char* serial_number,
                                uint8_t serial_number_size);

/**
 * svm41_device_reset() - Executs a reset on the device.
 *
 * @note The device will reply before executing the reset.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t svm41_device_reset(void);

#ifdef __cplusplus
}
#endif

#endif /* SVM41_I2C_H */
