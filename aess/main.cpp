#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "aes.h"

	uint8_t iv[]  = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f };
	uint8_t key[] = { 0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c };

int aes_encrypt_cbc(uint8_t *outputData, uint16_t *outputDataLen, uint8_t *inputData, uint16_t inputDataLen)
{
	printf("original data:\n");
	printOutMsg(inputData, inputDataLen);

	AES_CBC_encrypt_buffer(outputData, inputData, inputDataLen, key, iv);
	
	*outputDataLen = inputDataLen;

	printf("encrypt data:\n");
	printOutMsg(outputData, *outputDataLen);

	return 0;
}

int aes_decrypt_cbc(uint8_t *outputData, uint16_t *outputDataLen, uint8_t *inputData, uint16_t inputDataLen)
{
	AES_CBC_decrypt_buffer(outputData, inputData, inputDataLen, key, iv);

	*outputDataLen = inputDataLen;

	printf("decrypt data:\n");
	printOutMsg(outputData, *outputDataLen);
	
	return 0;
}


int main()
{
	uint8_t data[12] = "123456789";
	uint16_t datalen = strlen(data);

	uint8_t *outdata = (uint8_t *)malloc(1024);
	uint16_t outdatalen = 0;

	aes_encrypt_cbc(outdata, &outdatalen, data, datalen);
	return 0;
}