/** @file
 *  @brief Source file for Moving Average Calculator (mac)
 */

#include "mac.h"
#include <stdio.h>
#include "../../error_handler/error_handler.h"

// test support variables
static int      is_mock_set[ADC_NUM_CHANNELS]  = {0, 0};
static int16_t  mock_mac_val[ADC_NUM_CHANNELS] = {0, 0};
static return_t mock_ret_val[ADC_NUM_CHANNELS] = {RET_NOK, RET_NOK};

// windows for different adc channels -> shall be kept seperately
static int16_t  window[ADC_NUM_CHANNELS] [MAC_WINDOW_WIDTH] = {0};
static int32_t  window_sum[ADC_NUM_CHANNELS]                = {0, 0};
static uint16_t cur_index[ADC_NUM_CHANNELS]                 = {0, 0};

return_t 
get_adc_ma(
	adc_channel_id_t id,
	int16_t val_in,
	int16_t* val_out)
{
	return_t result = RET_NOK;
	int index = 0;
	// printf("channel: %s, input: %d \n", (id == ADC_CHANNEL0)? ("ADC_CHANNEL0"):("ADC_CHANNEL1"), val_in) ;
	if (is_mock_set[id])
	{
		// printf("[MOC] reading a value that is mocked [%d - %s] \n",
		// 	mock_mac_val[id],
		// 	(mock_ret_val[id] == RET_OK)? ("RET_OK") : ("RET_NOK"));
		result = mock_ret_val[id];
		*val_out = mock_mac_val[id];
		is_mock_set[id] = 0;
	}
	else
	{
		// insert value to window
		window[id][cur_index[id]] = val_in;
		cur_index[id]++;
		cur_index[id] %= MAC_WINDOW_WIDTH;
		
		// calculate the new average
		window_sum[id] = 0;
		for (index = 0; index < MAC_WINDOW_WIDTH; index++)
		{
			window_sum[id] += window[id][index];
		}
		
		// return the average value

		*val_out = window_sum[id] / MAC_WINDOW_WIDTH;
		// printf("mac out: %d\n", *val_out);
		result = RET_OK;
	}
	return result;
}


void 
set_adc_ma_output(
	adc_channel_id_t id,
	int16_t val_in,
	return_t ret_in)
{
	is_mock_set[id] = 1;
	mock_mac_val[id] = val_in;
	mock_ret_val[id] = ret_in;
}

void 
set_adc_ma_window(
	adc_channel_id_t id, 
	int16_t val_in)
{
	int index = 0;

	switch( id ){

	case 0:
	case 1:
		for (index = 0; index < MAC_WINDOW_WIDTH; index++)	
		{
			window[id][index] = val_in;
			window_sum[id] = val_in;
			cur_index[id] = 0;
		}
		break;
	default:
		error("set_adc_ma_window: incorrect ADC channel selected!");

	break;	
	}
}

void 
reset_adc_ma_window( adc_channel_id_t id )
{
	set_adc_ma_window(id, 0);
}
