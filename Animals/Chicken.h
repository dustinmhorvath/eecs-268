/*
 * Chicken.h
 *
 *  Created on: Sep 23, 2014
 *      Author: d553h471
 */

#ifndef CHICKEN_H_
#define CHICKEN_H_

#include "FarmAnimal.h"

class Chicken : public FarmAnimal{
protected:
	/*
	/@pre requires Chicken object.
	/@post none.
	/@return Gives back m_eggs.
	*/
	int getEggs() const;

	/*
	/@pre Requires Chicken object.
	/@post Sets m_eggs to 'eggs'.
	/@return none.
	*/
	void setEggs(int eggs);

	int m_eggs;
public:
	/*
	/@pre none.
	/@post Makes a chicken object.
	/@return none.
	*/
	Chicken();

};


#endif /* CHICKEN_H_ */
