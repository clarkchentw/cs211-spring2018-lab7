max: max1.o max2.o
	gcc -o max max1.o max2.o

max1.o: max1.c max.h
	gcc -c max1.c

max2.o: max2.c max.h
	gcc -c max2.c

clean:
	rm max1.o max2.o  max
