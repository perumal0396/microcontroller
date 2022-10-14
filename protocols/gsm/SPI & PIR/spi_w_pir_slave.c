#include<htc.h>
#include<stdio.h>
#define XTAL_FREQ 20000000
__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_ON & LVP_OFF);

#define Rs RD0
#define Rw RD1
#define EN RD2

#define PIR RD3

void delay();
void spi_init(void);
unsigned char spi_transfer(unsigned char data);
void print_uart(unsigned char *str);
void uart_tx(unsigned char val);
unsigned char uart_rc(void);
void Lcd_cmd(unsigned char cmd);
void Lcd_data(unsigned char data);
void tmp_Lcd(unsigned char *k);
void Lcd_init();

void uart_init(void);
unsigned char string[]	="PIC initialized.....\n";
unsigned char message1[]="Initializing device....\n";
void spi_init(void)
{
	unsigned char temp;
	SSPSTAT	= 0x00;
	SSPCON	= 0x14;	//slave select
	SSPIE	= 0;
	SSPIF	= 0;
	SSPBUF	=0;
	SSPEN	= 1;
	TRISC3	= 1;
	TRISC4	= 1;
	TRISC5	= 0;
	TRISA5	= 1;
	SSPBUF	= 0;
	while(SSPIF == 0);
	SSPIF	=0;
	temp = SSPBUF;
	SSPSTAT	= 0x00;
}
unsigned char spi_transfer(unsigned char data)
{
	SSPBUF	= data;
	while(SSPIF == 0);
	SSPIF	= 0;
	return SSPBUF;
}
int main()
{
	unsigned char i,j=0,k=1,reciv,var=0x30;
	TRISB=0;
	TRISD0 = TRISD1 = TRISD2 = 0;
	TRISD3 = 1;
	char arr[30];
	uart_init();
	print_uart(message1);
	Lcd_init();
	Lcd_cmd(0x38);
	tmp_Lcd(message1);
	spi_init();
	delay();
	while(1)
	{
   	if(PIR==1)
	{
  		if(j==0)
		{
			reciv = spi_transfer(var);
			sprintf(arr,"Data from master %x\r",reciv);
			arr[29]=0;
			print_uart(arr);
			Lcd_cmd(0x0f);
			tmp_Lcd(arr);
			uart_tx(var);
			delay();
			uart_tx('\r');
			delay();
			var++;
			j++;
			k=0;
		}
	}
	else
	{
		k++;
	 if(k==1)
		{
			reciv	=	spi_transfer(var);
			sprintf(arr,"flash from master %x\r",reciv);
			arr[29]=0;
			print_uart(arr);
			Lcd_cmd(0x0f);
			tmp_Lcd(arr);
			uart_tx(var);
			delay();
			uart_tx('\r');
			delay();
			var++;
			j=0;
		}
	 }
  }
}
void print_uart(unsigned char *str)
{
	
	while(*str)
	{
		uart_tx(*str);
		delay();
		str++;
	}
}

void delay()
{
		TMR1CS=0;	
		T1CKPS0=1;
		T1CKPS1=1;
		TMR1H=0XFA;
		TMR1L=0XB0;
		TMR1ON=1;
		while(TMR1IF==0);
		TMR1IF=0;
		TMR1ON=0;
}
void uart_tx(unsigned char val)
{

	TXREG = val;
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
	TRISC6 = 0; //making TX as output
	TRISC7 = 1; //making RX as input

	TXSTA = 0x00; //Asynchronous mode, 8bit, low speed
	RCSTA = 0x00; //Enable UART to use RC7 and RC6 as UART module pins
	SPBRG = 31; //to generate 9600 baudrate
	TXEN = 1;
	SPEN = 1;
	TXIF=0;
	RCIF=0;
}
void Lcd_cmd(unsigned char cmd)
{
	Rs	=	0;
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
	Lcd_cmd(0x80);
	Lcd_cmd(0x06);
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
void tmp_Lcd(unsigned char *k)
{
	while(*k)
	{
		Lcd_data(*k);
		delay();
		k++;
	}
}