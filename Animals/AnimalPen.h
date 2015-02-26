/*
 * AnimalPen.h
 *
 *  Created on: Sep 23, 2014
 *      Author: d553h471
 */

#ifndef ANIMALPEN_H
#define ANIMALPEN_H

#include "StackOfAnything.h"
#include "FarmAnimal.h"

class AnimalPen : public StackOfAnything<FarmAnimal*>{
public:
	/*
	/@pre none.
	/@post Builds an AnimalPen stack.
	/@return none.
	*/
	AnimalPen();

	/*
	/@pre Requires animalpen object.
	/@post deletes all objects on the stack, then deletes the stack.
	/@return none.
	*/
	~AnimalPen();

	/*
	/@pre Requires animalpen object.
	/@post Adds a farmanimal pointer to the top of the animalpen stack.
	/@return none.
	*/
	void addAnimal(FarmAnimal* animal);

	/*
	/@pre Requires animalpen object with at least one pointer on stack.
	/@post none.
	/@return Gives back the farmanimal pointer on the top of the stack.
	*/
	FarmAnimal* peekAtNextAnimal();

	/*
	/@pre Requires animalpen object with one pointer on stack.
	/@post Removes the pointer from the top of the stack and
	/ adjusts accordingly.
	/@return none.
	*/
	void releaseAnimal();

	/*
	/@pre Requires an animalpen object.
	/@post none.
	/@return Returns whether or not the stack is empty.
	*/
	bool isPenEmpty();


};

#endif
