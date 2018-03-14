NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                        func_lit   00E4   002A =     42. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       00E4  __func_lit_start
       010E  __func_lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   010E   0006 =      6. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       010E  __idata_start
       0114  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0114   069E =   1694. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       008A  __start
       008A  __text_start
       00AC  _exit
       00AD  _PWM_init
       00EB  _action_set
       011D  _action_base
       031C  _uart1_init
       032D  _putchar1
       0334  _getchar1
       033B  _puts1
       034F  _io_init
       035F  _key_init
       0368  _main
       03C7  push_xgsetF03C
       03D0  pop_xgsetF03C
       03D9  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0200   0006 =      6. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0200  __data_start
       0200  _flag
       0202  _tempflag1
       0204  _tempflag2
       0206  __data_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   0004 =      4. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

F:\ICCAVR\lib\crtatmega.o	[ crtatmega.s ]
main.o	[ main2.c ]
<library>	[ gpushb.s ]

User Global Definitions

ram_end = 0x21ff
hwstk_size = 0x1e

User Base Address Definitions

func_lit = 0xe4
data = 0x200
eeprom:0.4096

