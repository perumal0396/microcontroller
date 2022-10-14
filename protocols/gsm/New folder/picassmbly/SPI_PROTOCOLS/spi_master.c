#include<htc.h>
#include<stdio.h>
#define_XTAL_FREQ 20000000
__CONFIG (FOSC_HS&WDTE_OFF&PWRTE_OFF&BOREN_NO&LVP_OFF);
void display();
void spi_init(void);
unsigned char spi_transfer(unsigned char data);
void print_uart(unsigned char *str);
void uart_tx(unsigned char val);
unsigned char uart_rc(void);
void uart_init(void);
unsigned char string[]="pic initialized\n";
unsigned char message[]="initialized device\n";
