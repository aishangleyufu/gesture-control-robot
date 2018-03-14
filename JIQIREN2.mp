NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                        func_lit   008C   0032 =     50. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       008C  __func_lit_start
       00BE  __func_lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   00BE   0010 =     16. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       00BE  __idata_start
       00CE  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   00CE   0FEA =   4074. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0067  __text_start
       0067  __start
       0089  _exit
       008A  _uart1_init
       009F  _putchar1
       00A6  _getchar1
       00AD  _puts1
       00C1  _uart1_rx_isr
       00D8  _delay_1ms
       00FD  _delay_nms
       012B  _action_set
       0181  _action_base
       03D6  _action_series_do
       069C  _action_series_set
       074C  _pwm_init
       078A  _main
       07FD  push_arg4
       07FF  push_arg2
       0802  mod16s
       0806  div16s
       0820  mod16u
       0822  div16u
       0823  xdiv16u
       083C  pop_xgsetF0FC
       0847  push_xgsetF0FC
       0849  push_xgset30FC
       084B  push_xgset00FC
       084D  push_xgset003C
       0852  push_xgsetF000
       0857  pop_xgsetF000
       085C  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0100   0010 =     16. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0100  __data_start
       0100  _action_series_step
       0102  _action_series_number
       0104  _action_series_flag
       0106  _temp
       0108  _temp_last
       010A  _sendflag1
       010B  _sendflag
       010C  _usart0_data_counter
       010D  _usart0_data_receive
       0110  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   0110   0002 =      2. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0110  _data1
       0110  __bss_start
       0111  _data_temp
       0112  __bss_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   007C =    124. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

C:\Users\c\Desktop\三下\现代控制理论\ICCAVR\lib\crtatmega.o	[ crtatmega.s ]
main.o	[ main.c ]
<library>	[ asave.s, div16s.s, div16u.s, gpop5.s, gpush.s, gpushy.s ]

User Global Definitions

ram_end = 0x10ff
hwstk_size = 0x1e

User Base Address Definitions

func_lit = 0x8c
data = 0x100
eeprom:0.4096

