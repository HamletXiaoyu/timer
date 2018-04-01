all: timer1 timer2 timer3

timer1: timer1.o
	gcc -o timer1 timer1.o

timer1.o: timer1.c
	gcc -o timer1.o -c timer1.c

timer2: timer2.o
	gcc -o timer2 timer2.o

timer2.o: timer2.c
	gcc -o timer2.o -c timer2.c

timer3: timer3.o
	gcc -o timer3 timer3.o

timer3.o: timer3.c
	gcc -o timer3.o -c timer3.c

install: all

clean:
	-rm *.o
	-rm *~
