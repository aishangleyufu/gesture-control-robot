/*======
ʹ�ö�ʱ��1��OCR1A,OCR1B,OCR1C�����ܽ�ͬʱ���PWM����
�ڿ���PWM��ģʽ�£�top=0x03ff=1023
OCRnX��topʱ�̸���
Ƶ��=8000000/8/1023=977.5HZ
=======================================================*/
#include <iom128v.h> 
#include <macros.h> 
int action_series_step=0;
int action_series_number=0;
int action_series_flag=0;

void delay_1ms(void)//1ms��ʱ���� 
{ 
  long int i; 
  for (i=0;i<150*16;i++) ;//��Ϊ��8M�������������8�������ʱ������׼ 
  
}    
void delay_nms(long int n)//��ʱn���� 
{ 
  long int i; 
  for (i=0;i<n;i++)//ִ��n��1������ʱ 
  {delay_1ms();}  
} 



void main (void)
{
 int i,j,k;
 int number=0;
 DDRB|=BIT(PB7);
 DDRB|=BIT(PB6);
 DDRB|=BIT(PB5);
 DDRE|=BIT(PE3);
 DDRE|=BIT(PE4);
 DDRE|=BIT(PE5);
//��OCR1A�ܽ�����Ϊ���

TCCR1B|=(1<<WGM12)|(1<<WGM13)|(1<<CS11);

//ʱ��8��Ƶ
TCCR1A|=(1<<COM1C1)|(1<<COM1A1)|(1<<COM1B1)|(1<<WGM11);   //ѡͨABC  
//TCCR1A|=(1<<COM1C1)|(1<<WGM11);

//����PWMģʽtop:ICR1

ICR1=20000; //40000;

TCCR3B|=(1<<WGM12)|(1<<WGM13)|(1<<CS11)|(1<<CS01);
TCCR3A|=(1<<COM3A1)|(1<<COM3B1)|(1<<COM3C1)|(1<<WGM11);  //ѡͨABC
	ICR3=20000;


//����20ms

OCR1C=1000;   //2000---3000--4000
OCR1B=1000;
OCR1A=1000;
OCR3C=1000;
OCR3B=1000;
OCR3A=1000;

//������

TCNT1=0x0000;

/*TCCR1B|=(1<<WGM12)|(1<<WGM13)|(1<<CS11);
TCCR1A|=(1<<COM1C1)|(1<<WGM11);
ICR1=40000;   */


//���������
while(1)
{
for(i=0;i<1000;i++){
    for(j=0;j<1000;j++){
       for(k=0;k<8;k++){   //k<10,Լ����  
         ; 
		 }
    }
}

    OCR1C=3000-OCR1C; 
	OCR1B=3000-OCR1B; 
	OCR1A=3000-OCR1A; 
    OCR3C=3000-OCR3C; 
	OCR3B=3000-OCR3B; 
	OCR3A=3000-OCR3A; 

	
}
}