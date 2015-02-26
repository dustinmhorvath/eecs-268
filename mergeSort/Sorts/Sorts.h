#include <iostream>

#ifndef SORTS_H
#define SORTS_H


template <typename T> class Sorts{
public:
	/*
	/@pre Requires array argument
	/@post Sorts the array ascending
	/@return none
	*/
	void bubbleSort(T arr[], int size);

	/*
	/@pre Requires array argument
	/@post none
	/@return Gives back a [new] array, that's sorted.
	*/
	T* mergeSort(T arr[], int size);
private:

	/*
	/@note Helper function to mergeSort
	/@pre Called by mergeSort
	/@post none
	/@return Gives back single sorted array from 2 input sorted arrays
	*/
	T* merge(T* left, T* right, int sizeLeft, int sizeRight);

};

#include "Sorts.hpp"

#endif
