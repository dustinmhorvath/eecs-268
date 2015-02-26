/**
*	@file QueueInterface.h
*	@author YOUR NAME HERE
*	@date 2014.04.02
*/

#ifndef QUEUE_INTERFACE_H
#define QUEUE_INTERFACE_H

#include <string>
#include "PreconditionViolationException.h"

template <typename T>
class QueueInterface
{
	public:
	/**
	*	Not pure virtual, but allows for polymorphism of sub classes
	*	@post Deletes all entries in the queue
	*/
	virtual ~QueueInterface() {}

	/**
	*	@return True if the queue is empty, false otherwise
	*/
	virtual bool isEmpty() const = 0;

	/** 
	*	@post Entry added to back of queue
	*	@param newEntry The object to be added as a new entry
	*/
	virtual void enqueue(const T newEntry) = 0;


	/** 
	*	@pre The queue is not empty
	*	@post Front of the queue is removed
	*	@return The value of the entry at the front of the queue
	*	@throws PreconditionViolationException
	*/
	virtual T dequeue() throw(PreconditionViolationException) = 0;

	/** 
	*	@pre The queue is not empty
	*	@post The value at the front is returned and the queue is unchanged
	*	@return The value of the entry at the front of the queue
	*	@throws PreconditionViolationException
	*/
	virtual T peekFront() const  throw(PreconditionViolationException) = 0;

	/** 
	*	@post The queue is unchanged
	*	@return The size is returned
	*/
	virtual int size() const = 0;	

	/**
	*	@pre none
	*	@post prints the contents of the queue or "Queue Empty" if it is empty
	*	@return none
	*/
	virtual void print() const = 0;

};

#endif
