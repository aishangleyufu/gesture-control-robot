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
{ 
switch(number)
{
case 0:
action_set(0,0,0,0,0,0,100);
break; //ֱ��
//case 1:{action_set(0,0,-200,700,0,0,50);break;} //�ҽ�����											   #####
case 1:
action_set(0,0,-750,1200,0,0,40);
break; //�������	  			-300/-400						#####
case 2:
action_set(0,0,-600,0,1200,1200,100);
break; //��̧�ţ�ͬʱ�ҽŷ�ƽ							 #####
//case 4:{action_set(700,700,-350,-400,700,700,50);break;} //����� 3,4����һ�����
//case 5:{action_set(700,700,0,0,700,700,50);break;} //ת��	
case 3:
action_set(300,600,0,0,600,900,75);
break; //ǰ�㣬1�Ŷ��-500��6�Ŷ��+500��������ת�Ƶ�ǰ����#####
case 4:
action_set(300,600,450,350,600,900,50);
break; //�������	 	ǰ��								  #####
//case 8:{action_set(400,700,-750,300,700,1000,50);break;} //�ҽ����㣬�������ü�С	 
case 5:
action_set(300,600,0,300,0,300,50);
break; //�ҽ�����  ��ǰ��
case 6:
action_set(0,0,0,300,0,0,25);
break; //��Ż���	 	ͬʱ����ŷ�ƽ��ȡ��ǰ��			   #####
case 7:
action_set(-600,-600,0,300,0,0,25);
break; //��̧��										   #####
//case 12:{action_set(-700,-700,400,300,-700,-700,50);break;} //�����	11,12����һ����� ��ǰ��δ�ŵ�
//case 13:{action_set(-700,-700,0,0,-700,-700,50);break;} //��ת�� 
case 8:
action_set(-600,-400,0,0,-400,-600,75);
break; //ǰ�㣬1�Ŷ��-500��6�Ŷ��+500��������ת�Ƶ�ǰ���ϣ��������##### 
case 9:
action_set(-600,-400,-350,-450,-400,-600,50);
break; //�ҽ�����   	ǰ��								#####
//case 16:{action_set(-1000,-700,-250,-350,-700,-400,50);break;} //�������   
case 10:
action_set(0,0,-300,-450,-600,-600,50);
break; //��������ǰ��
//case 10:{action_set(0,0,-300,0,0,0,75);break;} //�һ�����ȡ��ǰ����Իص�3����̧�ţ����߻ص�0		  #####

case 11:
action_set(0,0,-300,0,-600,-800,50);
break; //�Һ�̧�ţ�ͬʱ�ҽŷ�ƽ							 #####
case 12:
action_set(-750,-400,0,0,-400,-750,75);
break; //���㣬1�Ŷ��+500��6�Ŷ��-500������ת�Ƶ���ţ��ҽ�����#####
case 13:
action_set(-750,-400,400,300,-400,-750,50);
break; //������	 	
case 14:action_set(-750,-600,0,250,0,0,50);
break; //�ҽŻ���	 	ͬʱ����ŷ�ƽ��ȡ��ǰ��			   #####								  #####
case 15:
action_set(0,0,0,250,0,0,40);
break; //�ҽŻ���	 	ͬʱ����ŷ�ƽ��ȡ��ǰ��			   #####
case 16:
action_set(600,600,0,250,0,0,40);
break; //���̧��										   #####
case 17:
action_set(600,600,0,0,600,600,50);
break; //���㣬1�Ŷ��+500��6�Ŷ��-500��������ת�Ƶ�ǰ����##### 
case 18:
action_set(600,600,-350,-450,600,600,50);
break; //������   									#####
case 19:
action_set(0,0,-300,-450,600,600,50);
break; //������   									#####
case 20:
action_set(0,0,-300,0,0,0,50);
break; //�������ȡ��ǰ����Իص�3����̧�ţ����߻ص�0		  #####

}
}


