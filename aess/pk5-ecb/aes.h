#ifndef _AES_H_
#define _AES_H_

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// #define the macros below to 1/0 to enable/disable the mode of operation.
//
// CBC enables AES encryption in CBC-mode of operation.
// ECB enables the basic ECB 16-byte block algorithm. Both can be enabled simultaneously.

// The #ifndef-guard allows it to be configured before #include'ing or at compile time.
// #ifndef CBC
//   #define CBC 1
// #endif

#ifndef ECB
  #define ECB 1
#endif

#define AES128 1
//#define AES192 1
//#define AES256 1

//#if (defined(ECB) && (ECB == 1))
#ifdef ECB
void AES_ECB_encrypt(const uint8_t* input, const uint8_t* key, uint8_t *output, const uint32_t length);
void AES_ECB_decrypt(const uint8_t* input, const uint8_t* key, uint8_t *output, const uint32_t length);

#endif // #if defined(ECB) && (ECB == !)


//#if defined(CBC) && (CBC == 1)
#if 0
void AES_CBC_encrypt_buffer(uint8_t* output, uint8_t* input, uint32_t length, const uint8_t* key, const uint8_t* iv);
void AES_CBC_decrypt_buffer(uint8_t* output, uint8_t* input, uint32_t length, const uint8_t* key, const uint8_t* iv);

#endif // #if defined(CBC) && (CBC == 1)

void printOutMsg(uint8_t *pData, uint16_t len);

//int base64_encode( char* dst, int* dlen, const unsigned char* src, int slen );
//int base64_decode( unsigned char* dst, int* dlen, const char* src, int slen );
void base64_encode(char *ret, int *dst_len,const char* data, int data_len);
void base64_decode(char *ret,int *dst_len,const char *data, int data_len) ; 
static char find_pos(char ch);
#define nullptr NULL
#endif //_AES_H_
