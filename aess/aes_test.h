#ifndef _AES_TEST_H_
#define _AES_TEST_H_
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "aes.h"


#define CBC 1
#define ECB 1




/***************************************************************************
* Function Name: printOutMsg 					
* Function Introduction: print the inpute data	
* Parameter description: 
*                 pData: data buffer
*                   len: data length
* Function return value: void		
* Data : 2017.10.25									
****************************************************************************/
void printOutMsg(uint8_t *pData, uint16_t len);


/***************************************************************************
* Function Name: AES_CBC_encrypt_decrypt 					
* Function Introduction: 
*		               for test the aes function 
* Parameter description: void     
* Function return value: void
* Data : 2017.10.25									
****************************************************************************/
void AES_CBC_encrypt_decrypt(void);


/***************************************************************************
* Function Name: aes_encrypt_cbc 					
* Function Introduction: use aes to encrypt data	
* Parameter description: 
*            outputData: output data
*         outputDataLen: output length
*             inputData: inpute data
*          inputDataLen: input data length
* Function return value: 
*                        0:success
* Data : 2017.10.25									
****************************************************************************/
int aes_encrypt_cbc(uint8_t *outputData, uint16_t *outputDataLen, uint8_t *inputData, uint16_t inputDataLen);


/***************************************************************************
* Function Name: aes_decrypt_cbc 					
* Function Introduction: use aes to decrypt data
* Parameter description: 
*            outputData: output data
*         outputDataLen: output length
*             inputData: inpute data
*          inputDataLen: input data length
* Function return value: 
*                        0:success
* Data : 2017.10.25									
****************************************************************************/
int aes_decrypt_cbc(uint8_t *outputData, uint16_t *outputDataLen, uint8_t *inputData, uint16_t inputDataLen);










#endif // _AES_TEST_H_

