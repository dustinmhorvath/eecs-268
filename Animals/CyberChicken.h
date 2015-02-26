/*
 * CyberChicken.h
 *
 *  Created on: Sep 23, 2014
 *      Author: d553h471
 */

#ifndef CYBERCHICKEN_H
#define CYBERCHICKEN_H

#include "Chicken.h"

class CyberChicken : public Chicken{
public:
	/*
	/@pre none.
	/@post Builds a cyberchicken object.
	/@return none.
	*/
	CyberChicken();
	/*
	/@pre Requires cyberchicken object.
	/@post none.
	/@return Gives back m_cyberEggs.
	*/
	int getCyberEggs() const;

	/*
	/@pre Requires cyberchicken object.
	/@post Sets m)cyberEggs to 'eggs'.
	/@return none.
	*/
	void setCyberEggs(int eggs);
};



#endif
