#Play groundowy MAKEFILE

Play:  play.o 
	g++ -o PLAY -std=c++11  play.o  

play.o: play.cpp Wektor.h  Macierz.hh  rozmiar.h 
	g++ -c -Wall -pedantic -std=c++11 -o play.o play.cpp




clean: 
	rm -f *.o
