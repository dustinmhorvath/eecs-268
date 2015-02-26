#include "Node.h"


#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

enum Order{
	PRE_ORDER,
	IN_ORDER,
	POST_ORDER
};


template <typename T>
class BinarySearchTree{
public:

	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree<T>& other);
	~BinarySearchTree();
	void add(T value);
	void printTree(Order order);
	Node<T>* search(T value);

private:
	void add(T value, Node<T>* subtree);
	void deleteTree(Node<T>* subTree);
	Node<T>* search(T value, Node<T>* subtree);


	Node<T>* m_root;

};

#include "BinarySearchTree.hpp"


#endif
