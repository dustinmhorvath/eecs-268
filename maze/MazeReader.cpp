#include <fstream>
#include <iostream>
#include <string>
#include "MazeReader.h"

MazeReader::MazeReader(std::string file) throw (MazeCreationException) : m_in(file){
	m_in >> m_rows;
	if(!m_in){
		throw(MazeCreationException("Row or column data is in non-integer format. Please format correctly and restart."));
	}
	m_in >> m_cols;
	if(!m_in){
		throw(MazeCreationException("Row or column data is in non-integer format. Please format correctly and restart."));
	}
	m_in >> m_startRow;
	if(!m_in){
		throw(MazeCreationException("Row or column data is in non-integer format. Please format correctly and restart."));
	}
	m_in >> m_startCol;
	if(!m_in){
		throw(MazeCreationException("Row or column data is in non-integer format. Please format correctly and restart."));
	}

	if(m_startRow >= m_rows || m_startRow < 0 || m_startCol >= m_cols || m_startCol < 0){
		throw(MazeCreationException("Start position outside array dimensions."));
	}
	else{

		m_maze = new char*[m_rows];
		for(int i = 0; i < m_rows; i++){
			m_maze[i] = new char[m_cols];
		}
		readMaze();
	}
}

MazeReader::~MazeReader(){
	for(int i = 0; i < m_rows; i++){
		delete[] m_maze[i];
	}
	delete[] m_maze;

	m_in.close();
}

char** MazeReader::getMaze() const{
	return m_maze;
}

int MazeReader::getCols() const{
	return m_cols;
}


int MazeReader::getRows() const{
	return m_rows;
}

int MazeReader::getStartCol() const{
	return m_startCol;
}

int MazeReader::getStartRow() const{
	return m_startRow;
}

void MazeReader::readMaze() throw (MazeCreationException){
	for(int i = 0; i < m_rows; i++){
		for(int j = 0; j < m_cols; j++){
			m_in >> m_maze[i][j];
			std::cout << m_maze[i][j];
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}