void action_series_do()
{switch(action_series_number)
{	  
	case 1:
	{switch(action_series_step)
		{case 1 : {action_base(20);break;} 
    	 case 2 : {action_base(10);break;}
		 case 3 : {action_base(9);break;}
		 case 4 : {action_base(8);break;}
		 case 5 : {action_base(7);break;}
		 case 6 : {action_base(6);break;}
		 case 7 : {action_base(5);break;}
		 case 8 : {action_base(4);break;}
		 case 9 : {action_base(3);break;}
		 case 10 : {action_base(2);break;}
		 case 11 : {action_base(1);break;}
		};break;} 
	 case 2:
	{switch(action_series_step)
		{case 1 : {action_base(20);break;} 
    	 case 2 : {action_base(10);break;}
		 case 3 : {action_base(9);break;}
		 case 4 : {action_base(8);break;}
		 case 5 : {action_base(7);break;}
		 case 6 : {action_base(6);break;}
		 case 7 : {action_base(5);break;}
		 case 8 : {action_base(4);break;}
		 case 9 : {action_base(3);break;}
		 case 10 : {action_base(2);break;}
		};break;}

		case 3:
	{switch(action_series_step)
		{case 1 : {action_base(20);break;}
		 case 2 : {action_base(19);break;}
		 case 3 : {action_base(18);break;}
		 case 4 : {action_base(17);break;}
		 case 5 : {action_base(16);break;}
		 case 6 : {action_base(15);break;}
		 case 7 : {action_base(14);break;}
		 case 8 : {action_base(13);break;}
		 case 9 : {action_base(12);break;}
		 case 10 : {action_base(11);break;}
		 case 11 : {action_base(1);break;}
		};break;}
		case 4:
	{switch(action_series_step)
		{case 1 : {action_base(20);break;}
		 case 2 : {action_base(19);break;}
		 case 3 : {action_base(18);break;}
		 case 4 : {action_base(17);break;}
		 case 5 : {action_base(16);break;}
		 case 6 : {action_base(15);break;}
		 case 7 : {action_base(14);break;}
		 case 8 : {action_base(13);break;}
		 case 9 : {action_base(12);break;}
		 case 10 : {action_base(11);break;}
		};break;}
		case 5:
	{switch(action_series_step)
		{case 1 : {action_base(0);break;}
		 case 2 : {action_base(6);break;}
		 case 3 : {action_base(5);break;}
		 case 4 : {action_base(4);break;}
		 case 5 : {action_base(0);break;}
		};break;}
		case 6:
	{switch(action_series_step)
		{case 1 : {action_base(0);break;}
		 case 2 : {action_base(10);break;}
		 case 3 : {action_base(9);break;}
		 case 4 : {action_base(8);break;}
		 case 5 : {action_base(0);break;}
		};break;}
		case 7:
	{switch(action_series_step)
		{case 1 : {action_base(0);break;}
		 case 2 : {action_base(16);break;}
		 case 3 : {action_base(15);break;}
		 case 4 : {action_base(14);break;}
		 case 5 : {action_base(0);break;}
		};break;}
		case 8:
	{switch(action_series_step)
		{case 1 : {action_base(0);break;}
		 case 2 : {action_base(20);break;}
		 case 3 : {action_base(19);break;}
		 case 4 : {action_base(18);break;}
		 case 5 : {action_base(0);break;}
		};break;}
		case 9:
	{switch(action_series_step)
		{case 1 : {action_base(9);break;}
		 case 2 : {action_base(8);break;}
		 case 3 : {action_base(5);break;}
		 case 4 : {action_base(4);break;}
		 case 5 : {action_base(3);break;}
		 case 6 : {action_base(1);break;}
		};break;} 
		 case 10:
	{switch(action_series_step)
		{case 1 : {action_base(9);break;}
		 case 2 : {action_base(8);break;}
		 case 3 : {action_base(5);break;}
		 case 4 : {action_base(4);break;}
		};break;} 

			 }
if(--action_series_step==0)action_series_flag=0,action_series_number=0;//���������ɣ�����ϵ�б�־λ��0

}

/********����ϵ������************/
void action_series_set(char number)
{
switch(number)
{case 1 : {action_series_number=1;action_series_step=11;break;}		 //��������һ��
case 2 : {action_series_number=2;action_series_step=10;break;}		 //������
case 3 : {action_series_number=3;action_series_step=11;break;}		 //����������һ��
case 4 : {action_series_number=4;action_series_step=10;break;}		 //��������
case 5 : {action_series_number=5;action_series_step=6;break;}		 //��������
case 6 : {action_series_number=6;action_series_step=6;break;}		 //��������
case 7 : {action_series_number=7;action_series_step=6;break;}		 //��������
case 8 : {action_series_number=8;action_series_step=6;break;}		 //��������
case 9 : {action_series_number=9;action_series_step=6;break;}		 //��������
case 10 : {action_series_number=10;action_series_step=4;break;}		 //��������
}
action_series_flag=1;
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

ICR1=40000;

TCCR3B|=(1<<WGM12)|(1<<WGM13)|(1<<CS11)|(1<<CS01);
TCCR3A|=(1<<COM3A1)|(1<<COM3B1)|(1<<COM3C1)|(1<<WGM11);  //ѡͨABC
	ICR3=40000;


//����20ms

OCR1C=3000;   //2000---3000--4000
OCR1B=3000;
OCR1A=3000;
OCR3C=3000;
OCR3B=3000;
OCR3A=3000;

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
   number=number+1;
   if(number>20){
   number=0;
   }
   
action_base(number);



   
   /*
    OCR1C=6000-OCR1C; 
	OCR1B=6000-OCR1B; 
	OCR1A=6000-OCR1A; 
    OCR3C=6000-OCR3C; 
	OCR3B=6000-OCR3B; 
	OCR3A=6000-OCR3A; 
	*/
	
}
}