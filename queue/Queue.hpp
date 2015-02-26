/*
/Dustin Horvath
/10/6/14
/Queue.hpp class file
/Implements methods for Queue class, used for building a stack implementation
*/

#include "Queue.h"
#include "BoxOfAnything.h"


template <typename T>
Queue<T>::Queue(){
	m_front = nullptr;
	m_back = nullptr;
	m_length = 0;
}


template <typename T>
Queue<T>::~Queue(){
	while(!isEmpty()){
		Queue<T>::dequeue();
	}
}

template <typename T>
bool Queue<T>::isEmpty() const{
	if(m_front == nullptr){
		return true;
	}
	else{
		return false;
	}
}

template <typename T>
void Queue<T>::enqueue(const T newEntry){
	BoxOfAnything<T>* tempPtr = new BoxOfAnything<T>(newEntry);
	tempPtr -> BoxOfAnything<T>::setPrevious(nullptr);
	if(isEmpty()){
		m_front = tempPtr;
	}
	else{
	m_back -> BoxOfAnything<T>::setPrevious(tempPtr);
	}
	m_back = tempPtr;
	m_length++;
}


template <typename T>
T Queue<T>::dequeue() throw(PreconditionViolationException){
	BoxOfAnything<T>* tempPtr = nullptr;
	if(isEmpty()){
		throw(PreconditionViolationException("Cannot dequeue empty queue."));
	}
	else{
		tempPtr = m_front;
		m_front = m_front -> BoxOfAnything<T>::getPrevious();
		return tempPtr -> BoxOfAnything<T>::getValue();
		delete tempPtr;
		m_length--;
	}
}



template <typename T>
T Queue<T>::peekFront() const throw(PreconditionViolationException){
	if(m_length == 0){
		throw(PreconditionViolationException("Do you want to throw empty stack exceptions? Because this is how you throw empty stack exceptions."));
	}
	else{
	return (m_front -> BoxOfAnything<T>::getValue());
	}
}


template <typename T>
int Queue<T>::size() const{
	return m_length;
}

template <typename T>
void Queue<T>::print() const{
	BoxOfAnything<T>* tempPtr = nullptr;
	if(!isEmpty()){
		std::cout << m_front -> BoxOfAnything<T>::getValue();
		tempPtr = m_front -> getPrevious();
		while(tempPtr != nullptr){
			std::cout << ",";
			std::cout << (tempPtr -> BoxOfAnything<T>::getValue());
			tempPtr = tempPtr -> getPrevious();
		}
	}
	else{
		std::cout << "Queue Empty" << std::endl;

	}
}

template <typename T>
bool Queue<T>::operator< (const QueueInterface<T>& rhs) const{
	if(m_length < rhs.m_length){
		return true;
	}
	else return false;

}

template <typename T>
bool Queue<T>::operator > (const QueueInterface<T>& rhs) const{
	if(m_length > rhs.m_length){
		return true;
	}
	else return false;
}


template <typename T>
bool Queue<T>::operator >= (const QueueInterface<T>& rhs) const{
	if(m_length >= rhs.m_length){
		return true;
	}
	else return false;
}

template <typename T>
bool Queue<T>::operator <= (const QueueInterface<T>& rhs) const{
	if(m_length <= rhs.m_length){
		return true;
	}
	else return false;
}

template <typename T>
bool Queue<T>::operator == (const QueueInterface<T>& rhs) const{
	if(m_length == rhs.m_length){
		return true;
	}
	else return false;
}

template <typename T>
bool Queue<T>::operator != (const QueueInterface<T>& rhs) const{
	if(m_length != rhs.m_length){
		return true;
	}
	else return false;
}


