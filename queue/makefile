Queue: main.o PreconditionViolationException.o
	g++ -g -std=c++0x main.o PreconditionViolationException.o -o Queue

main.o: main.cpp Queue.h Queue.hpp BoxOfAnything.h BoxOfAnything.hpp PreconditionViolationException.h
	g++ -g -std=c++0x -c main.cpp

PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp
	g++ -g -std=c++0x -c PreconditionViolationException.cpp

clean: 
	rm *.o main
	clean done

