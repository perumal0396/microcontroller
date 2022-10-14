#include<htc.h>

#define _XTAL_FREQ 20000000
__CONFIG( FOSC_HS & WDTE_OFF & PWRTE_OFF  & BOREN_ON & LVP_OFF );
//__CONFIG(0X1F7A);

void uart_init()
{
	TRISC6 = 0;
	TRISC7 = 1;
	TXSTA = 0X20;
	RCSTA = 0X90;
	SPBRG = 31;
	TXIF = 0;
}
void uart_tx(unsigned char msg)
{
	TXREG = msg;
	while(TXIF==0);
	TXIF = 0;
}
/*unsigned char uart_rx(void)
{
	CREN	=	1;
	while(RCIF==0);
	RCIF	=	0;
	return RCREG;
}
*/
void print_uart(unsigned char *str)
{
	
	while(*str)
	{
		uart_tx(*str);
		__delay_ms(25);
		str++;
	}
}

float distance(void)
{
	TMR1L=0;
	TMR1H=0;
	float distance,time;
	RB1 = 1;
	__delay_ms(10);
	RB1 = 0;
	while(RB2 == 0);
		TMR1ON = 1;
	while(RB2 == 1);
		TMR1ON = 0;
	time = (TMR1L | TMR1H<<8);
	distance = TMR1/58.8;
	return distance;
}

int main()
{
	int dist=0;
	TRISC = 0;
	PORTC = 0x00;
	TRISB1 = 0; //trigger of us is configured as output
	TRISB2 = 1; //echo of us is configured as input
	T1CON = 0X20;//PRESCALAR AND INTERNAL CLOCK;
	while(1)
	{
		dist = distance();
		dist = dist + 1;
		unsigned char message[]="Distance travelled ...\r\n";
		unsigned char mess[]="out of range.....\r\n";
		uart_init();
		print_uart(message);
		if(dist>=2&&dist<=400)
		{
			uart_tx(dist/100+48);
			//__delay_ms(25);
			dist=dist%100;
			uart_tx(dist/10+48);
			//__delay_ms(25);
			dist=dist%10;
			uart_tx(dist%10+48);
			//__delay_ms(25);
			uart_tx('c');
			//__delay_ms(25);
			uart_tx('m');
			//__delay_ms(25);
		}
		else
		{
			print_uart(mess);
			//__delay_ms(25);
		}
	__delay_ms(400);
	}
}