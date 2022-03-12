/** @file
 *  @brief types used in the system
 */

#ifndef _TYPES_H_
#define _TYPES_H_

#include <stdint.h>

/** @brief common return type in system */
typedef enum
{
    RET_OK = 0, //!< Operation successful
    RET_NOK, //!< Operation failed
} return_t;


/** @brief The available for ADC channels. */
typedef enum {
  ADC_CHANNEL0,
  ADC_CHANNEL1,
  ADC_NUM_CHANNELS
} adc_channel_id_t;

/** @brief Type for ADC values. 
 *  @note resolution of ADC value shall be in 0.1 Volt for proper functioning*/
typedef uint16_t adc_value_t;

/** @brief Type for Speed values 
 *  @note the graph provided has only values 0 and 50 so it is assumed that the speed has values in this interval
 */
typedef uint16_t speed_val_t;

/** @brief Type for percent 
 *  @note can have values between [0-100]
 */
typedef uint8_t percent_t;

/** @brief Type for torque value */
typedef int16_t trq_val_t;

#endif