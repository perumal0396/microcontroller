 /*************************************************/
 /* NAME        :   PERUMAL R                     */               
 /* DESCRIPTION :  UART INTERFACE WITH PIR SENSOR */                                                                              
 /* DATE        :   14/01/2021                    */ 
 /*                                               */
 /*************************************************/

#include<htc.h>   // header files in Hi_TEC compiler
#define _XTAL_FREQ 20000000  //frequence
__CONFIG( FOSC_HS & WDTE_OFF & PWRTE_OFF  & BOREN_ON & LVP_OFF  & WRT_OFF );
/* power down mode watchclock_dog */

#define RS RC0  /* Lcd register select pin Rs*/
#define Rw RC1  /* Lcd register read/write pin Rw*/ 
#define EN RC2  /* Lcd Enable pin EN */
#define PIR RC3 /* pir sensor input Rc3 pin HIGH */

void uart_tx(unsigned char val);   /*uart transmited to data unsigned char val */
unsigned char uart_rx(void); /*uart reciver */  
void uart_init(void);		/*uart initialized to ports */

void uart_tmp(unsigned char *s);/*uart_tmp is calling tha funcion to uart-tmp strings */

void delay(void); /*user givening a delay  times */
void Lcd_cmd(unsigned char cmd); /*Lcd_cmd assigned to data or transmit */ 
void Lcd_data(unsigned char data); /*Lcd_data assigned to the recvier function */
void Lcd_tmp(unsigned char *c);  /*Lcd_tmp printing characteris */
void Lcd_init();          /*Lcd_initialized funcion */

int main()             
{
	int i,j=0,k=1;      
	TRISC0=TRISC1=TRISC2=0; /*select or make it PORTC Output pin */
	TRISC3=1; /* TRISC3 select with PIR sensor HIGH=1 */
 	TRISC6=0; /*TRISC6 select with make it Output in uart reciver pin */
	TRISC7=1; /*TRISC7 select with uart transmit with input=1 */
	TRISB=0; /*TRISCB was make it Output pin 0 */
	Lcd_init();	/*Lcd_initialized with function */
	Lcd_cmd(0x01);	/*Lcd_cmd transmit the address */
	Lcd_tmp("PIR SENSOR:\n"); /*Lcd_tmp printing charactrize */
    uart_init();			/*Uart_initialized funcion */
	uart_tmp("PIR SENSOR:\n");/*uart_tmp printing charactriz */
    while(1) /*keep on working function */
	{
		if(PIR==1)	/*PIR sensor condition with 1 means work On */
		{	
			if(j==0)  /*condition true */
			{	
				Lcd_cmd(0x02);	 /* Lcd_cmd address */
				Lcd_tmp("HUMANE_WAS_MOVING\n");	/*Lcd_tmp printing charactrize */
				uart_tmp("HUMANE_WAS_MOVING\n"); /*uart_tmp printing charactriz */
				j++;
			 	k=0;		
			}
		}
	 
	    else    /*false condition */
	    {
		  k++;
		   if(k==1) /*	 condition is make in check and  if condition */
            {	
			  Lcd_cmd(0x38);  /*Lcd_cmd address  */
			  Lcd_tmp("NOT_DETECTION=\n");/*Lcd_tmp printing charactrize */	  	
			  uart_tmp("NOT_DETECTION=\n");/*uart_tmp printing charactrize */
			  j=0;
			 
		    }
	    } 
   } 
}

void delay() /* delay function */
{
	T1CKPS1=1; /*timer1 prescaler function :8 */
	T1CKPS0=1; /*timer1 prescaler function :8*/
	TMR1CS=0;  /*timer1 clock select output */
	TMR1H=0X30;	/*timer1 high making 100 selected */
	TMR1L=0XB0; /*timer1 low clock selected */
	TMR1ON=1;   /* timer1 on input */
	while(TMR1IF==0);/* while checking timer function */
	TMR1IF=0;      /*timer1 interupt flag=0 */
	TMR1ON=1;   /* timer1 is on */
}

void uart_init()/* uart_initialize function */
{	
	TXSTA=0x00; /*transmit state */
	RCSTA=0x00;/* reciver state */
	SPBRG=31; /*baud rate generator register */
	TXEN=1;  /*transmit enable bit */
	SPEN=1;  /*serial port enable bit */
	TXIF=0;  /*transmit flag bit */
	RCIF=0; /*reciver flag bit */
}

void uart_tx(unsigned char val) /*uart transmit function val */
{
	TXREG=val;      /*transmit register */
	while(TXIF==0); /*transmit flag  bit check */
	TXIF=0;			/*transmit flag bit */
}
unsigned char uart_rx(void) /* uart reciver funcion */
{
	while(RCIF==0);       /* rciver flag zero and keep on checking that true flg */
	RCIF=0;				/* reciver flag assinged defulat values zero */
	return RCREG;		/* reciver register return the flag */
}

void Lcd_cmd(unsigned char cmd) /* lcd_cmd transmiting data to lcd funcion */
{
  RS=0;    /*register select Rs pin */
  Rw=0;	  /*register read/write Rw pin */
  EN=1;	  /*Enable bit will on */
  PORTB=cmd;	/* PORTB transmit to data lcd_cmd */
  delay();		/* delay function */
  EN=0;			/* enable bit output */
}	
void Lcd_init()	 
{
	Lcd_cmd(0x38); /* Lcd_cmd trnsmiting a address */
	Lcd_cmd(0x01); /* Lcd_cmd trnsmiting a address */
	Lcd_cmd(0x02); /* Lcd_cmd trnsmiting a address */
	Lcd_cmd(0x0f); /* Lcd_cmd trnsmiting a address */
	Lcd_cmd(0x06); /* Lcd_cmd trnsmiting a address */
	Lcd_cmd(0x80); /* Lcd_cmd trnsmiting a address */

}
void Lcd_data(unsigned char data)
{
	RS=1;  /* register select Rs pin input */
	Rw=0;  /*register read/write output pin */
	EN=1;  /*Enable bit input */
	PORTB=data; /*PORTB is reciver the data funcion */
	delay();  /* delay function */
	EN=0;	/*Enable output */
}	
void uart_tmp(unsigned char *s)
{
	while(*s) 
	{
		uart_tx(*s++); /*uart_transmiting printing a string or charactrize */

	}
}
void Lcd_tmp(unsigned char *c)
{
	while(*c)
	{
		Lcd_data(*c++);   /* Lcd_data is printing the charatrize in lcd function */ 
	}
}