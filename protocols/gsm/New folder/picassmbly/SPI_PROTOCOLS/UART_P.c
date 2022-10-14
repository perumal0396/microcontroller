#include<htc.h>
#define _XTAL_FREQ 20000000
__CONFIG( FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_ON & LVP_OFF );
void uart_tx(unsigned char val);
unsigned char uart_rc(void);
void uart_init(void);
void dealy();
void dealy()
{
	TMR1CS=1;
	T1CKPS0=1;
	T1CKPS1=1;
	TMR1H=0X3C;
	TMR1L=0XB0;
	TMR1ON=1;
	while(!TMR1IF);
	TMR1IF=0;
	TMR1ON=0;
}
int main()
{
	uart_init();
	uart_tx('L');
	dealy();
	uart_tx('i');
	dealy();
	uart_tx('n');
	dealy();
	uart_tx('u');
	dealy();
	uart_tx('x');
	dealy();
	while(1);
}
void uart_tx(unsigned char val)
{
	TXREG=val;
	while(TXIF==0);
	TXIF=0;
}
unsigned char uart_rc(void)
{
	while(RCIF==0);
	RCIF=0;
	return RCREG;
}
void uart_init(void)
{
	TRISC6=0;
	TRISC7=1;
	TXSTA=0x00;
	RCSTA=0x00;
	SPBRG=31;
	TXEN=1;
	SPEN=1;
	TXIF=0;
	RCIF=0;
}