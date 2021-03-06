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
unsigned int PWMDTY[6]={3340,3260,3240,3440,3150,3200};//范围应该在（0,5000），不能等于0或者5000.仿真结果观察会影响时序，原因不知。
unsigned int PWMDTY_GET[6]={3340,3260,3240,3440,3150,3200}; //用于储存计算出来的PWMDTY值，在周期开始时导入PWMDTY,避免在一个周期内PWMDTY导致周期混乱的现象
unsigned int PWMDTY_BASE[6]={3340,3260,3190,3440,3150,3200};
unsigned int time=0; //20ms加1
int count=0;
char action=0;//1表示在动作，0表示不在动
char action_series_flag=0;//1表示在动作系列中，0表示不在动作系列中
char action_series_number=0;
char action_series_step=0;
unsigned int action_last=0;//动作持续周期
unsigned int action_do_last=0;
unsigned int distance=0;
int PWMDTY_change[6]={0};//每周期动作改变，小心，可正可负
char mode=1;
char status=0;
char head=0;
#define ZERO 0;
//////
extern unsigned int time;
extern bit busy;
extern char action;//1表示在动作，0表示不在动
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
P0M1=0X00;//P0口配置
TIMEinit();
UARTinit();//由于兼容性问题，这个初始化应该放在TIMEinit后面
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
if(action==0&&head!=0){//head=0,则停止
status=action_mix[status][head];
action_base(status);
}
}
else if(action_series_flag)			//如果基本动作系列还没执行完，先执行
{if(action==0)action_series_do();} //如果基本动作执行完，才执行
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
case'0':{action_base(0);break;} //直立
case'1':{action_base(1);break;} //右脚左倾
case'2':{action_base(2);break;} //左脚左倾	   可以直接从2到4
case'3':{action_base(3);break;} //右抬脚
case'4':{action_base(4);break;} //左弯脚
case'5':{action_base(5);break;} //左转正
case'6':{action_base(6);break;} //右倾 	 可以直接从6到8
case'7':{action_base(7);break;} //右脚立正
case'8':{action_base(8);break;} //左脚回正	 	可以直接从8到！
case'9':{action_base(9);break;} //左抬脚
case'!':{action_base(10);break;} //右弯脚
case'@':{action_base(11);break;} //右转正 
case'#':{action_base(12);break;} //左倾   可以直接从#到%
case'$':{action_base(13);break;} //左立正
case'%':{action_base(14);break;} //右回正，可以回到3，右抬脚，或者回到0.
case'^':{action_base(15);break;} //右回正，可以回到3，右抬脚，或者回到0.
case'&':{action_base(16);break;} //右回正，可以回到3，右抬脚，或者回到0.
case'*':{action_base(17);break;} //右回正，可以回到3，右抬脚，或者回到0.
case'(':{action_base(18);break;} //右回正，可以回到3，右抬脚，或者回到0.
case')':{action_base(19);break;} //右回正，可以回到3，右抬脚，或者回到0.
case's':{action_series_set(1);break;} //启动 并走一步
case'g':{action_series_set(2);break;} //继续走
case'S':{action_series_set(3);break;} //启动 并后退一步
case'G':{action_series_set(4);break;} //继续后退
case'r':{action_series_set(5);break;} //启动 并后退一步
case'l':{action_series_set(6);break;} //继续后退
case'L':{action_series_set(7);break;} //启动 并后退一步
case'R':{action_series_set(8);break;} //继续后退

case'k':{action_series_set(9);break;} //启动 并后退一步
case'K':{action_series_set(10);break;} //继续后退
case'm':{mode=1;break;} //继续后退
} }
sendmessage();				 //传送数据
time=0;

/*sendstring("head:");
printnumber(head);
sendstring("status:");
printnumber(status);
sendstring("signal:");
printnumber(signal);
  senddata(0x0d);
senddata(0x0a);//回车换行	 */
signal=0;
}
}
}

