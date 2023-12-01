source.out: library.o reader.o book.o source.o 
	g++ library.o reader.o book.o source.o  -o source.out

source.o: source.cpp
	g++ -c source.cpp

library.o: library.cpp
	g++ -c library.cpp

reader.o: reader.cpp
	g++ -c reader.cpp

book.o: book.cpp
	g++ -c book.cpp

clean:
	rm *.o source.out