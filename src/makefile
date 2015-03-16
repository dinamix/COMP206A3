objects = main.o list.o
coptions = -Wall -g -ggdb

run : ${objects}
	gcc ${coptions} -o run ${objects}

main.o : main.c list.h
	gcc ${coptions} -c main.c

list.o : list.c list.h
	gcc ${coptions} -c list.c

clean :
	rm -f run ${objects}
