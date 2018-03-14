CC = iccavr
LIB = ilibw
CFLAGS =  -e -D__ICC_VERSION=722 -DATMega128  -l -g -MLongJump -MHasMul -MEnhanced -Wf-use_elpm 
ASFLAGS = $(CFLAGS) 
LFLAGS =  -g -e:0x20000 -ucrtatmega.o -bfunc_lit:0x60.0x20000 -dram_end:0xfff -bdata:0x60.0xfff -dhwstk_size:100 -beeprom:0.4096 -fihx_coff -S2
FILES = main.o 

PRJ2:	$(FILES)
	$(CC) -o PRJ2 $(LFLAGS) @PRJ2.lk   -lcatm128
main.o: F:\ICCAVR\include\iom128v.h F:\ICCAVR\include\macros.h F:\ICCAVR\include\AVRdef.h
main.o:	..\..\CAVRSA~1\prj2\main.c
	$(CC) -c $(CFLAGS) ..\..\CAVRSA~1\prj2\main.c
