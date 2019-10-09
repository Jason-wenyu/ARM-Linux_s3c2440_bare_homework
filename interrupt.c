#include "s3c2440_soc.h"

typedef void (*irq_func)(int);
irq_func irq_arry[32];

/* SRCPND 用来显示哪个中断产生了, 需要清除对应位
 * bit0-eint0
 * bit2-eint2
 * bit5-eint8_23
 */

/* INTMSK 用来屏蔽中断, 1-masked
 * bit0-eint0
 * bit2-eint2
 * bit5-eint8_23
 */

/* INTPND 用来显示当前优先级最高的、正在发生的中断, 需要清除对应位
 * bit0-eint0
 * bit2-eint2
 * bit5-eint8_23
 */

/* INTOFFSET : 用来显示INTPND中哪一位被设置为1
 */
 

void handle_irq_c(void)
{
    /* 分辨中断源 */
	int bit = INTOFFSET;

	/* 调用对应的处理函数 */
	irq_array[bit](bit);
	
	/* 清中断 : 从源头开始清 */
	SRCPND = (1<<bit);
	INTPND = (1<<bit);	
}

void register_irq(int irq, irq_func fp)
{
    irq_array[irq] = fp;

	INTMSK &= ~(1<<irq);
}

