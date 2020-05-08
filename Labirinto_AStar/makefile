all: labirinto_console

labirinto_console: labirinto_main.o labirinto.o
	g++ labirinto_main.o labirinto.o -o labirinto_console

labirinto_main.o: labirinto_main.cpp labirinto.h
	g++ -c -Wall -pedantic labirinto_main.cpp

labirinto.o: labirinto.cpp labirinto.h
	g++ -c -Wall -pedantic labirinto.cpp

clean:
	rm -rf *.o *~ labirinto_console
