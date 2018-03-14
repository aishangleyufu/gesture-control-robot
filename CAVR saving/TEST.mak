CC = iccavr
LIB = ilibw
CFLAGS =  -e -D__ICC_VERSION=722 -D_EE_EXTIO -DATMega1280  -l -g -MLongJump -MHasMul -MEnhanced -Wf-use_elpm 
ASFLAGS = $(CFLAGS) 
LFLAGS =  -g -e:0x20000 -ucrtatmega.o -bfunc_lit:0xe4.0x20000 -dram_end:0x21ff -bdata:0x200.0x21ff -dhwstk_size:30 -beeprom:0.4096 -fihx_coff -S2
FILES = test1.o init.o 

TEST:	$(FILES)
	$(CC) -o TEST $(LFLAGS) @TEST.lk   -lcatm128
test1.o: F:\ICCAVR\include\iom128v.h F:\ICCAVR\include\macros.h F:\ICCAVR\include\AVRdef.h .\..\CAVRSA~1\include.h .\..\CAVRSA~1\init.h
test1.o:	..\CAVRSA~1\test1.c
	$(CC) -c $(CFLAGS) ..\CAVRSA~1\test1.c
init.o: .\..\CAVRSA~1\init.h .\..\CAVRSA~1\include.h F:\ICCAVR\include\iom128v.h
init.o:	..\CAVRSA~1\init.c
	$(CC) -c $(CFLAGS) ..\CAVRSA~1\init.c
