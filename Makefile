FLAG= -Wall -g

all: graph graphAlgos graphAlgod 

graphAlgod: libclassgraphAlgo.so
graphAlgos: libclassgraphAlgo.a

libclassgraphAlgo.so: graphAlgo.o
	gcc $(FLAG) -shared -o libclassgraphAlgo.so  graphAlgo.o 
libclassgraphAlgo.a:  graphAlgo.o
	ar -rcs libclassgraphAlgo.a graphAlgo.o

graph: main.o libclassgraphAlgo.a
	gcc $(FLAG) -o graph main.o ./libclassgraphAlgo.a -lm



graphAlgo.o: graphAlgo.c graph.h
	gcc $(FLAG) -c graphAlgo.c
main.o: main.c graph.h
	gcc $(FLAG) -c main.c

.PHONY: clean all
clean:
	rm -f *.o *.so *.a graph
