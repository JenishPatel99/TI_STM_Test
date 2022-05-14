/** @file HL_sys_main.c 
*   @brief Application main file
*   @date 11-Dec-2018
*   @version 04.07.01
*
*   This file contains an empty main function,
*   which can be used for the application.
*/

/* 
* Copyright (C) 2009-2018 Texas Instruments Incorporated - www.ti.com  
* 
* 
*  Redistribution and use in source and binary forms, with or without 
*  modification, are permitted provided that the following conditions 
*  are met:
*
*    Redistributions of source code must retain the above copyright 
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the 
*    documentation and/or other materials provided with the   
*    distribution.
*
*    Neither the name of Texas Instruments Incorporated nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/


/* USER CODE BEGIN (0) */
/* USER CODE END */

/* Include Files */

#include "HL_sys_common.h"

/* USER CODE BEGIN (1) */
#include "HL_spi.h"
#include "HL_gio.h"
#include "HL_het.h"

#define BUFFER_LENGTH 1

uint32_t i;              // Create a 32 bit integer variable for counting cycles
uint8_t giobDIR;      // Create a 8 bit integer variable for GIO PORTB direction
uint32_t switchA;
uint8_t switchB;
uint16 dummy = "CC";

// Initialize SPI config
spiDAT1_t dataconfig1_t;

/* USER CODE END */

/** @fn void main(void)
*   @brief Application main function
*   @note This function is empty by default.
*
*   This function is called after startup.
*   The user can use this function to implement the application.
*/

/* USER CODE BEGIN (2) */
/* USER CODE END */

int main(void)
{
/* USER CODE BEGIN (3) */

    uint16 TX_Data_Master[16] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                                  0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E,
                                  0x0F, 0x10 };
//    uint16 TX_Data_Slave[BUFFER_LENGTH] =
//            { 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B,
//              0x1C, 0x1D, 0x1E, 0x1F, 0x20 };
     //uint16 TX_Data_Master[1] = { 0xAC};
//     uint16 TX_Data_Slave[1]  = { 0xBF};
    uint16 RX_Data_Master[BUFFER_LENGTH] = { 0 };
    uint16 RX_Data_Slave[BUFFER_LENGTH] = { 0 };

    /* Enable CPU Interrupt through CPSR */
    _enable_IRQ();

    // Initialize SPI
    spiInit();

    // Populate SPI config
    dataconfig1_t.CS_HOLD = FALSE;
    dataconfig1_t.WDEL = FALSE; // not sure
    dataconfig1_t.DFSEL = SPI_FMT_0;
    dataconfig1_t.CSNR = 0x00;

    //spiEnableNotification(spiREG3, 0);
    int i = 0;
    int j;

    while (1) {

         // Writing/reading from slave
         uint16_t tx = TX_Data_Master[(++i % 16)];
         spiSendData(spiREG3, &dataconfig1_t, BUFFER_LENGTH, &tx);

         for (j=0; j<13636363; j++); // Delay for 0.5 ms

    }

    /* USER CODE END */
    return 0;
}


/* USER CODE BEGIN (4) */
void SPIWriteToSlave(spiBASE_t *spi, spiDAT1_t *dataconfig1_t, uint16 buffer_length, uint16 *pData) {
    spiSendData(spi, dataconfig1_t, buffer_length, pData);
}

uint16 SPIReadFromSlave(spiDAT1_t *dataconfig1_t, uint16 buffer_length) {
    uint16 receive_data = 0x00;

    spiSendData(spiREG1, dataconfig1_t, buffer_length, &dummy);
    spiSendAndGetData(spiREG1, dataconfig1_t, buffer_length, &dummy, &receive_data);

    return receive_data;
}
//
//void spiEndNotification(spiBASE_t *spi)
//{
/*  enter user code between the USER CODE BEGIN and USER CODE END. */
/* USER CODE BEGIN (34) */

//    uint16 data = 0xFF;
//    spiSendData(spi, &dataconfig1_t, 1, &data);
    /* USER CODE END */
