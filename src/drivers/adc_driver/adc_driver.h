/** @file
 *  @brief Header file for a (dummy) ADC driver.
 */
#ifndef DRIVERS_ADC_DRIVER_ADC_DRIVER_H_
#define DRIVERS_ADC_DRIVER_ADC_DRIVER_H_

#include "../../types.h"


/** @brief Initializes the ADC channel.
 *  @param[in] id The ID of the ADC channel.
 *  @returns Whether the channel was initialized successfully or not.
 */
return_t adc_init(adc_channel_id_t id);

/** @brief Reads the value of the ADC channel.
 *  @param[in] id The ID of the ADC channel.
 *  @param[out] value The read ADC value, which is a value between 0 and 1023.
 *  @returns Whether the channel was initialized successfully or not.
 */
return_t adc_read(adc_channel_id_t id, adc_value_t* value);

/** @brief Helper function for setting what is returned by adc_read().
 *  @param[in] id The ID of the ADC channel you want to specify the adc_read()
 *    output for..
 *  @param[in] value The value that is assigned to the ADC value output.
 *  @param[in] return_value The value that is returned by adc_read().
 *  @note This is just some code for manual mocking that can help you with
 *    testing!
 */
void adc_read_set_output(adc_channel_id_t id, adc_value_t value,
                         return_t return_value);


#endif  // DRIVERS_ADC_DRIVER_ADC_DRIVER_H_
