#include <iostream>
#include <random>

#ifndef SORTS_H
#define SORTS_H

template <typename T> class Sorts{
public:

	/*
	/@pre Takes in an array of numerical sortable items, and array size.
	/@post sorts the array in ascending order using bubblesort.
	/@return none.
	*/
	static void bubbleSort(T arr[], int size);


	/*
	/@pre Takes in an array of numerical sortable items, and array size.
	/@post sorts the array in ascending order using bogosort.
	/@return none.
	*/
	static void bogoSort(T arr[], int size);


	/*
	/@pre Takes in an array of numerical sortable items, and array size.
	/@post sorts the array in ascending order using insertionsort.
	/@return none.
	*/
	static void insertionSort(T arr[], int size);


	/*
	/@pre Takes in an array of numerical sortable items, and array size.
	/@post Calls quickSortRec with the median flag set to false.
	/@return none.
	*/
	static void quickSort(T arr[], int size);


	/*
	/@pre Takes in an array of numerical sortable items, and array size.
	/@post Calls quickSortRec with the median flag set to true.
	/@return none.
	*/
	static void quickSortMedian(T arr[], int size);


	/*
	/@pre Takes in an array of numerical sortable items, and array size.
	/@post sorts the array in ascending order using selectionsort.
	/@return none.
	*/
	static void selectionSort(T arr[], int size);


	/*
	/@pre Takes in an array of numerical sortable items, and array size.
	/@post None.
	/@return Goes through the array, and returns a bool whether or not it is in ascending order.
	*/
	static bool isSorted(T arr[], int size);


	/*
	/@pre Takes in an array of numerical sortable items, and array size.
	/@post sorts the array in ascending order using selectionsort.
	/@return none.
	*/
	static void mergeSort(T arr[], int size);

private:

	/*
	/@note Helper function to mergeSort.
	/@pre Called by mergeSort.
	/@post none.
	/@return Gives back single sorted array from 2 input sorted arrays.
	*/
	static void merge(T* left, T* right, int sizeLeft, int sizeRight);


	/*
	/@pre takes in an array of numerical sortables and array size.
	/@post sorts the array in ascending order using quickSort.
	/@return none.
	*/
	static void quickSortRec(T arr[], int first, int last, bool median);


	/*
	/@pre takes in an array of numerical sortables and array size.
	/@post selects the median index, and swaps its value with the value in the last index.
	/@return none
	*/
	static void setMedianPivot(T arr[], int first, int last);


	/*
	/@pre takes in an array of numerical sortables.
	/@post places the value at the last index within the array such that
	/ lesser values are to its left, and greater values to its right.
	/@return index of the pivot.
	*/
	static int partition(T arr[], int first, int last, bool median);

	/*
	/@pre takes in an array.
	/@post shuffles its members.
	/@return none.
	*/
	static void shuffle(T arr[], int size);
};

#include "Sorts.hpp"

#endif
