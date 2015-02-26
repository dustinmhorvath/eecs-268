/*
 * Cow.h
 *
 *  Created on: Sep 23, 2014
 *      Author: d553h471
 */

#ifndef COW_H
#define COW_H

#include "FarmAnimal.h"

class Cow : public FarmAnimal{
protected:
	double m_milkProduced;

public:
	/*
	/@pre none.
	/@post Builds a cow object.
	/@return none.
	*/
	Cow();

	/*
	/@pre Requires cow object.
	/@post none.
	/@return gives back m_milkProduced member value.
	*/
	double getMilkProduced() const;

	/*
	/@pre Requires cow object.
	/@post Sets member variable m_milkProduced to 'gallons'.
	/@return none.
	*/
	void setMilkProduced(double gallons);


};



#endif
