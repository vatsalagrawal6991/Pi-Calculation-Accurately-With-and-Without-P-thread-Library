build:all.out

arg1 =
arg2 =
arg3 =
arg4 =

all.out: obj/main.o obj/euler.o obj/peuler.o obj/leibniz.o obj/time.o obj/pleibniz.o
	gcc -Wall -g3 $^ -o  all.out -lpthread -lrt -lm

obj/main.o: src/main.c inc/leibniz.h inc/pleibniz.h inc/euler.h inc/pleibniz.h inc/time.h
	gcc -w -c $< -o $@ -I./inc

obj/euler.o: src/euler.c inc/time.h
	gcc -c $< -o $@ -I./inc

obj/peuler.o: src/peuler.c inc/time.h
	gcc -w -c $< -o $@ -I./inc

obj/leibniz.o: src/leibniz.c
	gcc -c $< -o $@ -I./inc

obj/time.o: src/time.c
	gcc -c $< -o $@

obj/pleibniz.o: src/pleibniz.c
	gcc -w -c $< -o $@ -I./inc

clear:
	rm -f ./obj/*.o *.out

run: all.out
	./all.out ${arg1} ${arg2} ${arg3} ${arg4}

plot:
	gnuplot ./data/plot.p