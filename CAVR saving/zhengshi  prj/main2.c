/*======
ʹ�ö�ʱ��1��OCR1A,OCR1B,OCR1C�����ܽ�ͬʱ���PWM����
�ڿ���PWM��ģʽ�£�top=0x03ff=1023
OCRnX��topʱ�̸���
Ƶ��=8000000/8/1023=977.5HZ
=======================================================*/
#include<iom128v.h>
#include<string.h> 
#include <macros.h> 
#define fosc 16000000  //����16MHZ
#define baud 38400  //������
int flag=0;
int tempflag1=0;
int tempflag2=0;


void PWM_init()
{
   DDRB|=0XE0;
   DDRE|=0X38;
TCCR1B|=(1<<WGM12)|(1<<WGM13)|(1<<CS11);
TCCR1A|=(1<<COM1C1)|(1<<COM1A1)|(1<<COM1B1)|(1<<WGM11);   //ѡͨABC                 
	ICR1=40000;
TCCR3B|=(1<<WGM12)|(1<<WGM13)|(1<<CS11)|(1<<CS01);
TCCR3A|=(1<<COM3A1)|(1<<COM3B1)|(1<<COM3C1)|(1<<WGM11);  //ѡͨABC
	ICR3=40000;
	OCR1A=2000;
	OCR1B=2000;
	OCR1C=2000;
	OCR3A=2000;
	OCR3B=2000;
	OCR3C=2000;
	TCNT1=0x0000;
	TCNT3=0x0000;
}

void action_set(int ch_1a, int ch_1b, int ch_1c, int ch_3a, int ch_3b, int ch_3c, int action_do_last)
{
    OCR1A=ch_1a+3000;
	OCR1B=ch_1b+3000;
	OCR1C=ch_1c+3000;
	OCR3A=ch_3a+3000;
	OCR3B=ch_3b+3000;
	OCR3C=ch_3c+3000;
}

void action_base(int number)
{ switch(number)
{
case 0:{action_set(0,0,0,0,0,0,100);break;} //ֱ��
//case 1:{action_set(0,0,-200,700,0,0,50);break;} //�ҽ�����											   #####
case 1:{action_set(0,0,-750,1200,0,0,40);break;} //�������	  			-300/-400						#####
case 2:{action_set(0,0,-600,0,1200,1200,100);break;} //��̧�ţ�ͬʱ�ҽŷ�ƽ							 #####
//case 4:{action_set(700,700,-350,-400,700,700,50);break;} //����� 3,4����һ�����
//case 5:{action_set(700,700,0,0,700,700,50);break;} //ת��	
case 3:{action_set(300,600,0,0,600,900,75);break;} //ǰ�㣬1�Ŷ��-500��6�Ŷ��+500��������ת�Ƶ�ǰ����#####
case 4:{action_set(300,600,450,350,600,900,50);break;} //�������	 	ǰ��								  #####
//case 8:{action_set(400,700,-750,300,700,1000,50);break;} //�ҽ����㣬�������ü�С	 
case 5:{action_set(300,600,0,300,0,300,50);break;} //�ҽ�����  ��ǰ��
case 6:{action_set(0,0,0,300,0,0,25);break;} //��Ż���	 	ͬʱ����ŷ�ƽ��ȡ��ǰ��			   #####
case 7:{action_set(-600,-600,0,300,0,0,25);break;} //��̧��										   #####
//case 12:{action_set(-700,-700,400,300,-700,-700,50);break;} //�����	11,12����һ����� ��ǰ��δ�ŵ�
//case 13:{action_set(-700,-700,0,0,-700,-700,50);break;} //��ת�� 
case 8:{action_set(-600,-400,0,0,-400,-600,75);break;} //ǰ�㣬1�Ŷ��-500��6�Ŷ��+500��������ת�Ƶ�ǰ���ϣ��������##### 
case 9:{action_set(-600,-400,-350,-450,-400,-600,50);break;} //�ҽ�����   	ǰ��								#####
//case 16:{action_set(-1000,-700,-250,-350,-700,-400,50);break;} //�������   
case 10:{action_set(0,0,-300,-450,-600,-600,50);break;} //��������ǰ��
//case 10:{action_set(0,0,-300,0,0,0,75);break;} //�һ�����ȡ��ǰ����Իص�3����̧�ţ����߻ص�0		  #####

case 11:{action_set(0,0,-300,0,-600,-800,50);break;} //�Һ�̧�ţ�ͬʱ�ҽŷ�ƽ							 #####
case 12:{action_set(-750,-400,0,0,-400,-750,75);break;} //���㣬1�Ŷ��+500��6�Ŷ��-500������ת�Ƶ���ţ��ҽ�����#####
case 13:{action_set(-750,-400,400,300,-400,-750,50);break;} //������	 	
case 14:{action_set(-750,-600,0,250,0,0,50);break;} //�ҽŻ���	 	ͬʱ����ŷ�ƽ��ȡ��ǰ��			   #####								  #####
case 15:{action_set(0,0,0,250,0,0,40);break;} //�ҽŻ���	 	ͬʱ����ŷ�ƽ��ȡ��ǰ��			   #####
case 16:{action_set(600,600,0,250,0,0,40);break;} //���̧��										   #####
case 17:{action_set(600,600,0,0,600,600,50);break;} //���㣬1�Ŷ��+500��6�Ŷ��-500��������ת�Ƶ�ǰ����##### 
case 18:{action_set(600,600,-350,-450,600,600,50);break;} //������   									#####
case 19:{action_set(0,0,-300,-450,600,600,50);break;} //������   									#####
case 20:{action_set(0,0,-300,0,0,0,50);break;} //�������ȡ��ǰ����Իص�3����̧�ţ����߻ص�0		  #####

}
}



