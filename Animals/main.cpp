/*
 * main.cpp
 *
 *  Created on: Sep 23, 2014
 *      Author: d553h471
 */

#include "CyberChicken.h"
#include "Cow.h"
#include "FarmAnimal.h"
#include "AnimalPen.h"
#include "Cow.h"

#include <iostream>
#include <string>

void goodbyeMessage(const FarmAnimal& animal){
	std::cout << "Upon release, the " << animal.getName() << " said " << animal.getSound() << "." << std::endl;
}


int main(){
	AnimalPen pen = AnimalPen();
	bool cont = true;
	int tempInt = 0;
	double tempDouble;
	char tempChar;
	Cow* cowPtr = nullptr;
	Chicken* chickenPtr = nullptr;
	CyberChicken* cyberPtr = nullptr;
	while(cont){
		std::cout << "Select an animal to add to the pen:" << std::endl;
		std::cout << "1.) Cow (produces milk)" << std::endl;
		std::cout << "2.) Chicken (cannot lay eggs)" << std::endl;
		std::cout << "3.) Cyber Chicken (seems dangerous, but lays eggs)" << std::endl;
		std::cout << "--------------------------------------------------- <<" << std::endl;
		std::cout << "choice: ";
		std::cin >> tempInt;
		switch(tempInt){
			case 1:
			std::cout << "How many gallons of milk did this cow produce?: ";
			std::cin >> tempDouble;
			cowPtr = new Cow();
			cowPtr -> setMilkProduced(tempDouble);
			pen.addAnimal(cowPtr);
			break;

			case 2:
			std::cout << "Add an eggless chicken to the pen? OK. You're the boss." << std::endl;
			chickenPtr = new Chicken();
			pen.addAnimal(chickenPtr);
			break;

			case 3:
			std::cout << "How many eggs did this cyber chicken produce?: ";
			std::cin >> tempInt;
			cyberPtr = new CyberChicken();
			cyberPtr -> setCyberEggs(tempInt);
			pen.addAnimal(cyberPtr);
			break;
		}
		std::cout << "Done adding animals? (y/n): ";
		std::cin >> tempChar;

		if(tempChar == 'y'){
			cont = false;
		}
		std::cout << std::endl;
	}

	std::cout << "Releasing all animals!" << std::endl;
	std::cout << "-------------------------" << std::endl;

	double milk = 0;
	int eggs = 0;
	while(!pen.isEmpty()){
		if((pen.peekAtNextAnimal() -> getName()) == "Chicken"){
			chickenPtr = static_cast<Chicken*>(pen.peekAtNextAnimal());
			std::cout << "Chicken unable to lay eggs. Perhaps cybornetic implants will help?" << std::endl;
			goodbyeMessage(*chickenPtr);
			std::cout << "Chicken destructor called." << std::endl;
		}
		else if((pen.peekAtNextAnimal() -> getName()) == "CyberChicken"){
			cyberPtr = static_cast<CyberChicken*>(pen.peekAtNextAnimal());
			std::cout << "This Cyber Chicken laid " << cyberPtr -> getCyberEggs() << " cyber eggs. Humanity is in trouble." << std::endl;
			eggs = eggs + cyberPtr -> getCyberEggs();
			goodbyeMessage(*cyberPtr);
			std::cout << "CyberChicken Destructor called." << std::endl;
			std::cout << "Chicken Destructor called." << std::endl;
		}
		else if((pen.peekAtNextAnimal()) -> getName() == "Cow"){
			cowPtr = static_cast<Cow*>(pen.peekAtNextAnimal());
			std::cout << "This cow produced " << cowPtr -> getMilkProduced() << " gallons of milk." << std::endl;
			milk = milk + cowPtr -> getMilkProduced();
			goodbyeMessage(*cowPtr);
		}
			pen.releaseAnimal();

	}
	std::cout << "Your farm produced " << milk << " of milk and " << eggs << " eggs." << std::endl;


	return 0;
}

