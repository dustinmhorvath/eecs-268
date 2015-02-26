/*
 * FarmAnimal.cpp
 *
 *  Created on: Sep 23, 2014
 *      Author: d553h471
 */

#include "FarmAnimal.h"
#include <string>

FarmAnimal::FarmAnimal(){
	m_name = "unset";
	m_sound = "undet";
}

std::string FarmAnimal::getName() const{
	return m_name;
}

void FarmAnimal::setName(std::string name){
	m_name = name;
}

std::string FarmAnimal::getSound() const{
	return m_sound;
}

void FarmAnimal::setSound(std::string sound){
	m_sound = sound;
}
