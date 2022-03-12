/** @file
 *  @brief Header file for torque calculator 
 */

#ifndef _TORQUE_CALC_H_
#define _TORQUE_CALC_H_

#include "../../types.h"

/** @brief calculates the torque value using data coming form 2 different adc channels, and speed value
 *  @param[in] throttle_angle_percent_adc0 percent of throttle pedal angle for adc 1
 *  @param[in] throttle_angle_percent_adc1 percent of throttle pedal angle for adc 2
 *  @param[in] speed the current speed of the vehicle
 *  @param[out] val_out the calculated torque 
 *  @note this function can provide capability to weigh adc selections differently in the implementation
 */
return_t calc_torque_d(
	uint8_t throttle_angle_percent_adc0, 
	uint8_t throttle_angle_percent_adc1, 
	speed_val_t speed,
	trq_val_t* val_out);

/** @brief calculates the torque value using data coming form single adc channel, and speed value
 *  @param[in] throttle_angle_percent percent of throttle pedal angle for adc 1
 *  @param[in] speed the current speed of the vehicle
 *  @param[out] val_out the calculated torque 
 */
return_t calc_torque(
	uint8_t throttle_angle_percent,
	speed_val_t speed,
	trq_val_t* val_out);



#endif // _TORQUE_CALC_H_
