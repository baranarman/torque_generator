/** @file 
 *  @brief Source file for torque calculator
 */

#include "torque_calc.h"

#include <stdio.h>
#include "../../error_handler/error_handler.h"

// the resolution is selected to be very low for the TASK purpose
// if this is a real implementation the resolution of this table can be much more higher

#define SPEED_RESOLUTION (2)
#define PERCENT_RESOLUTION (5)

// SPEED STEPS are 0 and 50 -> normally the values between these can be deduced through linear interpolation
// PERCENT RESOLUTION is 
static trq_val_t torque_table[SPEED_RESOLUTION] [PERCENT_RESOLUTION] = 
{  0 /*0km/h-0%*/,  45 /* 0km/h-25%*/, 72 /* 0km/h-50%*/, 100 /* 0km/h-75%*/, 120 /* 0km/h-100%*/ ,
  -30/*50km/h-0%*/, 22 /*50km/h-25%*/, 54 /*50km/h-50%*/, 83  /*50km/h-75%*/, 120 /*50km/h-100%*/ };

return_t calc_torque(
        uint8_t angle,
        speed_val_t speed,
        trq_val_t* val_out)
{
	// printf("calc_torque params: angle: %d, speed: %d \n", angle, speed);
	return_t result = RET_NOK;
	int param_check_ok = 0;
	int percent_resol_step_size = 100 / (PERCENT_RESOLUTION - 1);
	int percent_interval = 0;
	int stop_torque_val = 0;
	int fast_torque_val = 0;
	
	int interval_left_val = 0;
	int interval_right_val = 0;


	// check params
	if ( ( angle <= 100 ) || (speed <= 50) )
	{
		// interpolate wrt angle value
		percent_interval = angle / percent_resol_step_size + \
			( ((angle % percent_resol_step_size) > 0) ? (1) : (0) );
		// if result is 0 so angle is 0
		// if result is 1 so angle is between 0 and 25   ( 0, 25 ]
		// if result is 2 so angle is between 25 and 50  (25, 50 ]
		// if result is 3 so angle is between 50 and 75  (50, 75 ]
		// if result is 4 so angle is between 75 and 100 (75, 100]
		// the result is not expected to be bigger than 4
	
		switch(percent_interval)
		{
		case 0:
			stop_torque_val = torque_table[0][0];
			fast_torque_val = torque_table[1][0];
			break;
		case 1:
		case 2:
		case 3:
		case 4:
			// first calculate for stop speed = 0;
			interval_left_val = torque_table[0][percent_interval - 1];
			interval_right_val = torque_table[0][percent_interval];
			stop_torque_val = interval_left_val + ( (interval_right_val - interval_left_val) / ((float) percent_resol_step_size) ) * (angle - ( (percent_interval - 1) * percent_resol_step_size)); 
			
			// then calculate for high speed = 50
			interval_left_val = torque_table[1][percent_interval - 1];
			interval_right_val = torque_table[1][percent_interval];
			fast_torque_val = interval_left_val + ((interval_right_val - interval_left_val) / ((float) percent_resol_step_size) ) * (angle - ( (percent_interval - 1) * percent_resol_step_size)); 
			
			break;
		default:
			error("calc_torque: incorrect percent interval");
			break;	
		}

		// printf("stop torq val: %d \n",stop_torque_val);
		// printf("fast torq val: %d \n",fast_torque_val);

		// interpolate wrt speed values
		// scale linearly in the interval [0, 50]
		*val_out = stop_torque_val - ((speed) / 50.0) * (stop_torque_val - fast_torque_val);
		// printf("tc val: %d \n", *val_out);
		result = RET_OK;
	}
	else
	{
		error("calc_torque: parameter invalid");
	}
	return result;
}

                               
return_t calc_torque_d(
        uint8_t throttle_angle_percent_adc0,
        uint8_t throttle_angle_percent_adc1,
        speed_val_t speed,
        trq_val_t* val_out)
{
	// printf("calc_torque params: angle0: %d, angle1: %d, speed: %d \n", throttle_angle_percent_adc0, throttle_angle_percent_adc1, speed);
	uint8_t average_percent = (throttle_angle_percent_adc0 + throttle_angle_percent_adc1) / 2 ;
	return_t result = calc_torque(average_percent, speed, val_out);
	
	return result;
}

