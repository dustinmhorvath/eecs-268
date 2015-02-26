/*
 * CyberChicken.cpp
 *
 *  Created on: Sep 23, 2014
 *      Author: d553h471
 */

#include "CyberChicken.h"
#include <string>

CyberChicken::CyberChicken(){
	m_name = "CyberChicken";
	m_eggs = 0;
	m_sound = "resistance is futile";
};

int CyberChicken::getCyberEggs() const{
	return m_eggs;
}

void CyberChicken::setCyberEggs(int eggs){
	m_eggs = eggs;
}


