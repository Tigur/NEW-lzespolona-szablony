ZESP:  zesp.o lzespolonaa.o
	 g++ -o ZESP  -std=c++11   zesp.o lzespolonaa.o


zesp.o: zesp.cpp lzespolonaa.hh
	g++ -c -Wall -pedantic -std=c++11 -o  zesp.o  zesp.cpp


lzespolonaa.o: lzespolonaa.cpp lzespolonaa.hh
	g++ -c -Wall -pedantic -std=c++11 -o  lzespolonaa.o  lzespolonaa.cpp


clean:
	rm -f *.o





