/*************************************************************************
    > File Name: cycle.c
    > Author: zll
    > Mail: zhnllion@126.com 
    > Created Time: 2018年10月23日 星期二 19时28分05秒
 ************************************************************************/
#include "pthread.h"
#include<stdio.h>
#include<string.h>
#include"stdlib.h"
#include "unistd.h"
typedef struct CYCLE_BUF_Tag
{
	char *head;
	char *last;
	char *rx_offset;
	char *tx_offset;
	int buf_size;
	int using_size;
}CYCLE_BUF_ST;

int cycle_init(CYCLE_BUF_ST *cyc, int size)
{
	cyc->head = NULL;
	cyc->rx_offset = NULL;
	cyc->tx_offset = NULL;
	cyc->buf_size = size;
	cyc->using_size = 0;

	cyc->head = malloc(size);
	memset(cyc->head,0,size);
	if(cyc->head == NULL)
	{
		printf("error :molloc buf fail \n");
		return -1;
	}
	cyc->rx_offset = cyc->tx_offset = cyc->head;
	cyc->last = cyc->head + size - 1;
	return 0;
}

int cycle_write_buf(CYCLE_BUF_ST *cyc, char *buf, int len)
{
	int ret = 0;
	int length = 0;

	if(len > cyc->buf_size)
	{
		printf("error :wirte buf size too big \n");
		return -1;
	}

	if(cyc->using_size == cyc->buf_size)
	{
		printf("waring : write fail buf full \n");
		return 0;
	}

	/*判断是否会有数据的溢出*/
	if((cyc->buf_size - cyc->using_size) < len)
	{
		printf("waring : write buf size over\n");
		/*丢弃tx部分数据不占用rx后的数据*/
		return 0;
		len = cyc->buf_size - cyc->using_size;
	}

	if((cyc->tx_offset + len - 1) <= cyc->last)
	{
		memcpy(cyc->tx_offset, buf, len);
	
		if((cyc->tx_offset + len - 1) == cyc->last)
		cyc->tx_offset = cyc->head;
		else
		cyc->tx_offset = cyc->tx_offset + len;
	}
	else
	{
		int tmp_len = cyc->last - cyc->tx_offset + 1;
		memcpy(cyc->tx_offset,buf,tmp_len);
		memcpy(cyc->head,buf + tmp_len, len - tmp_len);
		cyc->tx_offset = cyc->head + len - tmp_len;
	}
	
	cyc->using_size = len + cyc->using_size;
	return len;
}

int cycle_read_buf(CYCLE_BUF_ST *cyc, char *buf, int len)
{
	int ret = 0;
	
	if(len > cyc->buf_size)
	{
		printf("error read buf size too big \n");
		return -1;
	}
	
	/*没有可用数据*/
	if(cyc->using_size == 0)
	{
		printf("waring :buf is empty \n");
		return 0;
	}
	/*数据不足*/
	if(len > cyc->using_size)
	{
		printf("waring :buf not enough\n");
		len = cyc->using_size;
	}

	if((cyc->rx_offset + len - 1) <= cyc->last)
	{	
		memcpy(buf, cyc->rx_offset, len);
		
		if((cyc->rx_offset + len -1) == cyc->last)
			cyc->rx_offset = cyc->head;
		else
		cyc->rx_offset = cyc->rx_offset + len;
	}
	else
	{
		int tmp_len = cyc->last - cyc->rx_offset + 1;
		memcpy(buf, cyc->rx_offset, tmp_len);
		memcpy(buf + tmp_len, cyc->head, len - tmp_len);
		cyc->rx_offset = cyc->head + len - tmp_len;
	}

	cyc->using_size = cyc->using_size - len;
	return len;
}
void *ring_test(void *p)
{
	char buf_tx[8] = "hello";
	CYCLE_BUF_ST *cyc = (CYCLE_BUF_ST *)p;
	int ret = 0;
	while(1)
	{
		ret = cycle_write_buf(cyc,buf_tx,5);
		printf("ret = %d\n",ret);
		usleep(100);
	}
}
int main(int argc, char *argv[])
{
	int ret = 0;
	pthread_t pid = 0;
	CYCLE_BUF_ST cyc;
	char buf_rx[8] = {0};
	ret = cycle_init(&cyc, 1024);
	int i = 0;
	int j = 0;
	ret = pthread_create(&pid,NULL,ring_test,(void *)&cyc);
	if(ret != 0)
		printf("pthread creat ret = %d\n",ret);
	while(1)
	{
		cycle_read_buf(&cyc,buf_rx,5);
		printf("rx = %s\n",buf_rx);
		memset(buf_rx,0,5);
		usleep(1000);
	}
	return 0;
}
