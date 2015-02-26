#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include "MazeReader.h"
#include "MazeCreationException.h"
#include "MazeWalker.h"
#include "Position.h"

int main(int argc, char* argv[]){
	if(argc < 3){
		std::cout << "\nThis program requires a maze file as input to run. You must" << std::endl;
		std::cout << "also declare whether to use Depth First Search or Breadth First Search." << std::endl;
		std::cout << "This is done by appending -dfs or -bfs options." << std::endl;
		std::cout << "Please restart the program using './Maze maze_example.txt -searchoption'.\n" << std::endl;
		return 0;
	}

	std::string filename = argv[1];
	std::string search = argv[2];
	bool dfs;
	if("-dfs" == search){
		dfs = true;
	}
	else if("-bfs" == search){
		dfs = false;
	}
	else{
		std::cout << "Search option not recognized. Please restart the program" << std::endl;
		std::cout << "using the -bfs or -dfs options." << std::endl;
		return 0;
	}

	std::cout << "\nReading the maze...\n";
	MazeReader* mazeReader;
	try{
		mazeReader = new MazeReader(filename);
	}
	catch(MazeCreationException e){
		std::cout << e.what() << std::endl;
		std::cout << "Please restart the program." << std::endl;
		return 0;
	}
	std::cout << "Entering the maze using " << search << " option.\n\n";
	MazeWalker* mazeWalker = new MazeWalker(
		mazeReader -> getMaze(),
		mazeReader -> getStartRow(),
		mazeReader -> getStartCol(),
		mazeReader -> getRows(),
		mazeReader -> getCols(),
		dfs
	);

	mazeWalker -> walkMaze();



delete mazeReader;
delete mazeWalker;
return 0;
}
