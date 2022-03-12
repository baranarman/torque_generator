#include "torque_calculator_test.h"
#include "../algo/torque_calculator/torque_calc.h"

#include "test.h"
#include <stdio.h>

bool
testTC()
{
	printf("executing Torque Calculator tests... \n");
	bool result = true;

	trq_val_t val = 0;
	return_t ret = RET_NOK;

	// for some specific input values the outputs will be checked

	// testing calc_torque_d with different speeds with no pedal pressed
	// input [  0,   0,    0]; expected output ret: RET_OK, val:   0;
	ret = calc_torque_d(0, 0, 0, &val);
	CHECK(result, RET_OK, ret);
	CHECK(result, 0, val);
	// input [  0,   0,   10]; expected output ret: RET_OK, val:  -6;
	ret = calc_torque_d(0, 0, 10, &val);
	CHECK(result, RET_OK, ret);
	CHECK(result, -6, val);	
	// input [  0,   0,   20]; expected output ret: RET_OK, val: -12;
	ret = calc_torque_d(0, 0, 20, &val);
	CHECK(result, RET_OK, ret);
	CHECK(result, -12, val);	
	// input [  0,   0,   30]; expected output ret: RET_OK, val: -18;
	ret = calc_torque_d(0, 0, 30, &val);
	CHECK(result, RET_OK, ret);
	CHECK(result, -18, val);	
	// input [  0,   0,   40]; expected output ret: RET_OK, val: -24;
	ret = calc_torque_d(0, 0, 40, &val);
	CHECK(result, RET_OK, ret);
	CHECK(result, -24, val);	
	// input [  0,   0,   50]; expected output ret: RET_OK, val: -30;
	ret = calc_torque_d(0, 0, 50, &val);
	CHECK(result, RET_OK, ret);
	CHECK(result, -30, val);	

	// testing calc_torque_d with different speeds with no pedal pressed 25% 
	// input [ 25,  25,    0]; expected output ret: RET_OK, val:  45;
	ret = calc_torque_d(25, 25, 0, &val);
	CHECK(result, RET_OK, ret);
	CHECK(result, 45, val);	
	// input [ 25,  25,   10]; expected output ret: RET_OK, val:  40;
	ret = calc_torque_d(25, 25, 10, &val);
	CHECK(result, RET_OK, ret);
	CHECK(result, 40, val);	
	// input [ 25,  25,   20]; expected output ret: RET_OK, val:  35;
	ret = calc_torque_d(25, 25, 20, &val);
	CHECK(result, RET_OK, ret);
	CHECK(result, 35, val);	
	// input [ 25,  25,   30]; expected output ret: RET_OK, val:  31;
	ret = calc_torque_d(25, 25, 30, &val);
	CHECK(result, RET_OK, ret);
	CHECK(result, 31, val);	
	// input [ 25,  25,   40]; expected output ret: RET_OK, val:  26;
	ret = calc_torque_d(25, 25, 40, &val);
	CHECK(result, RET_OK, ret);
	CHECK(result, 26, val);	
	// input [ 25,  25,   50]; expected output ret: RET_OK, val:  22;
	ret = calc_torque_d(25, 25, 50, &val);
	CHECK(result, RET_OK, ret);
	CHECK(result, 22, val);	

	// testing calc_torque_d with different speeds with no pedal pressed 30%  - 20%
	// input [ 30,  20,    0]; expected output ret: RET_OK, val:  45;
	ret = calc_torque_d(30, 20, 0, &val);
	CHECK(result, RET_OK, ret);
	CHECK(result, 45, val);	
	// input [ 30,  20,   10]; expected output ret: RET_OK, val:  40;
	ret = calc_torque_d(30, 20, 10, &val);
	CHECK(result, RET_OK, ret);
	CHECK(result, 40, val);	
	// input [ 30,  20,   20]; expected output ret: RET_OK, val:  35;
	ret = calc_torque_d(30, 20, 20, &val);
	CHECK(result, RET_OK, ret);
	CHECK(result, 35, val);	
	// input [ 30,  20,   30]; expected output ret: RET_OK, val:  31;
	ret = calc_torque_d(30, 20, 30, &val);
	CHECK(result, RET_OK, ret);
	CHECK(result, 31, val);	
	// input [ 30,  20,   40]; expected output ret: RET_OK, val:  26;
	ret = calc_torque_d(30, 20, 40, &val);
	CHECK(result, RET_OK, ret);
	CHECK(result, 26, val);	
	// input [ 30,  20,   50]; expected output ret: RET_OK, val:  22;
	ret = calc_torque_d(30, 20, 50, &val);
	CHECK(result, RET_OK, ret);
	CHECK(result, 22, val);	

	// testing calc_torque with different speeds with no pedal pressed 25% 
	// input [ 25,  0]; expected output ret: RET_OK, val:  45;
	ret = calc_torque(25, 0, &val);
	CHECK(result, RET_OK, ret);
	CHECK(result, 45, val);	
	// input [ 25, 10]; expected output ret: RET_OK, val:  40;
	ret = calc_torque(25, 10, &val);
	CHECK(result, RET_OK, ret);
	CHECK(result, 40, val);	
	// input [ 25, 20]; expected output ret: RET_OK, val:  35;
	ret = calc_torque(25, 20, &val);
	CHECK(result, RET_OK, ret);
	CHECK(result, 35, val);	
	// input [ 25, 30]; expected output ret: RET_OK, val:  31;
	ret = calc_torque(25, 30, &val);
	CHECK(result, RET_OK, ret);
	CHECK(result, 31, val);	
	// input [ 25, 40]; expected output ret: RET_OK, val:  26;
	ret = calc_torque(25, 40, &val);
	CHECK(result, RET_OK, ret);
	CHECK(result, 26, val);	
	// input [ 25, 50]; expected output ret: RET_OK, val:  22;
	ret = calc_torque(25, 50, &val);
	CHECK(result, RET_OK, ret);
	CHECK(result, 22, val);	


	// testing calc_torque with constand speed at different pedal angles
	// input [ 12,  25]; expected output ret: RET_OK, val:   8;
	ret = calc_torque(12, 25, &val);
	CHECK(result, RET_OK, ret);
	CHECK(result, 8, val);	
	// input [ 37,  25]; expected output ret: RET_OK, val:  47;
	ret = calc_torque(37, 25, &val);
	CHECK(result, RET_OK, ret);
	CHECK(result, 47, val);	
	// input [ 62,  25]; expected output ret: RET_OK, val:  76;
	ret = calc_torque(62, 25, &val);
	CHECK(result, RET_OK, ret);
	CHECK(result, 76, val);	
	// input [ 87,  25]; expected output ret: RET_OK, val: 104;
	ret = calc_torque(87, 25, &val);
	CHECK(result, RET_OK, ret);
	CHECK(result, 104, val);	

	return result;
}