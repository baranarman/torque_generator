/** @file
 *  @brief Header file for Speed driver
 */

#ifndef _SPEED_DRIVER_H_
#define _SPEED_DRIVER_H_

#include "../../types.h"

/** @brief Initialized the Speedometer driver
 *  returns Whether the speedometer driver is initialized successfully or not
 */
return_t speed_init();

/** @brief Reads the value of the speed in vehicle
 *  @param[out] value the read value which is a value between 0 and 50, in unit of km/h
 *  @returns wether the speed value is successfully read or not
 */
return_t speed_read(speed_val_t* speed);


/** @brief Helper function for setting what is returned by speed_read().
 *  @param[in] speed_in the value that is assigned to the speed value output.
 *  @parameter[in] return_in The value that is returned by speed_read().
 *  @note Just a mock function.
 */
void speed_read_set_output(speed_val_t speed_in, return_t return_in);


#endif
