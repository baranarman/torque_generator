/** @file
 *  @brief Main file.
 *  @description includes code that tests the implementation
 */

#include <stdio.h>

#include "test/vac_test.h"
#include "test/mac_test.h"
#include "test/torque_calculator_test.h"
#include "test/torque_worker_test.h"

int main(int argc, char *argv[]) {
  	
	printf("Lightyear Torque Calculator \n");
	
	printf("%-50s  result: %s\n", 
		"TEST RESULT for \"Voltage to Angle Converter\"",
		(testVAC())? "PASS" : "FAIL");
	
	printf("%-50s  result: %s\n", 
		"TEST RESULT for \"Moving Average Calculator\"",
		(testMAC())? "PASS" : "FAIL");

	printf("%-50s  result: %s\n", 
		"TEST RESULT for \"Torque Calculator\"",
		(testTC())? "PASS" : "FAIL");

	printf("%-50s  result: %s\n", 
		"TEST RESULT for \"Torque Worker\"",
		(testTW())? "PASS" : "FAIL");

}
