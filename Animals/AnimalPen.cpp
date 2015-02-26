/*
 * AnimalPen.cpp
 *
 *  Created on: Sep 23, 2014
 *      Author: d553h471
 */


#include "AnimalPen.h"

AnimalPen::AnimalPen(){}

AnimalPen::~AnimalPen(){
	while(!isPenEmpty()){
		pop();
	}
}


void AnimalPen::addAnimal(FarmAnimal* animal){
	push(animal);
}


FarmAnimal* AnimalPen::peekAtNextAnimal(){
	return(peek());
}


void AnimalPen::releaseAnimal(){
	pop();
}

bool AnimalPen::isPenEmpty(){
	return(isEmpty());
}

