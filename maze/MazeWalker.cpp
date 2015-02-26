
#include <iostream>
#include <fstream>
#include "Position.h"
#include "MazeWalker.h"
#include <queue>
#include <stack>

MazeWalker::MazeWalker(char** mazePtr, int startRow, int startCol, int rows, int cols, bool dfs) : m_curPos(startRow, startCol), m_startPos(startRow, startCol){
	m_isDFS = dfs;
	m_maze = mazePtr;
	m_rows = rows;
	m_cols = cols;
	m_count = 0;
	m_visited = new bool*[m_rows];
	for(int i = 0; i < m_rows; i++){
		m_visited[i] = new bool[m_cols];
		for(int j = 0; j < m_cols; j++){
			m_visited[i][j] = false;
		}
	}

	m_visited[startCol][startRow] = true;
	m_curPos.setRow(startRow);
	m_curPos.setCol(startCol);
	storeValidMoves();
}

MazeWalker::~MazeWalker(){
	for(int i = 0; i < m_rows; i++){
		delete[] m_visited[i];
	}
	delete[] m_visited;
}

void MazeWalker::walkMaze(){
	bool noExit = false;
	for(int i = 0; i < m_rows; i++){
		for(int j = 0; j < m_cols; j++){
			std::cout << m_visited[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << "Visited position (" << m_curPos.getRow() << "," << m_curPos.getCol() << ")\n" << std::endl;
	while(!isGoalReached() && noExit == false){
		if(m_isDFS){
			move(m_moveStack.top());
			m_moveStack.pop();
		}
		else if(!m_isDFS){
			move(m_moveQueue.front());
			m_moveQueue.pop();
		}
		storeValidMoves();
		for(int i = 0; i < m_rows; i++){
			for(int j = 0; j < m_cols; j++){
				std::cout << m_visited[i][j];
			}
			std::cout << std::endl;
		}
		std::cout << "Visited position (" << m_curPos.getRow() << "," << m_curPos.getCol() << ")" << std::endl;
		std::cout << "--------------------------\n";
		if(m_moveStack.size() == 0 && m_isDFS){
			noExit = true;
		}
		else if(m_moveQueue.size() == 0 && !m_isDFS){
			noExit = true;
		}
	}
	if(isGoalReached()){
		std::cout << "\nReached the exit at (" << m_curPos.getRow() << "," << m_curPos.getCol() << ") in " << m_count << " moves.\n" << std::endl;
	}
	if(noExit && !isGoalReached()){
		std::cout << "\nThis maze has no exit from this starting point.\n\n";
	}

	while(!m_moveStack.empty()){
		m_moveStack.pop();
	}
	while(!m_moveQueue.empty()){
		m_moveQueue.pop();
	}
}

void MazeWalker::storeValidMoves(){
//	std::cout << m_curPos.getRow() << " " << m_curPos.getCol() << "\n";//FOR TESTING
//	std::cout << m_rows << " " << m_cols << "\n";//FOR TESTING
	if(m_isDFS){
		if(m_curPos.getRow() > 0){
			if(m_maze[m_curPos.getRow() - 1][m_curPos.getCol()] != 'W' && !m_visited[m_curPos.getRow() - 1][m_curPos.getCol()]){
				m_moveStack.push(Position(m_curPos.getRow() - 1,m_curPos.getCol()));
			}
		}
		if(m_curPos.getRow() < m_rows - 1){
			if(m_maze[m_curPos.getRow() + 1][m_curPos.getCol()] != 'W' && !m_visited[m_curPos.getRow() + 1][m_curPos.getCol()]){
				m_moveStack.push(Position(m_curPos.getRow() + 1,m_curPos.getCol()));
			}
		}
		if(m_curPos.getCol() > 0){
			if(m_maze[m_curPos.getRow()][m_curPos.getCol() - 1] != 'W' && !m_visited[m_curPos.getRow()][m_curPos.getCol() - 1]){
				m_moveStack.push(Position(m_curPos.getRow(),m_curPos.getCol() - 1));
			}
		}
		if(m_curPos.getCol() < m_cols - 1){
			if(m_maze[m_curPos.getRow()][m_curPos.getCol() + 1] != 'W' && !m_visited[m_curPos.getRow()][m_curPos.getCol() + 1]){
				m_moveStack.push(Position(m_curPos.getRow(),m_curPos.getCol() + 1));
			}
		}
	}
	else if(!m_isDFS){
		if(m_curPos.getRow() > 0){
			if(m_maze[m_curPos.getRow() - 1][m_curPos.getCol()] != 'W' && !m_visited[m_curPos.getRow() - 1][m_curPos.getCol()]){
				m_moveQueue.push(Position(m_curPos.getRow() - 1,m_curPos.getCol()));
			}
		}
		if(m_curPos.getRow() < m_rows - 1){
			if(m_maze[m_curPos.getRow() + 1][m_curPos.getCol()] != 'W' && !m_visited[m_curPos.getRow() + 1][m_curPos.getCol()]){
				m_moveQueue.push(Position(m_curPos.getRow() + 1,m_curPos.getCol()));
			}
		}
		if(m_curPos.getCol() > 0){
			if(m_maze[m_curPos.getRow()][m_curPos.getCol() - 1] != 'W' && !m_visited[m_curPos.getRow()][m_curPos.getCol() - 1]){
				m_moveQueue.push(Position(m_curPos.getRow(),m_curPos.getCol() - 1));
			}
		}
		if(m_curPos.getCol() < m_cols - 1){
			if(m_maze[m_curPos.getRow()][m_curPos.getCol() + 1] != 'W' && !m_visited[m_curPos.getRow()][m_curPos.getCol() + 1]){
				m_moveQueue.push(Position(m_curPos.getRow(),m_curPos.getCol() + 1));
			}
		}
	}
}

void MazeWalker::move(Position& p){
	m_visited[p.getRow()][p.getCol()] = true;
	m_curPos.setRow(p.getRow());
	m_curPos.setCol(p.getCol());
	m_count++;
}

bool MazeWalker::isGoalReached() const{
	if(m_maze[m_curPos.getRow()][m_curPos.getCol()] == 'E'){
		return true;
	}
	else return false;
}