/********动作设定*******/
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
/********基本步法********/
void action_base(char number)
{ switch(number)
{
case 0:{action_set(0,0,0,0,0,0,100);break;} //直立
//case 1:{action_set(0,0,-200,700,0,0,50);break;} //右脚左倾											   #####
case 1:{action_set(0,0,-375,600,0,0,40);break;} //左脚左倾	  			-300/-400						#####
case 2:{action_set(0,0,-300,0,600,600,50);break;} //右抬脚，同时右脚放平							 #####
//case 4:{action_set(700,700,-350,-400,700,700,50);break;} //左弯脚 3,4可以一起完成
//case 5:{action_set(700,700,0,0,700,700,50);break;} //转正	
case 3:{action_set(300,600,0,0,600,900,75);break;} //前倾，1号舵机-500，6号舵机+500，把重心转移到前脚上#####
case 4:{action_set(300,600,450,350,600,900,50);break;} //左脚右倾	 	前倾								  #####
//case 8:{action_set(400,700,-750,300,700,1000,50);break;} //右脚右倾，度数还得减小	 
case 5:{action_set(300,600,0,300,0,300,50);break;} //右脚立正  ，前倾
case 6:{action_set(0,0,0,300,0,0,25);break;} //左脚回正	 	同时，左脚放平，取消前倾			   #####
case 7:{action_set(-600,-600,0,300,0,0,25);break;} //左抬脚										   #####
//case 12:{action_set(-700,-700,400,300,-700,-700,50);break;} //右弯脚	11,12可以一起完成 ，前脚未着地
//case 13:{action_set(-700,-700,0,0,-700,-700,50);break;} //右转正 
case 8:{action_set(-600,-400,0,0,-400,-600,75);break;} //前倾，1号舵机-500，6号舵机+500，把重心转移到前脚上，左脚稍弯##### 
case 9:{action_set(-600,-400,-350,-450,-400,-600,50);break;} //右脚左倾   	前倾								#####
//case 16:{action_set(-1000,-700,-250,-350,-700,-400,50);break;} //左脚左倾   
case 10:{action_set(0,0,-300,-450,-600,-600,50);break;} //左立正，前倾
//case 10:{action_set(0,0,-300,0,0,0,75);break;} //右回正，取消前倾可以回到3，右抬脚，或者回到0		  #####

case 11:{action_set(0,0,-300,0,-600,-800,50);break;} //右后抬脚，同时右脚放平							 #####
case 12:{action_set(-750,-400,0,0,-400,-750,75);break;} //后倾，1号舵机+500，6号舵机-500，重心转移到后脚，右脚稍弯#####
case 13:{action_set(-750,-400,400,300,-400,-750,50);break;} //脚右倾	 	
case 14:{action_set(-750,-600,0,250,0,0,50);break;} //右脚回正	 	同时，左脚放平，取消前倾			   #####								  #####
case 15:{action_set(0,0,0,250,0,0,40);break;} //右脚回正	 	同时，左脚放平，取消前倾			   #####
case 16:{action_set(600,600,0,250,0,0,40);break;} //左后抬脚										   #####
case 17:{action_set(600,600,0,0,600,600,50);break;} //后倾，1号舵机+500，6号舵机-500，把重心转移到前脚上##### 
case 18:{action_set(600,600,-350,-450,600,600,50);break;} //脚左倾   									#####
case 19:{action_set(0,0,-300,-450,600,600,50);break;} //脚左倾   									#####
case 20:{action_set(0,0,-300,0,0,0,50);break;} //左回正，取消前倾可以回到3，右抬脚，或者回到0		  #####

}
}
/*********基本动作系列执行**********/
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
if(--action_series_step==0)action_series_flag=0,action_series_number=0;//如果动作完成，则动作系列标志位置0

}

/********动作系列配置************/
void action_series_set(char number)
{
switch(number)
{case 1 : {action_series_number=1;action_series_step=11;break;}		 //启动并走一步
case 2 : {action_series_number=2;action_series_step=10;break;}		 //继续走
case 3 : {action_series_number=3;action_series_step=11;break;}		 //启动并后退一步
case 4 : {action_series_number=4;action_series_step=10;break;}		 //继续后退
case 5 : {action_series_number=5;action_series_step=6;break;}		 //继续后退
case 6 : {action_series_number=6;action_series_step=6;break;}		 //继续后退
case 7 : {action_series_number=7;action_series_step=6;break;}		 //继续后退
case 8 : {action_series_number=8;action_series_step=6;break;}		 //继续后退
case 9 : {action_series_number=9;action_series_step=6;break;}		 //继续后退
case 10 : {action_series_number=10;action_series_step=4;break;}		 //继续后退
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
time=0;//把时间清0，利用时间判断是否进入死循环
while(echo==0&&time<250);
while(echo==1)add++; //6个机器周期，3us
t=add*3/100;//单位100us
if(t!=0)dis=t*34/2/10;//距离=us*34cm/ms/2
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