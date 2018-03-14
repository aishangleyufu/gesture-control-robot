#line 35 "F:\ICCAVR\include\AVRdef.h"
unsigned char FlashReadByte(unsigned char ramp, unsigned addr);
unsigned FlashReadWord(unsigned char ramp, unsigned addr);
unsigned long FlashReadLWord(unsigned char ramp, unsigned addr);
void FlashReadBytes(unsigned char ramp, unsigned addr, unsigned char *buf, int n);



unsigned char EDataReadByte(unsigned char ramp, unsigned addr);
unsigned EDataReadWord(unsigned char ramp, unsigned addr);
unsigned long EDataReadLWord(unsigned char ramp, unsigned addr);
void EDataReadBytes(unsigned char ramp, unsigned addr, unsigned char *buf, int n);

void EDataWriteByte(unsigned char ramp, unsigned addr);
void EDataWriteWord(unsigned char ramp, unsigned addr);
void EDataWriteLWord(unsigned char ramp, unsigned addr);
void EDataWriteBytes(unsigned char ramp, unsigned addr, unsigned char *buf, int n);






















void _StackCheck(void);
void _StackOverflowed(char);

#line 5 "D:\Documents\Atmel\CAVRSA~1\init.h"
void TIMEinit(void);

void UARTinit(void);
#line 4 "D:\Documents\Atmel\CAVRSA~1\test1.c"
sbit PWMOUT0=P0^0;
sbit PWMOUT1=P0^1;
sbit PWMOUT2=P0^2;
sbit PWMOUT3=P0^3;
sbit PWMOUT4=P0^4;
sbit PWMOUT5=P0^5;
sbit trig=P1^0;
sbit echo=P1^1;
char order0=0,order1=0,signal=0;
unsigned int PWMDTY[6]={3340,3260,3240,3440,3150,3200}; 
unsigned int PWMDTY_GET[6]={3340,3260,3240,3440,3150,3200}; 
unsigned int PWMDTY_BASE[6]={3340,3260,3190,3440,3150,3200};
unsigned int time=0; 
int count=0;
char action=0; 
char action_series_flag=0; 
char action_series_number=0;
char action_series_step=0;
unsigned int action_last=0; 
unsigned int action_do_last=0;
unsigned int distance=0;
int PWMDTY_change[6]={0}; 
char mode=1;
char status=0;
char head=0;


extern unsigned int time;
extern bit busy;
extern char action; 
unsigned int period=10000;

code char action_mix[21][7]=
{{0,1,1,3,8,12,17}, 
{0,2,11,2,2,11,11}, 
{0,3,20,3,3,20,20}, 
{0,4,19,4,4,19,19}, 
{0,5,18,5,5,18,18}, 
{0,6,17,6,6,17,17}, 
{0,7,16,0,0,0,0}, 
{0,8,15,8,8,15,15}, 
{0,9,14,9,9,14,14}, 
{0,10,13,10,10,13,13}, 
{0,20,12,20,20,12,12}, 
{0,20,12,20,20,12,12}, 
{0,10,13,20,20,13,13}, 
{0,9,14,9,9,14,14}, 
{0,8,15,8,8,15,15}, 
{0,7,16,0,0,0,0}, 
{0,6,17,6,6,17,17}, 
{0,5,18,5,5,18,18}, 
{0,4,19,4,4,19,19}, 
{0,3,20,3,3,20,20}, 
{0,2,11,0,0,0,0} 
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
P0M1=0X00; 
TIMEinit();
UARTinit(); 

trig=0; 

if(time<=100);
while(1)
{ 
if(time>=26)
{ 
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
if(action==0&&head!=0){ 
status=action_mix[status][head];
action_base(status);
}
}
else if(action_series_flag) 
{if(action==0)action_series_do();} 
else{ 
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
case'0':{action_base(0);break;} 
case'1':{action_base(1);break;} 
case'2':{action_base(2);break;} 
case'3':{action_base(3);break;} 
case'4':{action_base(4);break;} 
case'5':{action_base(5);break;} 
case'6':{action_base(6);break;} 
case'7':{action_base(7);break;} 
case'8':{action_base(8);break;} 
case'9':{action_base(9);break;} 
case'!':{action_base(10);break;} 
case'@':{action_base(11);break;} 
case'#':{action_base(12);break;} 
case'$':{action_base(13);break;} 
case'%':{action_base(14);break;} 
case'^':{action_base(15);break;} 
case'&':{action_base(16);break;} 
case'*':{action_base(17);break;} 
case'(':{action_base(18);break;} 
case')':{action_base(19);break;} 
case's':{action_series_set(1);break;} 
case'g':{action_series_set(2);break;} 
case'S':{action_series_set(3);break;} 
case'G':{action_series_set(4);break;} 
case'r':{action_series_set(5);break;} 
case'l':{action_series_set(6);break;} 
case'L':{action_series_set(7);break;} 
case'R':{action_series_set(8);break;} 

case'k':{action_series_set(9);break;} 
case'K':{action_series_set(10);break;} 
case'm':{mode=1;break;} 
} }
sendmessage(); 
time=0;









signal=0;
}
}
}


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

