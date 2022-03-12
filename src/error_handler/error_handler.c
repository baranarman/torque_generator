#include "error_handler.h"
#include "../drivers/error_led/error_led.h"

#include <stdio.h>

void error(char* error_text)
{
	error_led_set(true);
	printf("\nERROR: %s \n", error_text);
}
