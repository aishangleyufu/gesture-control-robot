NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                        func_lit   0060   002A =     42. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0060  __func_lit_start
       008A  __func_lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   008A   0006 =      6. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       008A  __idata_start
       0090  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0090   0D4E =   3406. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0048  __start
       0048  __text_start
       006A  _exit
       006B  _delay_1ms
       0090  _delay_nms
       00BE  _action_set
       00F0  _action_base
       02EF  _action_series_do
       05B5  _action_series_set
       066B  _main
       06CE  push_arg4
       06D0  push_arg2
       06D3  push_xgsetF000
       06D8  pop_xgsetF000
       06DD  push_xgsetF03C
       06E6  pop_xgsetF03C
       06EF  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0060   0006 =      6. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0060  _action_series_step
       0060  __data_start
       0062  _action_series_number
       0064  _action_series_flag
       0066  __data_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   0004 =      4. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

F:\ICCAVR\lib\crtatmega.o	[ crtatmega.s ]
main.o	[ main.c ]
<library>	[ asave.s, gpushy.s, gpushb.s ]

User Global Definitions

ram_end = 0xfff
hwstk_size = 0x64

User Base Address Definitions

func_lit = 0x60
data = 0x60
eeprom:0.4096

