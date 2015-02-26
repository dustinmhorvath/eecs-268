/*
 * FarmAnimal.h
 *
 *  Created on: Sep 23, 2014
 *      Author: d553h471
 */

#ifndef FARMANIMAL_H
#define FARMANIMAL_H

#include <string>
#include <iostream>

class FarmAnimal{
protected:
	std::string m_name;
	std::string m_sound;

public:
	/*
	/@pre none.
	/@post Builds a farmanimal object.
	/@return none.
	*/
	FarmAnimal();

	/*
	/@pre Requires a farmanimal object.
	/@post none.
	/@return gives back m_name.
	*/
	std::string getName() const;

	/*
	/@pre requires a farmanimal object.
	/@post Sets m_name equal to 'name'.
	/@return none.
	*/
	void setName(std::string name);

	/*
	/@pre Requires farmanimal object.
	/@post none.
	/@return gives back m_name.
	*/
	std::string getSound() const;

	/*
	/@pre Requires farmanimal object.
	/@post Sets m_sound equal to 'sound'.
	/@return none.
	*/
	void setSound(std::string sound);

};



#endif
