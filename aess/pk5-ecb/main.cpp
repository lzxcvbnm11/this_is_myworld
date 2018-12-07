#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "aes.h"

	uint8_t iv[16]  = { 'P','a','s','F','m','c',0 };
	uint8_t key[16] = { 'P','a','s','F','m','c',0 };

int aes_encrypt_cbc(uint8_t *outputData, uint16_t *outputDataLen, uint8_t *inputData, uint16_t inputDataLen)
{
	char buf[1024] = {0};
	int len = 0;
	printf("original data:\n");
	printOutMsg(inputData, inputDataLen);

	AES_ECB_encrypt(inputData, key, outputData, inputDataLen);
	
	*outputDataLen = ((inputDataLen>>4)+1)<<4;
	base64_encode(buf,&len,(char *)outputData, *outputDataLen );
	printf("encrypt data: %s\r\n",buf);
	printOutMsg(outputData, *outputDataLen);

	return 0;
}

int aes_decrypt_cbc(uint8_t *outputData, uint16_t *outputDataLen, uint8_t *inputData, uint16_t inputDataLen)
{
	char buf[1024] = {0};
	int len = 0;
	printf("inputData = %s len = %d\r\n",inputData,inputDataLen);
	base64_decode(buf,&len,(char *)inputData, inputDataLen );
	
	printf("decrypt data len = %d:\n",len);
	printOutMsg(buf, len);
	
	AES_ECB_decrypt(buf, key, outputData, len);
	
	*outputDataLen = inputDataLen;
	
	printf("%s\n", outputData);
	printf("decrypt data:\n");
	printOutMsg(outputData, *outputDataLen);
	
	return 0;
}


int main()
{
	/*RDBSN=1234567890123456789012,BMUPCNT=3,BMUPSNS=12345678|12345678|123456,TIMESTAMP=1234567890*/
	uint8_t *data = "RDBSN=1234567890123456789012,BMUPCNT=3,BMUPSNS=12345678|12345678|123456,TIMESTAMP=1234567890";
	
	uint8_t *en_test_buf = "7PLa4nl/CXsNMGnegTR5KoUHXNuGnHkekeDt77+/oKp0Mv7FAKtiUto3TVha7dnKUfLH58Lwoo6L7Kzt3RO5Wk7D6cJuk7Q6oVlh/ivwW05bmXwxYR5dggoEo81Of1Xl";
	char *test_pkcs = "/aOTnQPkkb4mJ3nyLo3lkQ==";
	uint8_t en_buf[1024] = "0";
	uint16_t datalen = strlen(data);
	printf("datalen = %d\r\n",datalen);
	uint8_t *outdata = (uint8_t *)malloc(1024);
	uint16_t outdatalen = 0;

	printOutMsg(en_test_buf,strlen(en_test_buf));

	memset(outdata,0,1024);
	aes_encrypt_cbc(outdata, &outdatalen, data, datalen);
	//printf("encrypt = %s\r\n",outdata);
	memset(en_buf,0,1024);
	memcpy(en_buf,outdata,128);
	datalen = strlen(en_test_buf);
	printf("data_len = %d\r\n",datalen);

	aes_decrypt_cbc(outdata, &outdatalen, en_test_buf,strlen(en_test_buf));
	//printf("decrypt = %s\r\n",outdata);
	return 0;
}



