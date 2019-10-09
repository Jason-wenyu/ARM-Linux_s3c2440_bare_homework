#ifndef __UART_H
#define __UART_H

void uart0_init();
int putchar(int c);
int getchar(void);
int puts(const char *s);
void printHex(unsigned int val);

#endif
