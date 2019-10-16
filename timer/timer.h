#ifndef _TIMER_H
#define _TIMER_H

typedef void(*timer_func)(void);

typedef struct timer_desc {
	char *name;
	timer_func fp;
}timer_desc, *p_timer_desc;

void timer_init(void);
int register_timer(char *name, timer_func fp);
int unregister_timer(char *name);
void udelay(int n);
void mdelay(int m);
unsigned long long get_system_time_us(void);
unsigned int delta_time_us(unsigned long long pre, unsigned long long now);


#endif // !_TIMER_H

