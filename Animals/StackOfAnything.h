/*
 * StackOfAnything.h
 *
 *  Created on: Sep 15, 2014
 *      Author: dhorvath
 */


#ifndef STACKOFANYTHING_H
#define STACKOFANYTHING_H

#include "BoxOfAnything.h"
#include <stdexcept>
#include <iostream>
#include <string>

template <typename T>
class StackOfAnything{
	private:
		BoxOfAnything<T>* m_top;
		int m_size;

	public:
		/*
		 * @pre imported BoxOfAnything.h.
		 * @post builds a StackOfAnything<T> object and sets initial values.
		 */
		StackOfAnything();

		/*
		 * @pre StackOfAnything<T> object required.
		 * @post Deletes all the boxes on the stack, then deletes the stack.
		 */
		~StackOfAnything();

		/*
		 * @pre StackOfAnything<T> object required.
		 * @post none.
		 * @return whether or not there is anything on the stack.
		 */
		bool isEmpty() const;

		/*
		 * @pre StackOfAnything<T> object required.
		 * @post none.
		 * @return gives the size of the stack.
		 */
		int size() const;

		/*
		 * @pre StackOfAnything<T> object required.
		 * @post Makes a new Box on top of the stack, and places 'value' of type T in it.
		 * @return none.
		 */
		void push(T value);

		/*
		 * @pre Requires a StackOfAnything<T> object with size > 0
		 * @post none.
		 * @return Gives the value stored in the top object in the stack.
		 * @special catches exceptions for empty stacks.
		 */
		T peek() const throw(std::runtime_error);

		/*
		 * @pre Requires a stackOfAnything<T> object with size > 0
		 * @post deletes the top box off the stack and adjusts stack variables accordingly.
		 * @return Gives back the value of type T from inside the top stack object.
		 * @special catches exceptions for empty stacks.
		 */
		T pop() throw(std::runtime_error);


		BoxOfAnything<T>* m_tempPtr;
		T m_temp;
};

#include "StackOfAnything.hpp"


#endif
