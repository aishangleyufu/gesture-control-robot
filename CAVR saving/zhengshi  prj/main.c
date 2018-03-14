/*======
使用定时器1，OCR1A,OCR1B,OCR1C三个管脚同时输出PWM波形
在快速PWM的模式下，top=0x03ff=1023
OCRnX在top时刻更新
频率=8000000/8/1023=977.5HZ
=======================================================*/
#include<iom128v.h>
#include<string.h> 
#include <macros.h> 
#define fosc 16000000  //晶振16MHZ
#define baud 38400  //波特率
int flag=0;
int tempflag1=0;
int tempflag2=0;


void PWM_init()
{
   DDRB|=0XE0;
   DDRE|=0X38;
TCCR1B|=(1<<WGM12)|(1<<WGM13)|(1<<CS11);
TCCR1A|=(1<<COM1C1)|(1<<COM1A1)|(1<<COM1B1)|(1<<WGM11);   //选通ABC                 
	ICR1=40000;
TCCR3B|=(1<<WGM12)|(1<<WGM13)|(1<<CS11)|(1<<CS01);
TCCR3A|=(1<<COM3A1)|(1<<COM3B1)|(1<<COM3C1)|(1<<WGM11);  //选通ABC
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
case 0:{action_set(0,0,0,0,0,0,100);break;} //直立
//case 1:{action_set(0,0,-200,700,0,0,50);break;} //右脚左倾											   #####
case 1:{action_set(0,0,-750,1200,0,0,40);break;} //左脚左倾	  			-300/-400						#####
case 2:{action_set(0,0,-600,0,1200,1200,100);break;} //右抬脚，同时右脚放平							 #####
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



//=========================================================

//================UART=================
/***************************************************************************/
/*串口1测试程序                                          */

/***********************************宏定义**********************************/

/****************************************************************************
函数功能:uart1初始化程序
入口参数:
出口参数:
****************************************************************************/
void uart1_init(void) //USART1初始化
{
 //DDRD|=(1<<2)|(1<<3);   //  IO
 UCSR1B = 0x00;   //关闭USART1
 UCSR1A = 0x00;   //不适使用倍速发送
 UCSR1C = (1<<UCSZ11)|(1<<UCSZ10);//数据位为八位
 UBRR1L=(fosc/16/(baud+1))%256;//异步正常模式下，UBRR的计算公式
 UBRR1H=(fosc/16/(baud+1))/256;
 UCSR1B =(1<<RXEN1)|(1<<TXEN1); //接收使能，传送使能
}
/****************************************************************************
函数功能:uart1发送单字节数据
入口参数:c
出口参数:
****************************************************************************/
void putchar1(unsigned char c)//串口1发送字符
 {  
     while (!(UCSR1A&(1<<UDRE1)));//表明发送器一准备就绪
  UDR1=c;    
 } 
 
/****************************************************************************
函数功能:uart1接收单字节数据
入口参数:
出口参数:
****************************************************************************/
unsigned char getchar1(void) //串口1接回收数据
   {
  while(!(UCSR1A& (1<<RXC1)));
     return UDR1;   //将接收到的字符返回
 } 
 
/****************************************************************************
函数功能:uart1发送字符串数据
入口参数:*s
出口参数:
****************************************************************************/    
void puts1(char *s)
 {
 while (*s)
  {
  putchar1(*s);
  s++;
  } 
        putchar1(0x0a);//回车换行
     putchar1(0x0d);
 } 
 
/****************************************************************************
函数功能:
入口参数:
出口参数:
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
   for(i=0;i<1000;i++){
   			{for(j=0;j<1000;j++)
   			{for(k=0;k<1;k++)   //k<10,约三秒  
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
   			{for(k=0;k<8;k++)   //k<10,约三秒  
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


