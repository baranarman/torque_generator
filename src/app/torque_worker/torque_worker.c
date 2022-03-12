#include "torque_worker.h"
#include <stdbool.h>
#include <stdio.h>

#include "../../algo/torque_calculator/torque_calc.h"

// instead of linking mathlib i wrote my rounder
int toInt(float val)
{
	return (val < 0) ? (val - 0.5) : (val + 0.5);
}

bool get_throttle_angle_percent(adc_channel_id_t id, uint8_t* percent)
{
	// read values of adc's from the drivers
	return_t adc_read_result = RET_NOK;
	adc_value_t adc_val = 0;
	adc_value_t mac_val = 0;
	return_t mac_ret = RET_NOK;
	percent_t percent_tmp = 0;

	bool is_read_successful = false;
	bool is_mac_successful = false;

	int throttle_angle = 0;

	bool result = false;

	adc_read_result = adc_read(id, &adc_val);
	// printf("adc_read_result: %d \n", adc_val);
	if ( adc_read_result == RET_OK)
	{
		is_read_successful = true;
	}
	else
	{
		error("ADC read failed"); // TODO string shall include ADC number
	}

	// is_mac_successful feed them to mac and get mac value
	if ( is_read_successful )
	{

		// put them into voltage to angle converter
		throttle_angle = convert_adc_to_degree(id, adc_val);
		// printf("throttle angle: %d \n", throttle_angle);
		// calculate the percent of pedal angle	
		percent_tmp = toInt((throttle_angle / 30.0) * 100.0); 
		// printf("percent: %d \n", percent_tmp);		

		mac_ret = get_adc_ma(id, percent_tmp, &mac_val);
		if (mac_ret == RET_OK)
		{
			is_mac_successful = true;
			// printf("mat_read_result = %d \n", mac_val);
			*percent = mac_val;
		}
		else
		{
			error("MAC read failed"); // todo include adc number
		}
	}

	if ( is_mac_successful )
	{
		result = true;
	}

	return result;
}


return_t getTorque(trq_val_t* torque_val)
{
	return_t return_val = RET_NOK;

	bool throttle_percent_ok_adc0 = false;
	bool throttle_percent_ok_adc1 = false;
	uint8_t throttle_percent_adc0 = 0;
	uint8_t throttle_percent_adc1 = 0;

	speed_val_t speed_val = 0;
	return_t speed_ret = RET_NOK;



	// get speed
	bool is_speed_read_ok = false;
	speed_ret = speed_read(&speed_val);
	if (speed_ret == RET_OK)
	{
		is_speed_read_ok = true;
	}
	else
	{
		error("getTorque speed read failed");
		return_val = RET_NOK;
	}
	
	
	// get throttle angle from adcs
	if ( is_speed_read_ok )
	{
		throttle_percent_ok_adc0 =  get_throttle_angle_percent(ADC_CHANNEL0, &throttle_percent_adc0);
		throttle_percent_ok_adc1 =  get_throttle_angle_percent(ADC_CHANNEL1, &throttle_percent_adc1);
	}


	// using the speed and adc values call the torque calculator function

	if ( (throttle_percent_ok_adc0 == true) && (throttle_percent_ok_adc0 == true) )
	{
		return_val = calc_torque_d( 
			throttle_percent_adc0,
			throttle_percent_adc1,
			speed_val,
			torque_val);
	}
	else if  ( (throttle_percent_ok_adc0 == true) && (throttle_percent_ok_adc0 == false) )
	{
		return_val = calc_torque( 
			throttle_percent_adc0,
			speed_val,
			torque_val);
	}
	else if  ( (throttle_percent_ok_adc0 == false) && (throttle_percent_ok_adc0 == true) )
	{
		return_val = calc_torque( 
			throttle_percent_adc1,
			speed_val,
			torque_val);
	}
	else
	{
		// throttle percent failed 
		// no need for error as value is returned
	}


	// printf("getTorque ret: %s, val: %d \n",
	// 	(return_val == RET_OK)?("RET_OK"):("RET_NOK"),
	// 	*torque_val);
	return return_val;

}