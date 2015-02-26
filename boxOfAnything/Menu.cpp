/*
 * Menu.cpp
 *
 *  Created on: Sep 21, 2014
 *      Author: Dustin
 */

#include <iostream>
#include "Menu.h"

menu::menu(){
	choice = 0;
}
void menu::printMenu(){
	std::cout <<
	"Select an action:" << std::endl <<
	"1) Push onto the number stack" << std::endl <<
	"2) Push onto the character stack" << std::endl <<
	"3) Peek at top of number stack" << std::endl <<
	"4) Peek at top of character stack" << std::endl <<
	"5) Pop top of number stack" << std::endl <<
	"6) Pop top of char stack" << std::endl <<
	"7) Check size of number stack" << std::endl <<
	"8) Check size of char stack" << std::endl <<
	"9) Quit" << std::endl <<
	"Enter choice: ";
	std::cin >> menu::choice;
	std::cout << "You selected: " << menu::choice << std::endl;


}



