#include<iom128v.h>
#include<macros.h>
#include"include.h"
sbit PWMOUT0=P0^0;
sbit PWMOUT1=P0^1;
sbit PWMOUT2=P0^2;
sbit PWMOUT3=P0^3;
sbit PWMOUT4=P0^4;
sbit PWMOUT5=P0^5;
char order0=0,order1=0,signal=0;
unsigned int PWMDTY[6]={3340,3260,3240,3440,3150,3200};//��ΧӦ���ڣ�0,5000�������ܵ���0����5000.�������۲��Ӱ��ʱ��ԭ��֪��
unsigned int PWMDTY_GET[6]={3340,3260,3240,3440,3150,3200}; //���ڴ�����������PWMDTYֵ�������ڿ�ʼʱ����PWMDTY,������һ��������PWMDTY�������ڻ��ҵ�����
unsigned int PWMDTY_BASE[6]={3340,3260,3190,3440,3150,3200};
unsigned int time=0; //20ms��1
int count=0;
char action=0;//1��ʾ�ڶ�����0��ʾ���ڶ�
char action_series_flag=0;//1��ʾ�ڶ���ϵ���У�0��ʾ���ڶ���ϵ����
char action_series_number=0;
char action_series_step=0;
unsigned int action_last=0;//������������
unsigned int action_do_last=0;
unsigned int distance=0;
int PWMDTY_change[6]={0};//ÿ���ڶ����ı䣬С�ģ������ɸ�
char mode=1;
char status=0;
char head=0;
#define ZERO 0;
//////
extern unsigned int time;
extern bit busy;
extern char action;//1��ʾ�ڶ�����0��ʾ���ڶ�
unsigned int period=10000;
//////
code char action_mix[21][7]=
{{0,1,1,3,8,12,17}, //0
{0,2,11,2,2,11,11},  //1
{0,3,20,3,3,20,20},   //2
{0,4,19,4,4,19,19},   //3
{0,5,18,5,5,18,18},   //4
{0,6,17,6,6,17,17}, //5
{0,7,16,0,0,0,0},  //6
{0,8,15,8,8,15,15},   //7
{0,9,14,9,9,14,14},   //8
{0,10,13,10,10,13,13},   //9
{0,20,12,20,20,12,12}, //10
{0,20,12,20,20,12,12},  //11
{0,10,13,20,20,13,13},   //12
{0,9,14,9,9,14,14},   //13
{0,8,15,8,8,15,15},   //14
{0,7,16,0,0,0,0}, //15
{0,6,17,6,6,17,17},  //16
{0,5,18,5,5,18,18},   //17
{0,4,19,4,4,19,19},   //18
{0,3,20,3,3,20,20},   //19
{0,2,11,0,0,0,0} //20
};
void action_set(int goal0,int goal1,int goal2,int goal3,int goal4,int goal5,unsigned int t);
void action_base(char a);
void action_series_set(char number);
void action_series_do();
unsigned int ultrasonic();

