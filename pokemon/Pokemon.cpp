/**
*	@file : Pokemon.cpp
*	@author :  Dustin Horvath
*	@date : 9/7/14
*	Purpose: Implementation of Pokemon Class
*/

#include <iostream>
#include <string>

#include "Dice.h"
#include "Pokemon.h"

Pokemon::Pokemon(){
	hp = 0;
	attackLevel = 0;
	defenseLevel = 0;
	attackBonus = 0;
	defenseBonus = 0;
	name = "";
	d20 = Dice(20);
	d6 = Dice(6);
}

bool Pokemon::attack(Pokemon &opponent){
	std::cout << name << " is attacking " << opponent.name << std::endl;
	attackBonus = d20.roll();
	std::cout << name << " rolls an attack bonus of " << attackBonus << std::endl;
	opponent.defenseBonus = d20.roll();
	std::cout << opponent.name << " rolls a defense bonus of " << opponent.defenseBonus << std::endl;
	if((attackLevel + attackBonus) > (opponent.defenseLevel + opponent.defenseBonus)){
		std::cout << "The attack hits dealing 3-D6 damage!" << std::endl;
		int a1 = d6.roll();
		int a2 = d6.roll();
		int a3 = d6.roll();
		int damage = a1 + a2 + a3;
		opponent.setHP(opponent.getHP() - damage);
		std::cout << "The rolls are are " << a1 << ", " << a2 << ", and " << a3 << " totaling: " << damage << " damage!" << std::endl;
		if(opponent.hp > 0){
			std::cout << opponent.name << " has " << opponent.hp << " hit points left" << std::endl;
		}
		else{
			std::cout << opponent.name << " has 0 hit points left" << std::endl;
		}

	}
	else{
		std::cout << "The attack missed!" << std::endl;
	}

	// Returns whether '&opponent' was killed by the attack.
	if(opponent.hp < 1){
		return true;
	}
	else return false;
}

void Pokemon::userBuild(){
	std::cout << "Please name your pokemon: ";
		std::cin >> name;
		std::cout << std::endl;
	std::cout << "How many hit points will it have? (1-50): ";
		bool firstRun = true;
		while(hp > 50 || hp < 1){
			if(!firstRun){
				std::cout << "Must be between 1 and 50: ";
			}
			std::cin >> hp;
			firstRun = false;
		}
		std::cout << std::endl;
	std::cout << "Split fifty points between attack level and defense level" << std::endl;
	std::cout << "Enter your attack level (1-49): ";
		firstRun = true;
			while(attackLevel < 1 || attackLevel > 49){
				if(!firstRun){
					std::cout << "Sorry. The attack level must be between 1 and 49: ";
				}
				std::cin >> attackLevel;

				firstRun = false;
			}
        firstRun = true;
        std::cout << std::endl;
	std::cout << "Enter your defense level (1-" << 50 - attackLevel << "): ";
	   while(defenseLevel < 1 || defenseLevel > (50 - attackLevel)){
		   if(!firstRun){
			   std::cout << "Sorry. The defense level must be between 1 and " << 50 - attackLevel << ": ";
		   }
		   std::cin >> defenseLevel;
		   firstRun = false;
	   }
	   std::cout << std::endl;

}


void Pokemon::setHP(int input){
	hp = input;
}
void Pokemon::setName(std::string string){
	name = string;
}
void Pokemon::setDefenseLevel(int input){
	defenseLevel = input;
}
void Pokemon::setAttackLevel(int input){
	attackLevel = input;
}

int Pokemon::getHP(){
	return hp;
}
std::string Pokemon::getName(){
	return name;
}
int Pokemon::getDefenseLevel(){
	return defenseLevel;
}
int Pokemon::getAttackLevel(){
	return attackLevel;
}

