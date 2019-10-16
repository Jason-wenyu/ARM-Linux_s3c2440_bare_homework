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
        /*д�ɹ�����nand����*/
        *p = val;
        return 0;
    }
    else
    {
        /*NOR Flash����*/
        return 1;
    }
    
}

void copy2sdram(void)
{
    	/* Ҫ��lds�ļ��л�� __code_start, __bss_start
     * Ȼ���0��ַ�����ݸ��Ƶ�__code_start
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
    /* Ҫ��lds�ļ��л�� __bss_start, _end
	 */
	 extern int __bss_start,_end;
	 volatile unsigned int *start = (volatile unsigned int*)&__bss_start;
	 volatile unsigned int *end = (volatile unsigned int*)_end;

	 while(start < end)
	 {
        *start++ = 0;
	 }
	 
}

