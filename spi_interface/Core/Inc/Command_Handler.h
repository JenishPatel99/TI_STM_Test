/*
 * Command_Handler.h
 *
 *  Created on: May 4, 2022
 *      Author: liam
 */

#include "main.h"

#ifndef SRC_COMMAND_HANDLER_H_
#define SRC_COMMAND_HANDLER_H_

#define GET_IMAGE_NUM	0x05
#define CAPTURE_IMAGE 	0x10
#define COUNT_IMAGES 	0x20
#define SENSOR_IDLE 	0x30
#define SENSOR_ACTIVE	0x40
#define GET_HK			0x50
//#define I2C_COMPLEX_SHIT 0x69


void handle_command(uint8_t cmd);


#endif /* SRC_COMMAND_HANDLER_H_ */
