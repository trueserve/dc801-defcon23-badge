/*******************************************************************************
* File: main.c
*
* Version: 1.0
*
* Description:
*  This example project demonstrates the basic operation of Bootloader component
*
********************************************************************************
* Copyright 2014, Cypress Semiconductor Corporation. All rights reserved.
* This software is owned by Cypress Semiconductor Corporation and is protected
* by and subject to worldwide patent and copyright laws and treaties.
* Therefore, you may use this software only as provided in the license agreement
* accompanying the software package from which you obtained this software.
* CYPRESS AND ITS SUPPLIERS MAKE NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* WITH REGARD TO THIS SOFTWARE, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*******************************************************************************/
#include <project.h>

int main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    CyGlobalIntEnable;

    /* Start bootloader communication */
    Bootloader_Start();

    for(;;)
    {
        /* Place your application code here. */
    }
}

void CyBtldrCommStart(void) {
	UART_Start();
}
 
void CyBtldrCommStop (void) {
	UART_Stop();
}
 
void CyBtldrCommReset(void) {
	UART_SpiUartClearRxBuffer();
	UART_SpiUartClearTxBuffer();
}
 
cystatus CyBtldrCommWrite(uint8 *buffer, uint16 size, uint16 *count, uint8 timeOut) {
	for(*count = 0; *count < size; (*count)++) {
		UART_UartPutChar(buffer[*count]);
	}
	return CYRET_SUCCESS;
}
 
cystatus CyBtldrCommRead(uint8 *buffer, uint16 size, uint16 *count, uint8 timeOut) {
	int timeoutUs = timeOut * 10000;
	cystatus status = CYRET_TIMEOUT;
	*count = 0;\
	while(*count < size && timeoutUs >= 0) {
		if(UART_SpiUartGetRxBufferSize() > 0) {
			buffer[(*count)++] = UART_UartGetByte();
			// Switch to byte-to-byte timeout and mark as success
			timeoutUs = 10000; //10mS
			status = CYRET_SUCCESS;
		} else {
			CyDelayUs(10);
			timeoutUs -= 10;
		}
	}
	return status;
}

/* [] END OF FILE */
