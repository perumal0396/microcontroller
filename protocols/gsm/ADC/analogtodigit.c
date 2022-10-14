#include<htc.h>
#define _XTAL_FREQ  20000000
__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_ON & LVP_OFF);


void port_config(void);
unsigned char adc(void);
void timer0(void);
void delay(void);
void led_interrupt(void);

int main()
{
	unsigned char max_value=15;
	
	port_config();
	timer0();
	adc();	
	led_interrupt();
	delay();
		
	while(1);
}
//port configuration
void port_config(void){

	TRISB1		=	0;
	TRISB0		=	1;
	PORTB		=	0;
	TRISA0		=	1;

}
//timer0 values in  50-milisecond
void timer0(void){

	T0CS	=	0;
	T0SE	=	0;
	PSA		=	0;
	PS2		=	1;
	PS1		=	1;
	PS0		=	0;
	TMR0	=	50;
	while(TMR0IF==0);
	TMR0	=	0;	
	GIE		=	1;
	PEIE	=	1;
	TMR0IE	=	1;
	TMR0IF	=	0;
}
//adc configuration
unsigned char adc(void){

	ADCON1	=	0xCE; //AD port configuration
	ADCON0	=	0x04;  //channel selecting
	GO_DONE	=	1;
	ADCS1	=	0;
	ADCS2	=	1;
	ADCS0	=	0;
	CHS2	=	0;
	CHS0	=	0;
	ADFM	=	1;
	while(!(GO_DONE==0))
	return	((127-ADRESL>>1))+15;

}
//interrput configuration
void led_interrupt (void){

	GIE 	= 0;
 	if(TMR1IF==0){
	TMR1IF	=	0;
	TMR1IE	=	0;
	TMR1H	=	0;
	TMR1L	= 	0;
}

	if(RB0==1){

			RB1	=	0;
			delay();			
	}
	else{
			RB1	=	1;
			delay();
		}
	TMR1IE	=	1;		
}

//timer1 10-milesecond  calculation  using a prescaler 8
void delay(void){

		TMR1CS	= 0;
		T1CKPS1 = 1;
		T1CKPS0 = 1;
		TMR1H	= 0x0B;
		TMR1L	= 0xDC;
		TMR1ON	= 1;
		while(!TMR1IF);
		TMR1IF	= 0;
		TMR1ON	= 0;
}	