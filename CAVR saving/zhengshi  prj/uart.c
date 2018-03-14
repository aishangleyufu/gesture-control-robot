#include<iom128v.h>
#include<inavr.h>
#include<string.h>
#define INT8U  unsigned char 
#define INT16U unsigned int
#define UDRIE0               5
/* UART Buffer Defines */
#define UART0_RX_BUFFER_SIZE 128
#define UART0_TX_BUFFER_SIZE 128
/* Static Variables */
static unsigned char UART0_RxBuf[UART0_RX_BUFFER_SIZE];
static volatile unsigned char UART0_RxHead;
static volatile unsigned char UART0_RxTail;
static unsigned char UART0_TxBuf[UART0_TX_BUFFER_SIZE];
static volatile unsigned char UART0_TxHead;
static volatile unsigned char UART0_TxTail;
static unsigned char UART0_Flag=1;
void USART_INIT( void )
{
  UBRR0H = 0x00;
  UBRR0L = 0x0B;//9600 at 1.8432M
  UCSR0A = 0x20;
  UCSR0B = 0xD8;//开接收结束中断,发送结束中断接收使能,发送使能
  UCSR0C = 0x06;//异步模式，1位停止位，8位数据位
  UDR0 = 0x00;//清空数据寄存器
  UART0_RxTail = 0;
  UART0_RxHead = 0;
  UART0_TxTail = 0;
  UART0_TxHead = 0;
  __disable_interrupt();//关全局中断
}                    
void Tran_Byte( INT8U sdata )
{
  if(UART0_Flag == 0)
  {
    UDR0 = sdata;
    UART0_Flag = 1;
  }
  else
  {
    UART0_TxBuf[UART0_TxHead] = sdata;
    UART0_TxHead++;
    if(UART0_TxHead >= UART0_TX_BUFFER_SIZE)
      UART0_TxHead = 0;
  }
  __enable_interrupt();
}
void Send_String( INT8U *string )
{
  INT8U temp;  
  while(1)
  {
    temp = *string;
    Tran_Byte(temp);
    string++;
    if(*string == 0x00)
      break;
  }
}
INT8U HaveDataRxd( void )
{ 
  if(UART0_RxHead != UART0_RxTail) 
    return 1;
  else 
    return 0;
}
INT8U GetDataFromRxdBuf( void )
{
  INT8U temp;  
  temp = UART0_RxBuf[UART0_RxTail];  
  UART0_RxTail ++ ;
  if( UART0_RxTail >= UART0_RX_BUFFER_SIZE )
  {
    UART0_RxTail = 0 ;
  }
  return temp;  
}
//清空接收缓冲区。
void UART_ResetRxBuffer( void )
{
  UART0_RxHead = 0;
  UART0_RxTail = 0;
}
int main( void )
{
  DDRA = 0xFF;PORTA = 0xFF;
  DDRE = 0xFE;
  INT8U tab;
  USART_INIT();
  __enable_interrupt();//开全局中断
  while(1)
  {
    __delay_cycles(10000);    
    while(!HaveDataRxd());
    tab = GetDataFromRxdBuf();
    __delay_cycles(10000);
    Tran_Byte(tab);
  }
}
#pragma vector=USART0_RXC_vect
__interrupt void USART0_RX( void )
{
  INT8U data;
  INT8U status;
  data = UDR0; /* read the received data */
  status = UCSR0A;
  if((status & 0x18) == 0x00)
  {    
    UART0_RxBuf[UART0_RxHead] = data;
    UART0_RxHead ++;
    if(UART0_RxHead == UART0_RX_BUFFER_SIZE)
      UART0_RxHead = 0;
  }
}
#pragma vector=USART0_TXC_vect
__interrupt void USRAT0_TX( void )
{
  INT8U temp;  
  /* check if all data is transmitted */
  if(UART0_TxHead != UART0_TxTail)
  {
    /* calculate buffer index */
    temp = UART0_TxBuf[UART0_TxTail];
    UDR0 = temp;
    UART0_TxTail ++;
    if(UART0_TxTail >= UART0_TX_BUFFER_SIZE)
      UART0_TxTail = 0;
  }
  else
  {
    UART0_Flag =  0;
  } 
}

