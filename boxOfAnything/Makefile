SOA: main.o Menu.o
	g++ -g -std=c++0x main.o Menu.o -o SOA

main.o: main.cpp BoxOfAnything.h BoxOfAnything.hpp Menu.h StackOfAnything.h StackOfAnything.hpp
	g++ -g -std=c++0x -c main.cpp

Menu.o: Menu.cpp Menu.h
	g++ -g -std=c++0x -c Menu.cpp

clean: 
	rm *.o main
	clean done