void action_base(char number)
{ switch(number)
{
case 0:{action_set(0,0,0,0,0,0,100);break;} 

case 1:{action_set(0,0,-375,600,0,0,40);break;} 
case 2:{action_set(0,0,-300,0,600,600,50);break;} 


case 3:{action_set(300,600,0,0,600,900,75);break;} 
case 4:{action_set(300,600,450,350,600,900,50);break;} 

case 5:{action_set(300,600,0,300,0,300,50);break;} 
case 6:{action_set(0,0,0,300,0,0,25);break;} 
case 7:{action_set(-600,-600,0,300,0,0,25);break;} 


case 8:{action_set(-600,-400,0,0,-400,-600,75);break;} 
case 9:{action_set(-600,-400,-350,-450,-400,-600,50);break;} 

case 10:{action_set(0,0,-300,-450,-600,-600,50);break;} 


case 11:{action_set(0,0,-300,0,-600,-800,50);break;} 
case 12:{action_set(-750,-400,0,0,-400,-750,75);break;} 
case 13:{action_set(-750,-400,400,300,-400,-750,50);break;} 
case 14:{action_set(-750,-600,0,250,0,0,50);break;} 
case 15:{action_set(0,0,0,250,0,0,40);break;} 
case 16:{action_set(600,600,0,250,0,0,40);break;} 
case 17:{action_set(600,600,0,0,600,600,50);break;} 
case 18:{action_set(600,600,-350,-450,600,600,50);break;} 
case 19:{action_set(0,0,-300,-450,600,600,50);break;} 
case 20:{action_set(0,0,-300,0,0,0,50);break;} 

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
if(--action_series_step==0)action_series_flag=0,action_series_number=0; 

}


void action_series_set(char number)
{
switch(number)
{case 1 : {action_series_number=1;action_series_step=11;break;} 
case 2 : {action_series_number=2;action_series_step=10;break;} 
case 3 : {action_series_number=3;action_series_step=11;break;} 
case 4 : {action_series_number=4;action_series_step=10;break;} 
case 5 : {action_series_number=5;action_series_step=6;break;} 
case 6 : {action_series_number=6;action_series_step=6;break;} 
case 7 : {action_series_number=7;action_series_step=6;break;} 
case 8 : {action_series_number=8;action_series_step=6;break;} 
case 9 : {action_series_number=9;action_series_step=6;break;} 
case 10 : {action_series_number=10;action_series_step=4;break;} 
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
time=0; 
while(echo==0&&time<250);
while(echo==1)add++; 
t=add*3/100; 
if(t!=0)dis=t*34/2/10; 
senddata('#');
printnumber(dis);
senddata('#');
return dis;
}

void UART(void) interrupt 4
{
if(TI)TI=0,busy=0;
if(RI)RI=0,signal=SBUF;
T2H=255;
T2L=255-52;
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
