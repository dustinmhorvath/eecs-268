q2: main.o PreconditionViolationException.o
	g++ -g -Wall -std=c++0x main.o PreconditionViolationException.o -o q2

main.o: main.cpp StackOfAnything.h Queue.h StackOfAnything.h
	g++ -g -Wall -std=c++0x -c main.cpp

PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp
	g++ -g -Wall -std=c++0x -c PreconditionViolationException.cpp

clean:
	rm *.o q2
