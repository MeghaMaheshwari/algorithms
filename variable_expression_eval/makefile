output: main.o FileParser.o 
	g++ -std=c++0x main.o FileParser.o  -o output

main.o: main.cpp
	g++ -std=c++0x -c main.cpp

FileParser.o: FileParser.cpp FileParser.h
	g++ -std=c++0x -c FileParser.cpp

clean:
	rm *.o output
