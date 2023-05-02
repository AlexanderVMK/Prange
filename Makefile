all: main matrix
	g++ -o Prange PrangeISD.o matrix.o

main: PrangeISD.cpp
	g++ -c PrangeISD.cpp

matrix: matrix.cpp
	g++ -c matrix.cpp

clear:
	rm *.o
