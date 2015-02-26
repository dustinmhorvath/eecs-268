Maze: main.o MazeWalker.o MazeReader.o Position.o MazeCreationException.o
	g++ -std=c++11 -g main.o MazeWalker.o MazeReader.o Position.o MazeCreationException.o -o Maze

main.o: main.cpp MazeWalker.h MazeReader.h Position.h MazeCreationException.h
	g++ -std=c++11 -g -c main.cpp

MazeWalker.o: MazeWalker.h MazeWalker.cpp
	g++ -std=c++11 -g -c MazeWalker.cpp

MazeReader.o: MazeReader.h MazeReader.cpp
	g++ -std=c++11 -g -c MazeReader.cpp

Position.o: Position.h Position.cpp
	g++ -std=c++11 -g -c Position.cpp

MazeCreationException.o: MazeCreationException.h MazeCreationException.cpp
	g++ -std=c++11 -g -c MazeCreationException.cpp

clean: 
	rm *.o Maze *.gch
	clean done

