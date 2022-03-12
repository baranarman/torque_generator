/** @file
 *  @brief Header file for torque generator, it uses possible drivers and application
 */ 

#ifndef __TORQUE_WORKER_H__
#define __TORQUE_WORKER_H__

#include <stdint.h>

#include "../../types.h"

// project includes
#include "../../drivers/speed_driver/speed_driver.h"
#include "../../drivers/adc_driver/adc_driver.h"
#include "../../drivers/error_led/error_led.h"

#include "../../error_handler/error_handler.h"

#include "../../algo/moving_average_calculator/mac.h"
#include "../../algo/voltage_angle_converter/vac.h"
#include "../../algo/torque_calculator/torque_calc.h"


/** @brief returns torque value for the system.
 *  @param[out] val the value of the torque(Nm)
 *  @returns if torque is correctly calculated or not
 *  @note newton meter = torque
 */ 
return_t getTorque(trq_val_t* val);

#endif