//=========================================================

//================UART=================
/***************************************************************************/
/*����1���Գ���                                          */

/***********************************�궨��**********************************/

/****************************************************************************
��������:uart1��ʼ������
��ڲ���:
���ڲ���:
****************************************************************************/
void uart1_init(void) //USART1��ʼ��
{
 //DDRD|=(1<<2)|(1<<3);   //  IO
 UCSR1B = 0x00;   //�ر�USART1
 UCSR1A = 0x00;   //����ʹ�ñ��ٷ���
 UCSR1C = (1<<UCSZ11)|(1<<UCSZ10);//����λΪ��λ
 UBRR1L=(fosc/16/(baud+1))%256;//�첽����ģʽ�£�UBRR�ļ��㹫ʽ
 UBRR1H=(fosc/16/(baud+1))/256;
 UCSR1B =(1<<RXEN1)|(1<<TXEN1); //����ʹ�ܣ�����ʹ��
}
/****************************************************************************
��������:uart1���͵��ֽ�����
��ڲ���:c
���ڲ���:
****************************************************************************/
void putchar1(unsigned char c)//����1�����ַ�
 {  
     while (!(UCSR1A&(1<<UDRE1)));//����������һ׼������
  UDR1=c;    
 } 
 
/****************************************************************************
��������:uart1���յ��ֽ�����
��ڲ���:
���ڲ���:
****************************************************************************/
unsigned char getchar1(void) //����1�ӻ�������
   {
  while(!(UCSR1A& (1<<RXC1)));
     return UDR1;   //�����յ����ַ�����
 } 
 
/****************************************************************************
��������:uart1�����ַ�������
��ڲ���:*s
���ڲ���:
****************************************************************************/    
void puts1(char *s)
 {
 while (*s)
  {
  putchar1(*s);
  s++;
  } 
        putchar1(0x0a);//�س�����
     putchar1(0x0d);
 } 
 
/****************************************************************************
��������:
��ڲ���:
���ڲ���:
****************************************************************************/
/*void main(void)
{
 unsigned char i;
  uart1_init();
  puts1("HELLO!");
 while(1)
    {    
        puts1("test ok!");        
 }
} 
*/

//======================================================

