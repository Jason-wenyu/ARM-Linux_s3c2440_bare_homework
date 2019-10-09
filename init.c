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

void copy2sdram(void)
{
    	/* 要从lds文件中获得 __code_start, __bss_start
     * 然后从0地址把数据复制到__code_start
     */
    extern int __code_start,__bss_start;
    
    
}


