/*
 * Cow.cpp
 *
 *  Created on: Sep 23, 2014
 *      Author: d553h471
 */

#include "Cow.h"

Cow::Cow(){
	m_name = "Cow";
	m_sound = "Moo";
}

double Cow::getMilkProduced() const{
	return m_milkProduced;
}

void Cow::setMilkProduced(double gallons){
	m_milkProduced = gallons;
}

