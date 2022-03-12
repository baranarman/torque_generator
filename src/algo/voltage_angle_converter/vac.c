/** @file 
 *  @brief Source file for Voltage to Angel converter for ADC values. 
 */

#include "vac.h"
#include "../../error_handler/error_handler.h"

int 
convert_adc_to_degree(
	adc_channel_id_t id, 
	adc_value_t val /*0.1V resolution*/)
{
	int result = 0;
	
	switch (id){
	case ADC_CHANNEL0:
		result = (val - 5);
		break;
	case ADC_CHANNEL1:
		result = (val - 10) / 0.8;
		break;
	default:
		error("convert_adc_to_degree unexpected channel id");
		break;
	}

	return result;
}
