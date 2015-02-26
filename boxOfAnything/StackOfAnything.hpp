/*
 * StackOfAnything.cpp
 *
 *  Created on: Sep 15, 2014
 *      Author: dhorvath
 */

#include "BoxOfAnything.h"
#include "StackOfAnything.h"
#include <iostream>
#include <string>

template <typename T>
StackOfAnything<T>::StackOfAnything(){
	m_top = nullptr;
	m_size = 0;
	m_tempPtr = nullptr;
	m_temp = 0;
}

template <typename T>
StackOfAnything<T>::~StackOfAnything(){
	while(m_top != nullptr){
		pop();
	}
}

template <typename T>
bool StackOfAnything<T>::isEmpty() const{
	if(m_size == 0){
		return true;
	}
	else return false;
}

template <typename T>
int StackOfAnything<T>::size() const{
	return m_size;
}

template <typename T>
void StackOfAnything<T>::push(T value){
	m_tempPtr = m_top;
	m_top = new BoxOfAnything<T>(value);
	m_top -> BoxOfAnything<T>::setPrevious(m_tempPtr);
	m_size++;
}

template <typename T>
T StackOfAnything<T>::peek() const throw(std::runtime_error){
	if(isEmpty()){
		throw(std::runtime_error("Peek attempted on empty stack"));
	}
	return m_top -> BoxOfAnything<T>::getValue();
}

template <typename T>
T StackOfAnything<T>::pop() throw(std::runtime_error){
	if(isEmpty()){
		throw(std::runtime_error("Pop attempted on empty stack"));
	}
	m_temp = m_top -> BoxOfAnything<T>::getValue();
	m_tempPtr = m_top -> BoxOfAnything<T>::getPrevious();

	delete m_top;

	m_top = m_tempPtr;
	m_tempPtr = nullptr;
	m_size--;

	return m_temp;
}



