
#ifndef NODE_H
#define NODE_H

template <typename T> class Node{
public:
	Node();
	Node(const Node<T>& other);
	T getValue();
	Node<T>* getLeft();
	Node<T>* getRight();
	void setValue(T value);
	void setLeft(Node<T>* left);
	void setRight(Node<T>* right);


private:
	T m_value;
	Node<T>* m_left;
	Node<T>* m_right;
};

#include "Node.hpp"

#endif
