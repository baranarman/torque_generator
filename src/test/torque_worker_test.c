#include "torque_worker_test.h"
#include "../app/torque_worker/torque_worker.h"

#include "test.h"
#include "stdio.h"

bool testTW()
{
	printf("executing Torque Worker tests...\n");
	bool result = true;
	trq_val_t val = 0;
	return_t ret = RET_NOK;

	// initialize drivers
	return_t adc_ret0 = adc_init(ADC_CHANNEL0);
	CHECK(result, RET_OK, adc_ret0);

	return_t adc_ret1 = adc_init(ADC_CHANNEL1);
	CHECK(result, RET_OK, adc_ret1);

	return_t speed_ret = speed_init();
	CHECK(result, RET_OK, speed_ret);

	error_led_init();
	// initialize mac
	reset_adc_ma_window(ADC_CHANNEL0);
	reset_adc_ma_window(ADC_CHANNEL1);

	// input set 1: 
	// adc0:[ADC_CHANNEL0, 35, ADC_RET_OK] 
	// adc1:[ADC_CHANNEL1, 34, ADC_RET_OK] 
	// spd :[0, SPEED_RET_OK]
	// expected: [TRQ_CALC_OK, 36]
	adc_read_set_output(ADC_CHANNEL0, 35, RET_OK);
	adc_read_set_output(ADC_CHANNEL1, 34, RET_OK);
	speed_read_set_output(0, RET_OK);
	ret = getTorque(&val);
	CHECK(result, RET_OK, ret);
	CHECK(result, 36, val);

	// input set 2: 
	// adc0:[ADC_CHANNEL0, 35, ADC_RET_OK] 
	// adc1:[ADC_CHANNEL1, 34, ADC_RET_OK] 
	// spd :[0, SPEED_RET_OK]
	// expected: [TRQ_CALC_OK, 61]
	adc_read_set_output(ADC_CHANNEL0, 35, RET_OK);
	adc_read_set_output(ADC_CHANNEL1, 34, RET_OK);
	speed_read_set_output(0, RET_OK);
	ret = getTorque(&val);
	CHECK(result, RET_OK, ret);
	CHECK(result, 61, val);

	// input set 3: 
	// adc0:[ADC_CHANNEL0, 35, ADC_RET_OK] 
	// adc1:[ADC_CHANNEL1, 34, ADC_RET_OK] 
	// spd :[0, SPEED_RET_OK]
	// expected: [TRQ_CALC_OK, 83]
	adc_read_set_output(ADC_CHANNEL0, 35, RET_OK);
	adc_read_set_output(ADC_CHANNEL1, 34, RET_OK);
	speed_read_set_output(0, RET_OK);
	ret = getTorque(&val);
	CHECK(result, RET_OK, ret);
	CHECK(result, 83, val);

	// input set 4: 
	// adc0:[ADC_CHANNEL0, 35, ADC_RET_OK] 
	// adc1:[ADC_CHANNEL1, 34, ADC_RET_OK] 
	// spd :[0, SPEED_RET_OK]
	// expected: [TRQ_CALC_OK, 83]
	adc_read_set_output(ADC_CHANNEL0, 35, RET_OK);
	adc_read_set_output(ADC_CHANNEL1, 34, RET_OK);
	speed_read_set_output(0, RET_OK);
	ret = getTorque(&val);
	CHECK(result, RET_OK, ret);
	CHECK(result, 104, val);


	// input set 5: 
	// adc0:[ADC_CHANNEL0, 35, ADC_RET_OK] 
	// adc1:[ADC_CHANNEL1, 34, ADC_RET_OK] 
	// spd :[0, SPEED_RET_OK]
	// expected: [TRQ_CALC_OK, 83]
	adc_read_set_output(ADC_CHANNEL0, 35, RET_OK);
	adc_read_set_output(ADC_CHANNEL1, 34, RET_OK);
	speed_read_set_output(0, RET_OK);
	ret = getTorque(&val);
	CHECK(result, RET_OK, ret);
	CHECK(result, 120, val);

	// input set 6: 
	// adc0:[ADC_CHANNEL0, 35, ADC_RET_OK] 
	// adc1:[ADC_CHANNEL1, 34, ADC_RET_OK] 
	// spd :[0, SPEED_RET_OK]
	// expected: [TRQ_CALC_OK, 83]
	adc_read_set_output(ADC_CHANNEL0, 5, RET_OK);
	adc_read_set_output(ADC_CHANNEL1, 10, RET_OK);
	speed_read_set_output(0, RET_OK);
	ret = getTorque(&val);
	CHECK(result, RET_OK, ret);
	CHECK(result, 104, val);

	return result;
}