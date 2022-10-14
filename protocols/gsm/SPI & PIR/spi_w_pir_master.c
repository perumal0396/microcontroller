#include<htc.h>
#include<stdio.h>
#define XTAL_FREQ 20000000
__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_ON & LVP_OFF);

#define SS_ RC1
#define Rs RD0
#define Rw RD1
#define EN RD2

#define PIR RD3

void spi_init(void);
unsigned char spi_transfer(unsigned char data);

void uart_tx(unsigned char val);
unsigned char uart_rx(void);
void uart_init();
void uart_tmp(unsigned char *str);

void Lcd_cmd(unsigned char cmd);
void Lcd_data(unsigned char data);
void Lcd_init();
void Lcd_tmp(unsigned char *c);

void delay();

unsigned char string[]="Pic initialized device...\n";
unsigned char msg[]="initialized device...\n";

void spi_init()
{
	unsigned char temp;
	SSPSTAT	=	0x00;
	SSPCON	=	0x10;
	SSPBUF	=	0;
	SSPEN	=	1;
	SSPIF	=	0;
	SSPIE	=	0;	
	TRISC3 	=	0;
	TRISC4	=	1;
	TRISC5	=	0;
	TRISC1	=	0;
	delay();
	SSPBUF	=	0;
	while(SSPIF==0)
	SSPIF	=	0;
	temp=SSPBUF	=0;
	SSPSTAT	=	0x00;
}
unsigned char spi_transfer(unsigned char data)
{
	SSPBUF	=	data;
	while(SSPIF==0);
	SSPIF	=	0;
	return SSPBUF;
}
int main()
{
	unsigned char i,j=0,k=1,recive,var=0x10;
	char arr[20];
	TRISB=0;
	TRISD0 = TRISD1 = TRISD2 =0;
	uart_init();
	TRISD3	=	1;
	PORTD = 0x00;
	uart_tmp(msg);
	Lcd_init();
	Lcd_cmd(0x38);
	Lcd_tmp(msg);
	spi_init();
	while(1)
	{	
	if(PIR==1)
	{
		if(j==0)
		{
			SS_	=	0;
			recive = spi_transfer(var);

			SS_	=	1;
			sprintf(arr,"PIR SENSOR WORKING %x\r",recive);
			arr[19]=0;
			uart_tmp(arr);
			Lcd_cmd(0x0f);
			Lcd_tmp(arr);
			for(i=0;i<50;i++)
			delay();
			var++;
			j++;
			k=1;
			
		}
	}
	
	else
	{
		k++;
		if(k==1)
		{																																						SS_	=	0;
			recive	= spi_transfer(var);
																																		SS_	=	1;
			sprintf(arr,"PIR NOT WORKS %x\r",recive);
			arr[19]=0;
			uart_tmp(arr);
			Lcd_cmd(0x0f);
			Lcd_tmp(arr);
			for(i=0;i<50;i++)
			delay();
			var++;
			j=0;
		}
	  }
	}		
}
void uart_tmp(unsigned char *str)
{
	while(*str)
	{
		uart_tx(*str++);
		delay();
	}
}
void Lcd_tmp(unsigned char *c)
{
	while(*c)
	{
		Lcd_data(*c++);
		delay();
	}
}
	
void delay()
{
		T1CKPS1	=	1;
		T1CKPS0	=	1;
		TMR1CS	=	0;
		TMR1ON	=	1;
		TMR1L	= 0xFA;
		TMR1H	= 0xBC;
		while(TMR1IF==0);
		TMR1IF	=	0;
		TMR1ON	=	0;
}
void uart_tx(unsigned char val)
{
	TXREG	=	val;
	while(TXIF==0);
	TXIF	=	0;
}
unsigned char uart_rx(void)
{
	
	while(RCIF==0);
	RCIF	=	0;
	return RCREG;
}
void uart_init(void)
{
	TXSTA	=	0;
	RCSTA	=	0;
	TRISC6	=	0;
	TRISC7	=	1;
	SPEN	=	1;
	SPBRG	=	31;
	TXIF	=	0;
	RCIF	=	0;
	TXEN	=	1;
}
void Lcd_cmd(unsigned char cmd)
{
	Rs	= 	0;
	Rw	=	0;
	EN	=	1;
	PORTB=cmd;
	delay();
	EN	=	0;
}
void Lcd_init()
{
	Lcd_cmd(0x38);
	Lcd_cmd(0x0f);
	Lcd_cmd(0x02);
	Lcd_cmd(0x01);
	Lcd_cmd(0x06);
	Lcd_cmd(0x80);
}
void Lcd_data(unsigned char data)
{
	Rs	=	1;
	Rw	=	0;
	EN	=	1;
	PORTB=data;
	delay();
	EN	=	0;
}
