/*
 * Command_Handler.c
 *
 *  Created on: May 4, 2022
 *      Author: liam
 */
#include "Command_Handler.h"
#include "main.h"

void handle_command(uint8_t cmd){
	switch (cmd){
		case GET_IMAGE_NUM:
			DBG_PUT("Get Image Command called\r\n");
			break;
		case CAPTURE_IMAGE:
			DBG_PUT("Capture Command called\r\n");
			break;
		case COUNT_IMAGES:
			DBG_PUT("Count Images Command called\r\n");
			break;
		case SENSOR_IDLE:
			DBG_PUT("Sensor Idle Command called\r\n");
			break;
		case SENSOR_ACTIVE:
			DBG_PUT("Sensor Active Command called\r\n");
			break;
		case GET_HK:
			DBG_PUT("Get Housekeeping Command called\r\n");
			break;
	}
}

