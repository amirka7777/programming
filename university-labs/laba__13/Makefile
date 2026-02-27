.PHONY: clean

all: program


program: src/main.c libcars.a
	gcc -Iinclude src/main.c -L. -lcars -o program

libcars.a: obj/carsFunction.o
	ar rcs libcars.a obj/carsFunction.o

obj/carsFunction.o: src/carsFunction.c include/carsHeader.h
	gcc -Iinclude -c src/carsFunction.c -o obj/carsFunction.o


clean:
	rm -f obj/*.o libcars.a program