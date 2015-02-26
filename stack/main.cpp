/**
*	@file : main.cpp
*	@author :  Dustin Horvath
*	@date : 9/15/14
*	Purpose: Implementation of main
*/

#include <iostream>
#include <string>
#include "StackOfBoxes.h"
#include "Box.h"


int main(){
	StackOfBoxes stackOnStack = StackOfBoxes();
	StackOfBoxes* stackOnHeap = new StackOfBoxes();

	int number = 0;

	stackOnStack.push(1);
	stackOnStack.push(2);
	stackOnStack.push(3);



	std::cout << stackOnStack.pop() << std::endl;
	std::cout << stackOnStack.pop() << std::endl;
	std::cout << stackOnStack.pop() << std::endl;


	stackOnHeap -> push(4);
	stackOnHeap -> push(5);
	stackOnHeap -> push(6);

	std::cout << stackOnHeap -> pop() << std::endl;
	std::cout << stackOnHeap -> pop() << std::endl;
	std::cout << stackOnHeap -> pop() << std::endl;

	delete stackOnHeap;
}
