/**
*	@file : Pokemon.h
*	@author :  Dustin Horvath
*	@date : 9/7/14
*	Purpose: Header file of Pokemon Class
*/

#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>

class Pokemon{
private:
	int hp;
	int attackLevel;
	int defenseLevel;
	std::string name;
	Dice d20;
	Dice d6;

public:
	/*
	 * These are used in hit calculation. Probably could've been
	 * private, but that would've just created more unnecessary work.
	 * @note: Constructor will initialize these to zero.
	 */
	int attackBonus;
	int defenseBonus;

	/*
	 * @pre Requires imported Dice class.
	 * @post Creates and initializes an instance of Pokemon object.
	 */
	Pokemon();

	/*
	 * @pre Two Pokemon objects, one to call, and one as the argument.
	 * @post Passes in a Pokemon by reference, outputs attack dialogue to
	 * console, calculates and SETs damage to '&opponent' pokemon HP.
	 * @return Returns whether or not '&opponent''s hp was reduced to zero.
	 */
	bool attack(Pokemon &opponent);

	/*
	 * @pre Requires a Pokemon object that has been initialized.
	 * @post Gets input from user for several Object variables.
	 * return None
	 */
	void userBuild();

	/*
	 * SET block for private member variables.
	 * @pre Require an instance of Pokemon object.
	 * @post Takes in a value and sets the private member variable
	 * to that value.
	 */
	void setHP(int input);
	void setName(std::string string);
	void setDefenseLevel(int input);
	void setAttackLevel(int input);

	/*
	 * GET block for private member variables.
	 * @pre Require an instance of Pokemon object.
	 * @post Takes in a value and sets the private member variable
	 * to that value.
	 */
	int getHP();
	std::string getName();
	int getDefenseLevel();
	int getAttackLevel();


};


#endif
