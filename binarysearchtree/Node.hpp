#include "Node.h"
#include <iostream>

template <typename T>
Node<T>::Node(){
	m_left = nullptr;
	m_right = nullptr;
}

template <typename T>
Node<T>::Node(const Node<T>& other){
	m_value = other.m_value;

	if(other.m_left != nullptr){
		m_left = new Node<T>(*(other.m_left));
	}
	if(other.m_right != nullptr){
		m_right = new Node(*(other.m_right));
	}
		
}

template <typename T>
T Node<T>::getValue(){
	return m_value;
}

template <typename T>
Node<T>* Node<T>::getLeft(){
	return m_left;
}

template <typename T>
Node<T>* Node<T>::getRight(){
	return m_right;
}

template <typename T>
void Node<T>::setValue(T value){
	m_value = value;
}

template <typename T>
void Node<T>::setLeft(Node<T>* left){
	m_left = left;
}

template <typename T>
void Node<T>::setRight(Node<T>* right){
	m_right = right;
}


