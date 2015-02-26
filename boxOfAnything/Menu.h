/*
 * Menu.h
 *
 *  Created on: Sep 21, 2014
 *      Author: Dustin
 */

#ifndef MENU_H_
#define MENU_H_

class menu{
	public:
		/*
		 * @pre none.
		 * @post Builds a 'menu' object so that its functions can be used.
		 * @return none.
		 */
		menu();

		/*
		 * @pre Requires a 'menu' object initialized.
		 * @post stores user input from dialog in menu.choice
		 * @return none
		 */
		void printMenu();
		int choice;
};



#endif /* MENU_H_ */
