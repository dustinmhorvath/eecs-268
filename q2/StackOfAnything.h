/** 	@file StackOfAnything.h
*	@author John Gibbons
*	@date 2014.02.02
*       Update: 2014.09.10
*		-Throwing of std::runtime_error added to pop() and peek()
*/


#ifndef STACKOFANYTHING_H
#define STACKOFANYTHING_H

#include <stdexcept>
#include "StackableAnything.h"


template <typename T> 
class StackOfAnything
{	
	public:

	/** @pre none
	*   @post creates an empty stack capable of storing StackableAnything<T>
	*   @return an empty stack
	*/
	StackOfAnything();

	/** @pre none
	*   @post deletes the entire stack
	*/
	~StackOfAnything();

	/** @pre none
	*   @post none
	*   @return returns true if size == 0, false otherwise
	*/
	bool isEmpty();

	/** @pre value is a valid T
	*   @post the value is put into a StackableAnything and put at the top of the stack
	*/
	void push(T value);


	/** @pre the stack is not empty
	*   @post none
	*   @return value, T, from top of stack. 
	*   @throws std::runtime_error when a peek is performed on an empty stack
	*/
	T peek() const throw (std::runtime_error);


	/** @pre the stack is not empty
	*   @post the top of the stack is removed and its value returned
	*   @return the value, T, from the top of the stack
	*   @throws std::runtime_error when a pop is performed on an empty stack
	*/
	T pop() throw (std::runtime_error);

	/** @pre none
	*   @post none
	*   @return returns the value of size
	*/
	int size() const;

	private:
	
	StackableAnything<T>* m_top;
	int m_size;	
};

#include "StackOfAnything.hpp"

#endif

