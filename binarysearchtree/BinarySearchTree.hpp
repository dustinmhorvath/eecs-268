#include <iostream>

template <typename T>
BinarySearchTree<T>::BinarySearchTree(){
	m_root = nullptr;
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& other){
	if(other.m_root == nullptr){
		m_root = nullptr;
	}
	else{
		m_root = new Node<T>(*(other.m_root));
	}
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree(){
	deleteTree(m_root);
}

template <typename T>
void BinarySearchTree<T>::add(T value){
	if(m_root == nullptr){
		m_root = new Node<T>();
		m_root -> setValue(value);
	}
	else{
		add(value, m_root);
	}
}

template <typename T>
void BinarySearchTree<T>::printTree(Order order){

}


template <typename T>
Node<T>* BinarySearchTree<T>::search(T value){
	return search(value, m_root);
}

template <typename T>
void BinarySearchTree<T>::add(T value, Node<T>* subtree){
	if(subtree == nullptr){
		subtree = new Node<T>();
		subtree -> setValue(value);
	}
	else if(value < subtree -> getValue()){
		add(value, subtree -> getLeft());
	}
	else if(value > subtree -> getValue()){
		add(value, subtree -> getRight());
	}
	else{
		std::cout << "Error. There is no room to add the value." << std::endl;
	}
}

template <typename T>
void BinarySearchTree<T>::deleteTree(Node<T>* subTree){
	if(subTree -> getLeft() != nullptr){
		deleteTree(subTree -> getLeft());
	}
	if(subTree -> getRight() != nullptr){
		deleteTree(subTree -> getRight());
	}
	delete m_root;
}

template <typename T>
Node<T>* BinarySearchTree<T>::search(T value, Node<T>* subtree){
	if(subtree == nullptr){
		std:: cout << "The value is not in the tree." << std::endl;
		return subtree;
	}
	if(subtree -> getValue() == value){
		return subtree;
	}
	else if(value < subtree -> getValue()){
		search(value, subtree -> getLeft());
	}
	else if(value > subtree -> getValue()){
		search(value, subtree -> getRight());
	}
}
