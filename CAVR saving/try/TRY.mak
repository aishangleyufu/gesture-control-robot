CC = iccavr
LIB = ilibw
CFLAGS =  -e -D__ICC_VERSION=722 -D_EE_EXTIO -DATMega1280  -l -g -MLongJump -MHasMul -MEnhanced -Wf-use_elpm 
ASFLAGS = $(CFLAGS) 
LFLAGS =  -g -e:0x20000 -ucrtatmega.o -bfunc_lit:0xe4.0x20000 -dram_end:0x21ff -bdata:0x200.0x21ff -dhwstk_size:30 -beeprom:0.4096 -fihx_coff -S2
FILES = main3.o 

TRY:	$(FILES)
	$(CC) -o TRY $(LFLAGS) @TRY.lk   -lcatm128
main3.o: F:\ICCAVR\include\iom128v.h F:\ICCAVR\include\string.h F:\ICCAVR\include\_const.h F:\ICCAVR\include\macros.h F:\ICCAVR\include\AVRdef.h
main3.o:	..\..\CAVRSA~1\try\main3.c
	$(CC) -c $(CFLAGS) ..\..\CAVRSA~1\try\main3.c
