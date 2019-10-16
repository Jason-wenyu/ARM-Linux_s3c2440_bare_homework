#include "s3c2440_soc.h"

void sdram_init(void)
{
	BWSCON = 0x22000000;

	BANKCON6 = 0x18001;
	BANKCON7 = 0x18001;

	REFRESH  = 0x8404f5;

	BANKSIZE = 0xb1;

	MRSRB6   = 0x20;
	MRSRB7   = 0x20;
}

int isBootFromNorFlash(void)
{
    volatile int *p = (volatile *)0;
    int val;

    val = *p;
    *p = 0x12345678;
    if(*p == 0x12345678)
    {
        /*写成功，是nand启动*/
        *p = val;
        return 0;
    }
    else
    {
        /*NOR Flash启动*/
        return 1;
    }
    
}

void copy2sdram(void)
{
    	/* 要从lds文件中获得 __code_start, __bss_start
     * 然后从0地址把数据复制到__code_start
     */
    extern int __code_start,__bss_start;
    volatile unsigned int *dest = (volatile int *)&__code_start;
    volatile unsigned int *end = (volatile int *)&__bss_start;
    volatile unsigned int *src = (volatile int *)0;
    unsigned int len = (unsigned int)(&__code_start) -(unsigned int)(&__bss_start)
    if(isBootFromNorFlash())
    {
        while(dest < end)
        {
            *dest++ = *src++;
        }
        else
        {
            nand_init();
            nand_read((unsigned int)src, dest, len);
        }
    }
    
}

void clean_bss(void)
{
    /* 要从lds文件中获得 __bss_start, _end
	 */
	 extern int __bss_start,_end;
	 volatile unsigned int *start = (volatile unsigned int*)&__bss_start;
	 volatile unsigned int *end = (volatile unsigned int*)_end;

	 while(start < end)
	 {
        *start++ = 0;
	 }
	 
}

