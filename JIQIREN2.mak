CC = iccavr
LIB = ilibw
CFLAGS =  -e -D__ICC_VERSION=722 -DATMega128  -l -g -MLongJump -MHasMul -MEnhanced -Wf-use_elpm 
ASFLAGS = $(CFLAGS) 
LFLAGS =  -g -e:0x20000 -ucrtatmega.o -bfunc_lit:0x8c.0x20000 -dram_end:0x10ff -bdata:0x100.0x10ff -dhwstk_size:30 -beeprom:0.4096 -fihx_coff -S2
FILES = main.o 

JIQIREN2:	$(FILES)
	$(CC) -o JIQIREN2 $(LFLAGS) @JIQIREN2.lk   -lcatm128
main.o: C:\Users\c\Desktop\三下\现代控制理论\ICCAVR\include\iom128v.h C:\Users\c\Desktop\三下\现代控制理论\ICCAVR\include\macros.h C:\Users\c\Desktop\三下\现代控制理论\ICCAVR\include\AVRdef.h
main.o:	main.c
	$(CC) -c $(CFLAGS) main.c
