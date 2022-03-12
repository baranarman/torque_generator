#include "vac_test.h"
#include "../algo/voltage_angle_converter/vac.h"

#include "test.h"
#include <stdio.h>
bool
testVAC()
{
	printf("executing Voltage to Angle Converter tests... \n");
	bool result = true;
	int angle = 0;

	/* input: [0,  ADC_CHANNEL0] output: -5 degree , not valid for the case but valid for function, no error detection in converter*/
	angle = convert_adc_to_degree(ADC_CHANNEL0, 0);
	CHECK(result, -5, angle );

	/* input: [5,  ADC_CHANNEL0] output: 0 degree  */
	angle = convert_adc_to_degree(ADC_CHANNEL0, 5);
	CHECK(result, 0, angle );

	/* input: [25, ADC_CHANNEL0] output: 20 degree */
	angle = convert_adc_to_degree(ADC_CHANNEL0, 25);
	CHECK(result, 20, angle );

	/* input: [30, ADC_CHANNEL0] output: 25 degree */
	angle = convert_adc_to_degree(ADC_CHANNEL0, 30);
	CHECK(result, 25, angle );

	/* input: [35, ADC_CHANNEL0] output: 30 degree */
	angle = convert_adc_to_degree(ADC_CHANNEL0, 35);
	CHECK(result, 30, angle );

	/* input: [36, ADC_CHANNEL0] output: 31 degree , not valid for the case but valid for function, no error detection in converter*/
	angle = convert_adc_to_degree(ADC_CHANNEL0, 36);
	CHECK(result, 31, angle );

	/* input: [0,  ADC_CHANNEL1] output: -12 degree , not valid for the case but valid for function, no error detection in converter*/
	angle = convert_adc_to_degree(ADC_CHANNEL1, 0);
	CHECK(result, -12, angle );

	/* input: [10,  ADC_CHANNEL1] output: 0 degree  */
	angle = convert_adc_to_degree(ADC_CHANNEL1, 10);
	CHECK(result, 0, angle );	

	/* input: [15, ADC_CHANNEL1] output: 6 degree */
	angle = convert_adc_to_degree(ADC_CHANNEL1, 15);
	CHECK(result, 6, angle );	

	/* input: [30, ADC_CHANNEL1] output: 25 degree */
	angle = convert_adc_to_degree(ADC_CHANNEL1, 30);
	CHECK(result, 25, angle );	

	/* input: [34, ADC_CHANNEL1] output: 30 degree */
	angle = convert_adc_to_degree(ADC_CHANNEL1, 34);
	CHECK(result, 30, angle );	

	/* input: [35, ADC_CHANNEL1] output: 31 degree , not valid for the case but valid for function, no error detection in converter*/
	angle = convert_adc_to_degree(ADC_CHANNEL1, 35);
	CHECK(result, 31, angle );	

	return result;

}

