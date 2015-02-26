/*
 * Chicken.cpp
 *
 *  Created on: Sep 23, 2014
 *      Author: d553h471
 */

#include "Chicken.h"

Chicken::Chicken(){
	m_name = "Chicken";
	m_sound = "Cluck";
}

int Chicken::getEggs() const{
	return m_eggs;
}

void Chicken::setEggs(int eggs){
	m_eggs = eggs;
}

