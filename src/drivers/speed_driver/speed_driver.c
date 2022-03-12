/** @file 
 *  @brief Source file for Speed driver
 */

#include "speed_driver.h"
#include <stdio.h>

// test support functions
static int            is_mock_set = 0;
static speed_val_t    mock_speed_read_val = 0;
static return_t mock_speed_ret_val = RET_NOK;

return_t speed_init()
{
	printf("[SPD] Initializing speedometer \n");
	return RET_OK;
}

return_t speed_read( speed_val_t* speed)
{
	return_t result = RET_NOK;
	if ( is_mock_set )
	{
		printf("[SPD] reading a value that is mocked [%d - %s] \n", 
			mock_speed_read_val,
			(mock_speed_ret_val == RET_OK) ? ("RET_OK"): ("RET_NOK"));
		result = mock_speed_ret_val;
		*speed = mock_speed_read_val;
		is_mock_set = 0;
	}
	else
	{
		printf("[SPD] reading value through hw interface ? hw not connected in the context of TASK.\n");
		result = RET_NOK;
	}
	
	return result;
}

void 
speed_read_set_output(
	speed_val_t speed_in,
	return_t return_in)
{
	is_mock_set         = 1;
	mock_speed_read_val = speed_in;
	mock_speed_ret_val  = return_in;
}

