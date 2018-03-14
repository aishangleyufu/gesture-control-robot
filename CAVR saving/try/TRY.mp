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
                            text   0114   06E4 =   1764. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       008A  __start
       008A  __text_start
       00AC  _exit
       00AD  _delay
       00EB  _PWM_init
       0121  _action_set
       0153  _action_base
       0352  _uart1_init
       0363  _putchar1
       036A  _getchar1
       0371  _puts1
       0385  _io_init
       0395  _key_init
       039E  _main
       03EA  push_xgsetF03C
       03F3  pop_xgsetF03C
       03FC  __text_end

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

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   0206   0006 =      6. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0206  __bss_start
       0206  _k
       0208  _j
       020A  _i
       020C  __bss_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   0004 =      4. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

F:\ICCAVR\lib\crtatmega.o	[ crtatmega.s ]
main3.o	[ main3.c ]
<library>	[ gpushb.s ]

User Global Definitions

ram_end = 0x21ff
hwstk_size = 0x1e

User Base Address Definitions

func_lit = 0xe4
data = 0x200
eeprom:0.4096

