/**
*	@file main.cpp
*	@author 
*	@date 
*/

#include <iostream>
#include "StackOfAnything.h"
#include "Queue.h"

template <typename T>
void printComparisons(const Queue<T>& q, const StackOfAnything<T>& s)
{
	std::cout 	<< "Compare queue and stack:\n"
			<< "q < s: " <<  (q < s) 	<< "\n"
			<< "s < q: " <<  (s < q) 	<< "\n"
			<< "q == s: " << (q == s) 	<< "\n"
			<< "s == q: " << (s == q) 	<< "\n";
}

template <typename T>
bool operator==(const StackOfAnything<T>& s, const Queue<T>& q){
	if(s.size() == q.size()){
		return true;
	}
	else return false;
}	// I'm not going to make these return a string because...I don't like that. Returning
	// a bool makes more sense.

template <typename T>
bool operator==(const Queue<T>& q, const StackOfAnything<T>& s){
	if(q.size() == s.size()){
		return true;
	}
	else return false;
}

template <typename T>
bool operator<(const StackOfAnything<T>& s, const Queue<T>& q){
	if(s.size() < q.size()){
			return true;
		}
		else return false;
}

template <typename T>
bool operator<(const Queue<T>& q, const StackOfAnything<T>& s){
	if(q.size() < s.size()){
		return true;
	}
	else return false;
}

int main(){
	StackOfAnything<int> stack;
	Queue<int> queue;
	bool cont = true;
	int num;

	while(cont){
		std::cout << "1. Push onto stack" << std::endl;
		std::cout << "2. Enqueue in queue" << std::endl;
		std::cout << "3. Print Comparisons" << std::endl;
		std::cout << "4. Quit" << std::endl;
		std::cout << "What to do?: ";
		std::cin >> num;
		std::cout << std::endl <<std::endl;

		switch(num){
			case 1:
				std::cout << "What number do you want to push?: ";
				std::cin >> num;
				stack.push(num);
			break;
			case 2:
				std::cout << "What number do you want to queue?: ";
				std::cin >> num;
				queue.enqueue(num);
			break;
			case 3:
				printComparisons(queue, stack);
			break;
			case 4:
				std::cout << "Goodbye." << std::endl;
				cont = false;
			break;
			default:
				std::cout << "Invalid input, quitting..." << std::endl;
				cont = false;
			break;
		}
		std::cout << std::endl;
	}


	return 0;
}
