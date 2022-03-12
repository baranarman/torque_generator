#include "mac_test.h"
#include "../algo/moving_average_calculator/mac.h"

#include "test.h"
#include <stdio.h>

bool testMAC()
{
		printf("executing Moving Average Calculator tests...\n");
		bool result = true;

		int value = 0;

		return_t mac_result= RET_NOK;
		adc_value_t val_out = 0;
		// reset the ADC0 & ADC1 before initial use
		reset_adc_ma_window(ADC_CHANNEL0);
		reset_adc_ma_window(ADC_CHANNEL1);

		/* input#1: (ADC_CHANNEL0, 10) output ret: OK output val = 2  */
		mac_result = get_adc_ma(ADC_CHANNEL0, 10, &val_out);
		CHECK(result, RET_OK, mac_result);
		CHECK(result, 2, val_out);

		/* input#2: (ADC_CHANNEL0, 10) output ret: OK output val = 4  */
		mac_result = get_adc_ma(ADC_CHANNEL0, 10, &val_out);
		CHECK(result, RET_OK, mac_result);
		CHECK(result, 4, val_out);

		/* input#3: (ADC_CHANNEL0, 10) output ret: OK output val = 6  */
		mac_result = get_adc_ma(ADC_CHANNEL0, 10, &val_out);
		CHECK(result, RET_OK, mac_result);
		CHECK(result, 6, val_out);

		/* input#4: (ADC_CHANNEL0, 10) output ret: OK output val = 8  */
		mac_result = get_adc_ma(ADC_CHANNEL0, 10, &val_out);
		CHECK(result, RET_OK, mac_result);
		CHECK(result, 8, val_out);

		/* input#5: (ADC_CHANNEL0, 10) output ret: OK output val = 10  */		
		mac_result = get_adc_ma(ADC_CHANNEL0, 10, &val_out);
		CHECK(result, RET_OK, mac_result);
		CHECK(result, 10, val_out);

		/* input#6: (ADC_CHANNEL0, 10) output ret: OK output val = 10  */		
		mac_result = get_adc_ma(ADC_CHANNEL0, 10, &val_out);
		CHECK(result, RET_OK, mac_result);
		CHECK(result, 10, val_out);

		/* input#7: (ADC_CHANNEL0, 20) output ret: OK output val = 12  */
		mac_result = get_adc_ma(ADC_CHANNEL0, 20, &val_out);
		CHECK(result, RET_OK, mac_result);
		CHECK(result, 12, val_out);

		/* input#8: (ADC_CHANNEL0, 0) output ret: OK output val = 10  */
		mac_result = get_adc_ma(ADC_CHANNEL0, 0, &val_out);
		CHECK(result, RET_OK, mac_result);
		CHECK(result, 10, val_out);

		/* input#9: (ADC_CHANNEL0, 0) output ret: OK output val = 8  */
		mac_result = get_adc_ma(ADC_CHANNEL0, 0, &val_out);
		CHECK(result, RET_OK, mac_result);
		CHECK(result, 8, val_out);

		/* input#10: (ADC_CHANNEL0, 0) output ret: OK output val = 6  */
		mac_result = get_adc_ma(ADC_CHANNEL0, 0, &val_out);
		CHECK(result, RET_OK, mac_result);
		CHECK(result, 6, val_out);

		// without reseting the adc0 start sending data to adc mac to see if there is an interaction betwee adc queues

		/* input#1: (ADC_CHANNEL1, 10) output ret: OK output val = 2  */
		mac_result = get_adc_ma(ADC_CHANNEL1, 10, &val_out);
		CHECK(result, RET_OK, mac_result);
		CHECK(result, 2, val_out);

		/* input#2: (ADC_CHANNEL1, 10) output ret: OK output val = 4  */
		mac_result = get_adc_ma(ADC_CHANNEL1, 10, &val_out);
		CHECK(result, RET_OK, mac_result);
		CHECK(result, 4, val_out);

		/* input#3: (ADC_CHANNEL1, 10) output ret: OK output val = 6  */
		mac_result = get_adc_ma(ADC_CHANNEL1, 10, &val_out);
		CHECK(result, RET_OK, mac_result);
		CHECK(result, 6, val_out);

		/* input#4: (ADC_CHANNEL1, 10) output ret: OK output val = 8  */
		mac_result = get_adc_ma(ADC_CHANNEL1, 10, &val_out);
		CHECK(result, RET_OK, mac_result);
		CHECK(result, 8, val_out);

		/* input#5: (ADC_CHANNEL1, 10) output ret: OK output val = 10  */		
		mac_result = get_adc_ma(ADC_CHANNEL1, 10, &val_out);
		CHECK(result, RET_OK, mac_result);
		CHECK(result, 10, val_out);

		/* input#6: (ADC_CHANNEL1, 10) output ret: OK output val = 10  */		
		mac_result = get_adc_ma(ADC_CHANNEL1, 10, &val_out);
		CHECK(result, RET_OK, mac_result);
		CHECK(result, 10, val_out);

		/* input#7: (ADC_CHANNEL1, 20) output ret: OK output val = 12  */
		mac_result = get_adc_ma(ADC_CHANNEL1, 20, &val_out);
		CHECK(result, RET_OK, mac_result);
		CHECK(result, 12, val_out);

		/* input#8: (ADC_CHANNEL1, 0) output ret: OK output val = 10  */
		mac_result = get_adc_ma(ADC_CHANNEL1, 0, &val_out);
		CHECK(result, RET_OK, mac_result);
		CHECK(result, 10, val_out);

		/* input#9: (ADC_CHANNEL1, 0) output ret: OK output val = 8  */
		mac_result = get_adc_ma(ADC_CHANNEL1, 0, &val_out);
		CHECK(result, RET_OK, mac_result);
		CHECK(result, 8, val_out);

		/* input#10: (ADC_CHANNEL1, 0) output ret: OK output val = 6  */
		mac_result = get_adc_ma(ADC_CHANNEL1, 0, &val_out);
		CHECK(result, RET_OK, mac_result);
		CHECK(result, 6, val_out);

		// testing reset function on adc0
		reset_adc_ma_window(ADC_CHANNEL0);
		/* input#1: (ADC_CHANNEL0, 0) output ret: OK output val = 0  */
		mac_result = get_adc_ma(ADC_CHANNEL0, 0, &val_out);
		CHECK(result, RET_OK, mac_result);
		CHECK(result, 0, val_out);

		// testing reset function on adc1
		reset_adc_ma_window(ADC_CHANNEL1);
		/* input#1: (ADC_CHANNEL1, 0) output ret: OK output val = 0  */
		mac_result = get_adc_ma(ADC_CHANNEL1, 0, &val_out);
		CHECK(result, RET_OK, mac_result);
		CHECK(result, 0, val_out);

		// testing set_adc_ma_window function for ADC0
		set_adc_ma_window(ADC_CHANNEL0, 12);
		/* input#1: (ADC_CHANNEL0, 12) output ret: OK output val = 12  */
		mac_result = get_adc_ma(ADC_CHANNEL0, 12, &val_out);
		CHECK(result, RET_OK, mac_result);
		CHECK(result, 12, val_out);		

		// testing set_adc_ma_window function for ADC1
		set_adc_ma_window(ADC_CHANNEL1, 12);
		/* input#1: (ADC_CHANNEL1, 12) output ret: OK output val = 12  */
		mac_result = get_adc_ma(ADC_CHANNEL1, 12, &val_out);
		CHECK(result, RET_OK, mac_result);
		CHECK(result, 12, val_out);		

		// testing set_adc_ma_output function for ADC0
		set_adc_ma_output(ADC_CHANNEL0, 22, RET_OK);
		/* input#2: (ADC_CHANNEL0, 12) output ret: OK output val = 22 - this input will be ignored as mock is activated */
		mac_result = get_adc_ma(ADC_CHANNEL0, 12, &val_out);
		CHECK(result, RET_OK, mac_result);
		CHECK(result, 22, val_out);						

		// testing set_adc_ma_output function for ADC1
		set_adc_ma_output(ADC_CHANNEL1, 22, RET_OK);
		/* input#2: (ADC_CHANNEL1, 12) output ret: OK output val = 22 - this input will be ignored as mock is activated */
		mac_result = get_adc_ma(ADC_CHANNEL1, 12, &val_out);
		CHECK(result, RET_OK, mac_result);
		CHECK(result, 22, val_out);						

		return result;
}