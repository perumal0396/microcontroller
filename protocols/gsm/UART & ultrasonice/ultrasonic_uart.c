#include<htc.h>
#define _XTAL_FREQ 20000000
__CONFIG( FOSC_HS & WDTE_OFF & PWRTE_OFF  & BOREN_ON & LVP_OFF  & WRT_OFF );

#define triger RD0
#define echo   RD1

void uart_tx(unsigned char val);
unsigned char uart_rx(void);
void uart_init(void);

void uart_tmp(unsigned char *s);

int sensor()
{  
    int dist=0;
	T1CKPS1=0;
	T1CKPS0=0;
	TMR1CS=0;
	TMR1H=0;
	TMR1L=0;
	triger=1;
	__delay_ms(2);
	triger=0;
	while(!echo);
	TMR1ON=1;
	while(echo);
	TMR1ON=0;
    
     dist =(TMR1L |(TMR1H<<8))/58.82;
	return dist;
}
void uart_init()
{	
	TXSTA=0x00;
	RCSTA=0x00;
	SPBRG=31;
	TXEN=1;
	SPEN=1;
	TXIF=0;
	RCIF=0;
}

void uart_tx(unsigned char val)
{
	TXREG=val;
	while(TXIF==0);
	TXIF=0;
}
unsigned char uart_rx(void)
{
	while(RCIF==0);
	RCIF=0;
	return RCREG;
}
void uart_tmp(unsigned char *s)
{
	while(*s)
	{
		uart_tx(*s++);
	}
}
int main()
{
	int dist=0;
	
	TRISC6=0;
	TRISC7=1;
	TRISD0=0;
	TRISD1=1;
	uart_init();
	uart_tmp("ultrasonic....");
	while(1)
	{
		dist = sensor()/5;
		if(dist==1)
		{
			uart_tmp("level_1...2CM");
			__delay_ms(2);
		}
		if(dist==2)
		{
			uart_tmp("level_2....4CM");
			__delay_ms(2);
		}
		if(dist==3)
		{
			uart_tmp("level_3....6CM");
			__delay_ms(2);
		}
	 }
}			