#include<htc.h>
#define _XTAL_FREQ 20000000

__CONFIG( FOSC_HS & WDTE_OFF & PWRTE_OFF  & BOREN_ON & LVP_OFF  & WRT_OFF );

#define RS RC0
#define Rw RC1
#define EN RC2
#define PIR RD0

void Lcd_cmd(unsigned char cmd)
{
  RS=0;
  Rw=0;
  EN=1;
  PORTB=cmd;
  __delay_ms(2);
  EN=0;
}
void Lcd_init()
{
	Lcd_cmd(0x38);
	Lcd_cmd(0x0f);
	Lcd_cmd(0x01);
	Lcd_cmd(0x02);
	Lcd_cmd(0x06);
	Lcd_cmd(0x80);

}
/*void Lcd_clear()
{
	Lcd_clear(0x38);
	Lcd_clear(0x02);
}
*/
void Lcd_data(unsigned char data)
{
	RS=1;
	Rw=0;
	EN=1;
	PORTB=data;
	__delay_ms(2);
	EN=0;
}
void Lcd_tmp( unsigned char *c)
{
	while(*c)
	{
		Lcd_data(*c++);
		
	}
}
int main()
{
	int i,j=0,k=1;
	TRISB=0;
	TRISC0 =  TRISC1 = TRISC2 =0;
	TRISD0=1;
	Lcd_init();
//	Lcd_clear();
	Lcd_cmd(0x38);
	Lcd_tmp("START_PIR");
	while(1)
	{
		if(PIR==1)
		{  
		
			if(j==0)
			{
				Lcd_cmd(0x01);
				Lcd_tmp("PIR:OBJECT_DETCION");
				j++;
				k=0;
			}
		}
		else
		{  
          k++; 
			if(k==1)
			{
				Lcd_cmd(0x02);
				Lcd_tmp("PIR:NOT_DECTION");
				j=0;
			}
		}
	}
}