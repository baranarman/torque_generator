/** @file
 *  @brief Header file for Moving Average Calculator (mac). 
 */

#ifndef _MAC_H_
#define _MAC_H_

#include "../../types.h"

#define MAC_WINDOW_WIDTH (5)


/** @brief provides one sample to Moving Average Window, and calculates the new average and returns it
 *  @param[in] id The ID of the ADC channel
 *  @param[in] val_in the new sample coming from adc driver, will be input to the window
 *  @param[out] val_out the new average calculated.
 *  @returns if the calculation is done successfully or not
 */
//return_t get_adc_ma(adc_channel_id_t id, adc_value_t val_in, adc_value_t* val_out);
return_t get_adc_ma(adc_channel_id_t id, int16_t val_in, int16_t* val_out);

/** @brief Helper function for setting what is returned by  get_adc_ma() function
 *  @param[in] id The ID of the ADC channel
 *  @param[in] val_in the value that will be returned by the get_adc_ma() 
 *  @param[in] ret_in the return value that will be returned by the get_adc_ma() function
 */
void set_adc_ma_output(adc_channel_id_t id, int16_t val_in, return_t ret_in);

/** @brief fills all the elements of the ma window with the same value
 *  @param[in] id The ADC channel
 *  @param[in] val_in the value that will be set to all elements in the moving window
 */
void set_adc_ma_window(adc_channel_id_t id, int16_t val_in);

/** @brief resets all the elemtns of the ma window with value = 0
 *  @param[in] id The ADC channel
 */
void reset_adc_ma_window(adc_channel_id_t id);


#endif
