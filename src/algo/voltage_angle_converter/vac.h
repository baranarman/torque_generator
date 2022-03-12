/** @file
 *  @brief Header file for ADC voltage to throttle angle converter - in degrees
 *  @note the equation for ADC0 is: V_ADC0 = (0.5 + 0.1 * Angle(inDegrees))
 *  @note the reverse Angle = (V_ADC0 - 5) / 1
 *  @note the equation for ADC1 is: V_ADC1 = (1.0 + 0.08 * Angle(inDegrees))
 *  @note the reverse Angle = (V_ADC1 - 10) / 0.8
 */

#ifndef _VAC_H_
#define _VAC_H_

#include "../../types.h"

/** @brief ADC voltage to  
 *  @param[in] id ADC channel id
 *  @param[in] val the ADC voltage value that will be converted to angle 
 *  @returns the angle of throttle, in degree units
 */
int convert_adc_to_degree(adc_channel_id_t id, adc_value_t val);

#endif