void main()
{ 
unsigned int change=100;
P0M0=0XFF;
P0M1=0X00;//P0������
TIMEinit();
UARTinit();//���ڼ��������⣬�����ʼ��Ӧ�÷���TIMEinit����
//signal='s';
trig=0;	
//distance=ultrasonic();
if(time<=100);
while(1)
{			  	 
if(time>=26)
{			    //////time_period==26 times
if(mode==1){
head=0;
switch(signal){
case'm':{mode=0;break;}
case'0':{head=0;break;}
case'1':{head=1;break;}
case'2':{head=2;break;}
case'3':{head=3;break;}
case'4':{head=4;break;}
case'5':{head=5;break;}
case'6':{head=6;break;}
}
if(action==0&&head!=0){//head=0,��ֹͣ
status=action_mix[status][head];
action_base(status);
}
}
else if(action_series_flag)			//�����������ϵ�л�ûִ���꣬��ִ��
{if(action==0)action_series_do();} //�����������ִ���꣬��ִ��
else{              //////////////mode===0
switch(signal){
case'a':{PWMDTY_GET[0]=PWMDTY_GET[0]-change;break;}
case'A':{PWMDTY_GET[0]=PWMDTY_GET[0]+change;break;}
case'b':{PWMDTY_GET[1]=PWMDTY_GET[1]-change;break;}
case'B':{PWMDTY_GET[1]=PWMDTY_GET[1]+change;break;}
case'c':{PWMDTY_GET[2]=PWMDTY_GET[2]-change;break;}
case'C':{PWMDTY_GET[2]=PWMDTY_GET[2]+change;break;}
case'd':{PWMDTY_GET[3]=PWMDTY_GET[3]-change;break;}
case'D':{PWMDTY_GET[3]=PWMDTY_GET[3]+change;break;}
case'e':{PWMDTY_GET[4]=PWMDTY_GET[4]-change;break;}
case'E':{PWMDTY_GET[4]=PWMDTY_GET[4]+change;break;}
case'f':{PWMDTY_GET[5]=PWMDTY_GET[5]-change;break;}
case'F':{PWMDTY_GET[5]=PWMDTY_GET[5]+change;break;}
case'+':{change=change+50;break;}
case'-':{change=change-50;break;}
case'0':{action_base(0);break;} //ֱ��
case'1':{action_base(1);break;} //�ҽ�����
case'2':{action_base(2);break;} //�������	   ����ֱ�Ӵ�2��4
case'3':{action_base(3);break;} //��̧��
case'4':{action_base(4);break;} //�����
case'5':{action_base(5);break;} //��ת��
case'6':{action_base(6);break;} //���� 	 ����ֱ�Ӵ�6��8
case'7':{action_base(7);break;} //�ҽ�����
case'8':{action_base(8);break;} //��Ż���	 	����ֱ�Ӵ�8����
case'9':{action_base(9);break;} //��̧��
case'!':{action_base(10);break;} //�����
case'@':{action_base(11);break;} //��ת�� 
case'#':{action_base(12);break;} //����   ����ֱ�Ӵ�#��%
case'$':{action_base(13);break;} //������
case'%':{action_base(14);break;} //�һ��������Իص�3����̧�ţ����߻ص�0.
case'^':{action_base(15);break;} //�һ��������Իص�3����̧�ţ����߻ص�0.
case'&':{action_base(16);break;} //�һ��������Իص�3����̧�ţ����߻ص�0.
case'*':{action_base(17);break;} //�һ��������Իص�3����̧�ţ����߻ص�0.
case'(':{action_base(18);break;} //�һ��������Իص�3����̧�ţ����߻ص�0.
case')':{action_base(19);break;} //�һ��������Իص�3����̧�ţ����߻ص�0.
case's':{action_series_set(1);break;} //���� ����һ��
case'g':{action_series_set(2);break;} //������
case'S':{action_series_set(3);break;} //���� ������һ��
case'G':{action_series_set(4);break;} //��������
case'r':{action_series_set(5);break;} //���� ������һ��
case'l':{action_series_set(6);break;} //��������
case'L':{action_series_set(7);break;} //���� ������һ��
case'R':{action_series_set(8);break;} //��������

case'k':{action_series_set(9);break;} //���� ������һ��
case'K':{action_series_set(10);break;} //��������
case'm':{mode=1;break;} //��������
} }
sendmessage();				 //��������
time=0;

/*sendstring("head:");
printnumber(head);
sendstring("status:");
printnumber(status);
sendstring("signal:");
printnumber(signal);
  senddata(0x0d);
senddata(0x0a);//�س�����	 */
signal=0;
}
}
}

