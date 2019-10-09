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
    	/* Ҫ��lds�ļ��л�� __code_start, __bss_start
     * Ȼ���0��ַ�����ݸ��Ƶ�__code_start
     */
    extern int __code_start,__bss_start;
    
    
}


