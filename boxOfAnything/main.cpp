/*
 * main.cpp
 *
 *  Created on: Sep 15, 2014
 *      Author: dhorvath
 */


#include "BoxOfAnything.h"
#include "StackOfAnything.h"
#include "Menu.h"
#include <iostream>

int main(){

	int tempInt = 0;
	char tempChar = 0;
	bool cont = true;

	menu* myMenu = new menu();
	StackOfAnything <int> intStack;
	StackOfAnything <char> charStack;
	while(cont){
		myMenu -> menu::printMenu();
		switch(myMenu -> choice){
			case 1:
				std::cout << "Enter a number: ";
				std::cin >> tempInt;
				intStack.push(tempInt);
				std::cout << tempInt << " added to stack" <<std::endl;
			break;
			case 2:
				std::cout << "Enter a character: ";
				std::cin >> tempChar;
				charStack.push(tempChar);
				std::cout << tempChar << " added to stack" << std::endl;
			break;
			case 3:
				try{
				intStack.peek();
				std::cout << "The top of the stack is " << intStack.peek() << std::endl;
				}
				catch(std::runtime_error& e){
				std::cout << "ERROR" << std::endl;
				std::cout << e.what() << std::endl;
				}
			break;
			case 4:
				try{
				charStack.peek();
				std::cout << "The top of the stack is " << charStack.peek() << std::endl;
				}
				catch(std::runtime_error& e){
				std::cout << "ERROR" << std::endl;
				std::cout << e.what() << std::endl;
				}
			break;
			case 5:
				try{
				std::cout << intStack.pop() << " has been removed from the stack" << std::endl;
				}
				catch(std::runtime_error& e){
				std::cout << "ERROR" << std::endl;
				std::cout << e.what() << std::endl;
				}
			break;
			case 6:
				try{
				std::cout << charStack.pop() << " has been removed from the stack" << std::endl;
				}
				catch(std::runtime_error& e){
				std::cout << "ERROR" << std::endl;
				std::cout << e.what() << std::endl;
				}
			break;
			case 7:
				std::cout << "The number stack contains " << intStack.size() << " numbers" << std::endl;
			break;
			case 8:
				std::cout << "The character stack contains " << charStack.size() << " numbers" << std::endl;
			break;
			case 9:
				cont = false;
				std::cout << std::endl << "Exiting..." << std::endl;
			break;

		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
	delete myMenu;
	return 0;
}