/********�����趨*******/
void action_set(int goal0,int goal1,int goal2,int goal3,int goal4,int goal5,unsigned int t)
{

action_last=t;
action_do_last=t;
PWMDTY_change[0]=(goal0+(int)PWMDTY_BASE[0]-(int)PWMDTY_GET[0])/(int)action_last;
PWMDTY_change[1]=(goal1+(int)PWMDTY_BASE[1]-(int)PWMDTY_GET[1])/(int)action_last; 
PWMDTY_change[2]=(goal2+(int)PWMDTY_BASE[2]-(int)PWMDTY_GET[2])/(int)action_last;
PWMDTY_change[3]=(goal3+(int)PWMDTY_BASE[3]-(int)PWMDTY_GET[3])/(int)action_last;
PWMDTY_change[4]=(goal4+(int)PWMDTY_BASE[4]-(int)PWMDTY_GET[4])/(int)action_last;
PWMDTY_change[5]=(goal5+(int)PWMDTY_BASE[5]-(int)PWMDTY_GET[5])/(int)action_last;
action=1;
}
/********��������********/
void action_base(char number)
{ switch(number)
{
case 0:{action_set(0,0,0,0,0,0,100);break;} //ֱ��
//case 1:{action_set(0,0,-200,700,0,0,50);break;} //�ҽ�����											   #####
case 1:{action_set(0,0,-375,600,0,0,40);break;} //�������	  			-300/-400						#####
case 2:{action_set(0,0,-300,0,600,600,50);break;} //��̧�ţ�ͬʱ�ҽŷ�ƽ							 #####
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
/*********��������ϵ��ִ��**********/
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
		 case 6 : {acti_on_base(15);break;}
		 case 7 : {action_base(14);break;}
		 case 8 : {action_base(13);break;}
		 case 9 : {actionbase(12);break;}
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
unsigned int ultrasonic()
{
unsigned int add=0,dis=0,t=0;
unsigned int most_time=10000;
trig=0;
trig=1;
delay_3us(5);
time=0;//��ʱ����0������ʱ���ж��Ƿ������ѭ��
while(echo==0&&time<250);
while(echo==1)add++; //6���������ڣ�3us
t=add*3/100;//��λ100us
if(t!=0)dis=t*34/2/10;//����=us*34cm/ms/2
senddata('#');
printnumber(dis);
senddata('#');
return dis;
}

void time0(void) interrupt 1
{	
order0++;
if(order0>7)order0=1;
switch(order0)
	{
	 case 1:{PWMOUT0=1;
	 		 PWMDTY[0]=PWMDTY_GET[0];
	 		 TH0=-PWMDTY[0]/256;
			 TL0=-PWMDTY[0]%256;
			 break;}
	 case 2:{PWMOUT0=0;
	 		 TH0=-(period-PWMDTY[0])/256;
			 TL0=-(period-PWMDTY[0])%256;
			 break;}
	 case 3:{PWMOUT1=1;
			 PWMDTY[1]=PWMDTY_GET[1];
	 		 TH0=-PWMDTY[1]/256;
			 TL0=-PWMDTY[1]%256;
			 break;}
	 case 4:{PWMOUT1=0;
	 		 TH0=-(period-PWMDTY[1])/256;
			 TL0=-(period-PWMDTY[1])%256;
			 break;}
	 case 5:{PWMOUT2=1;
			 PWMDTY[2]=PWMDTY_GET[2];
	 		 TH0=-PWMDTY[2]/256;
			 TL0=-PWMDTY[2]%256;
			 break;}
	 case 6:{PWMOUT2=0;
	 		 TH0=-(period-PWMDTY[2])/256;
			 TL0=-(period-PWMDTY[2])%256;
			 break;}
   	 case 7:{
	 		 TH0=-period/256;
			 TL0=-period%256;
			 time=time+1;
			 if(action)
			 {if(action_do_last!=0)
			  {PWMDTY_GET[0]=(int)PWMDTY_GET[0]+PWMDTY_change[0];
			  PWMDTY_GET[1]=(int)PWMDTY_GET[1]+PWMDTY_change[1];
			  PWMDTY_GET[2]=(int)PWMDTY_GET[2]+PWMDTY_change[2];
			  PWMDTY_GET[3]=(int)PWMDTY_GET[3]+PWMDTY_change[3];
			  PWMDTY_GET[4]=(int)PWMDTY_GET[4]+PWMDTY_change[4];
			  PWMDTY_GET[5]=(int)PWMDTY_GET[5]+PWMDTY_change[5];
			  action_do_last--;
			  }
			  action_last--;
			  if(action_last==0)
			  {action=0;PWMDTY_change[0]=0;PWMDTY_change[1]=0;PWMDTY_change[2]=0;PWMDTY_change[3]=0;PWMDTY_change[4]=0;PWMDTY_change[5]=0;}
			 }
			 break;}
	 break;
	}	 
}
void time1(void) interrupt 3
{
order1++;
if(order1>7)order1=1;
switch(order1)
	{
	 case 1:{PWMOUT3=1;
	         PWMDTY[3]=PWMDTY_GET[3];
	 		 TH1=-PWMDTY[3]/256;
			 TL1=-PWMDTY[3]%256;
			 break;}
	 case 2:{PWMOUT3=0;
	 		 TH1=-(period-PWMDTY[3])/256;
			 TL1=-(period-PWMDTY[3])%256;
			 break;}
	 case 3:{PWMOUT4=1;
	         PWMDTY[4]=PWMDTY_GET[4];
	 		 TH1=-PWMDTY[4]/256;
			 TL1=-PWMDTY[4]%256;
			 break;}
	 case 4:{PWMOUT4=0;
	 		 TH1=-(period-PWMDTY[4])/256;
			 TL1=-(period-PWMDTY[4])%256;
			 break;}
	 case 5:{PWMOUT5=1;
	 		 PWMDTY[5]=PWMDTY_GET[5];
			 TH1=-PWMDTY[5]/256;
			 TL1=-PWMDTY[5]%256;
			 break;}
	 case 6:{PWMOUT5=0;
	 		 TH1=-(period-PWMDTY[5])/256;
			 TL1=-(period-PWMDTY[5])%256;
			 break;}
   	 case 7:{
	 		 TH1=-period/256;
			 TL1=-period%256;
			 break;}
	 break;
	} 
 }					