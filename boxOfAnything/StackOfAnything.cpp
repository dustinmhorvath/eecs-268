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

StackOfAnything::StackOfAnything(){
	m_top = nullptr;
	m_size = 0;
	m_tempPtr = nullptr;
	m_temp = 0;
}

StackOfAnything::~StackOfAnything(){
	while(m_top != nullptr){
		pop();
	}
}

bool StackOfAnything::isEmpty() const{
	if(m_size == 0){
		return true;
	}
	else return false;
}

int StackOfAnything::size() const{
	return m_size;
}

void StackOfAnything::push(T value){
	m_tempPtr = m_top;
	m_top = new BoxOfAnything();
	m_top -> BoxOfAnything::setValue(value);
	m_top -> BoxOfAnything::setPrevious(m_tempPtr);
	m_size = m_size + 1;
}

T StackOfAnything::peek(){
	if(isEmpty()){
		throw(std::runtime_error("Peek attempted on empty stack"));
	}
	return m_top -> BoxOfAnything::getValue();
}

T pop() throw(std::runtime_error){
	if(isEmpty()){
		throw(std::runtime_error("Pop attempted on empty stack"));
	}
	m_temp = m_top -> BoxOfAnything::getValue();
	m_tempPtr = m_top;
	delete m_top;
	m_top = m_tempPtr;
	m_size = m_size - 1;
	return m_temp;
}



