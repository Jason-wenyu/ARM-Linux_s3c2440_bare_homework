#include "../s3c2440_soc.h"
#include "led.h"
#include "../lcd/framebuffer.h"
#include "../lcd/font.h"
#include "../lcd/geometry.h"
#include "../timer/timer.h"


void delay(volatile int d)
{
	while (d--);
}

/* ÿ10ms�ú���������һ�� 
 * ÿ500ms����һ��LEDʵ�ּ���
 */
 void led_timer_irq(void)
 {
    static int timer_num = 0;
    static int cnt = 0;
    int tmp;
    
    timer_num++;
    if(timer_num < 50)
    {
        return 0;
    }
    timer_num = 0;
    cnt++;

	tmp = ~cnt;
	tmp &= 7;
	GPFDAT &= ~(7<<4);
	GPFDAT |= (tmp<<4);
 }

 void led_init(void)
{
	/* ����GPFCON��GPF4/5/6����Ϊ������� */
	GPFCON &= ~((3<<8) | (3<<10) | (3<<12));
	GPFCON |=  ((1<<8) | (1<<10) | (1<<12));
}

 void led_display(void)
 {
     clear_screen(0xffffff);
     /* return����ʾ */
     fb_disp_rectangle(340,200,110,40,0xff0000);
 
     fb_print_string(350,215,"Return",0);
     fb_print_string(100,80,"LED TEST",0xff0000);
 }

void led_test(void)
{
    int val = 0;
    int index;
	led_display();
    register_timer("led", led_timer_irq);
    // /* ѭ������ */
    while(1)
    {
        index = index_read();
		if (index == 11)
			break;
	}
	unregister_timer("led");
}
 


