/*
 * main.cpp
 *
 *  Created on: Aug 25, 2014
 *      Author: dhorvath
 */

#include <string>
#include <iostream>

#include "Dice.h"
#include "Pokemon.h"


int main(){
	Pokemon p1 = Pokemon();
	Pokemon p2 = Pokemon();
	int round = 1;
	Dice d10 = Dice(10);
	int roll = 0;

	std::cout << "Player 1, build your Pokemon!" << std::endl << "=====================" << std::endl;
	p1.userBuild();
	std::cout << "Player 2, build your Pokemon!" << std::endl << "=====================" << std::endl;
	p2.userBuild();

	std::cout << "Player 1 will roll a D10, 6 or higher to go first." << std::endl;
	roll = d10.roll();
	std::cout << "Player 1 rolls a " << roll << " and will go ";
	if(roll > 5){std::cout << "first"; }
	else{ std::cout << "second";}
	std::cout << "." << std::endl;

	if(roll > 5){
		while(p1.getHP() > 0 && p2.getHP() > 0 && round < 11){
			std::cout << std::endl << "Round " << round << "!" << std::endl << std::endl;
			if(!p1.attack(p2)){
				if(p2.attack(p1)){
					std::cout << p1.getName() << " has been defeated!" << std::endl;
				}
			}
			else{
				std::cout << p2.getName() << " has been defeated!" << std::endl;
			}
			round = round + 1;
		}
	}
	else{
		while(p1.getHP() > 0 && p2.getHP() > 0 && round < 11){
			std::cout << std::endl << "Round " << round << "!" << std::endl << std::endl;
			if(!p2.attack(p1)){
				if(p1.attack(p2)){
					std::cout << p2.getName() << " has been defeated!" << std::endl;
				}
			}
			else{
				std::cout << p1.getName() << " has been defeated!" << std::endl;
			}
			round = round + 1;
		}
	}

	if(p1.getHP() > 0 && p2.getHP() > 0){
				std::cout << "Both fighters are still standing! It's a draw!" << std::endl;
			}

	return 0;
}