/*
void  Pwm1A_Init(void)

{
DDRB|=0XE0;
DDRE|=0X38;
//DDRB|=BIT(PB7);
TCCR1B|=(1<<WGM12)|(1<<WGM13)|(1<<CS11);
TCCR1A|=(1<<COM1C1)|(1<<WGM11);
ICR1=Period;
OCR1C=0x0200;
TCNT1=0x0000;
} 

void  Pwm1B_Init(void)

{

//DDRB|=BIT(PB7);
TCCR1B|=(1<<WGM12)|(1<<WGM13)|(1<<CS11);
TCCR1A|=(1<<COM1C1)|(1<<WGM11);
ICR1=Period;
OCR1C=0x0200;
TCNT1=0x0000;
} 

void  Pwm1C_Init(void)

{

//DDRB|=BIT(PB7);
TCCR1B|=(1<<WGM12)|(1<<WGM13)|(1<<CS11);
TCCR1A|=(1<<COM1C1)|(1<<WGM11);
ICR1=Period;
OCR1C=0x0200;
TCNT1=0x0000;
} 

void  Pwm3A_Init(void)
{
//DDRE|=BIT(PE3);
TCCR3B|=(1<<WGM12)|(1<<WGM13)|(1<<CS11)|(1<<CS01);
TCCR3A|=(1<<COM3A1)|(1<<WGM11);
ICR3=Period;
OCR3A=0x0400;
TCNT3=0x0000;
}
 
void  Pwm3B_Init(void)
{
//DDRE|=BIT(PE4);
TCCR3B|=(1<<WGM12)|(1<<WGM13)|(1<<CS11)|(1<<CS01);
TCCR3A|=(1<<COM3B1)|(1<<WGM11);
ICR3=Period;
OCR3A=0x0400;
TCNT3=0x0000;
} 

void  Pwm3C_Init(void)
{
//DDRE|=BIT(PE4);
TCCR3B|=(1<<WGM12)|(1<<WGM13)|(1<<CS11)|(1<<CS01);
TCCR3A|=(1<<COM3B1)|(1<<WGM11);
ICR3=Period;
OCR3A=0x0400;
TCNT3=0x0000;
} 
   */
   
void io_init()
{
	DDRA=0x00;
	DDRB=0x00;
	DDRC=0x00;
	DDRD=0x00;
	DDRE=0x00;
	DDRF=0x00;
	PORTA=0x00;
	PORTB=0x00;
	PORTC=0x00;
	PORTD=0x00;
	PORTE=0x00;
	PORTF=0x00;
}

void key_init()
{
io_init();
	
	DDRB=0xff;      
	PORTB=0xff;  
	
	DDRE=0x00;  
	PORTE=0xF0;

}
  



void main(){
   //unsigned char i;
     int a=0;
	 int i,j,k=0;
   PWM_init();
   //key_init();
   //uart1_init();
   //puts1("HELLO!");
   while(1){
   for(i=0;i<100;i++){
   			{for(j=0;j<10;j++)
   			{for(k=0;k<1;k++)   //k<10,Լ����  
    					; 
 	         }
   	         }
			 }
   OCR1A=6000-OCR1A;
	OCR1B=6000-OCR1B;
	OCR1C=6000-OCR1C;
	OCR3A=6000-OCR3A;
	OCR3B=6000-OCR3B;
	OCR3C=6000-OCR3C;
 /*  		if(PINE & 0x10)
 		{tempflag1=1;
			PORTB |=0x10;}
		    else
			  PORTB &=0xef;
		if(PINE & 0x20)
			{tempflag2=1;
			PORTB |=0x20;}
			else
			  PORTB &=0xdf;
		if(tempflag1==1&&(PINE & 0x10 ==0))
		    {flag++;
			 tempflag1=0;
			}
		if(tempflag2==1&&(PINE & 0x20 ==0))
		    {flag--;
			 tempflag2=0;
			 }
			 if(flag<0)
			   flag=0;
			   if(flag>20)
			    flag=20;
			*/
			//action_base(a);
			/*
			for(i=0;i<1000;i++){
   			{for(j=0;j<1000;j++)
   			{for(k=0;k<8;k++)   //k<10,Լ����  
    					; 
 	         }
   	         }
			 }
   	   	    a++;
   			if(a>20){
    		a=0; 
			}
			*/
			//puts1("test ok!");
   }

}

