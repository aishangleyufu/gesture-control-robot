NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   00E4   0006 =      6. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       00E4  __idata_start
       00EA  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   00EA   0236 =    566. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0075  __text_start
       0075  __start
       0097  _exit
       0098  _delay_1ms
       00BD  _delay_nms
       00EB  _main
       0181  push_arg4
       0183  push_arg2
       0186  push_xgsetF000
       018B  pop_xgsetF000
       0190  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0200   0006 =      6. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0200  _action_series_step
       0200  __data_start
       0202  _action_series_number
       0204  _action_series_flag
       0206  __data_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   0004 =      4. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

F:\ICCAVR\lib\crtatmega.o	[ crtatmega.s ]
test.o	[ test.c ]
<library>	[ asave.s, gpushy.s ]

User Global Definitions

ram_end = 0x21ff
hwstk_size = 0x1e

User Base Address Definitions

func_lit = 0xe4
data = 0x200
eeprom:0.4096

