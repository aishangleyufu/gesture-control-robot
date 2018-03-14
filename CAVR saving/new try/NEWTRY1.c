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
	OCR1A=3000;
	OCR1B=3000;
	OCR1C=3000;
	OCR3A=3000;
	OCR3B=3000;
	OCR3C=3000;
}