/*
/Dustin Horvath
/10/27/14
/Main for Sorts program. Takes in an input file and uses bubbleSort and mergeSort on it.
/Also outputs to a file called sorted.txt to verify output.
*/

#include "Sorts.h"
#include "SortInfo.h"
#include <string>
#include <chrono>
#include <iostream>
#include <functional>
#include <cassert>
#include <climits>
#include <random>
#include <ctime>

template <typename T> double sortTimer(std::function<void(T[], int)> sort, T arr[], int size){
	std::chrono::system_clock::time_point start;
	std::chrono::system_clock::time_point end;
	std::chrono::duration<double> elapsed;

	start = std::chrono::system_clock::now();

	sort(arr, size);

	end = std::chrono::system_clock::now();
	elapsed = (end - start);

	return elapsed.count();
}

void sortTimingInfo(SortInfo<int>& sortInfo, double timeLimit){
	std::default_random_engine generator(time(nullptr));
	std::uniform_int_distribution<int> distribution(0,999);
	sortInfo.setCount(1);
	int timeElapsed = 0;
	int size = sortInfo.getCount();
	while(timeElapsed < timeLimit){
		size = sortInfo.getCount();
		int* tempArray = new int[size];
		for(int i = 0; i < sortInfo.getCount(); i++){
			tempArray[i] = distribution(generator);
		}
		timeElapsed = sortTimer(sortInfo.getSort(), tempArray, size);

		sortInfo.setCount(sortInfo.getCount() + 1);

		delete tempArray;
	}
	sortInfo.setCount(sortInfo.getCount() - 1);
}

double getRandomDouble(){
	int num = rand() % 100000;

	return (double)num;
}

double* randomDoubleArray(int size){
	double* array = new double[size];
	for(int i = 0; i < size; i++){
		array[i] = getRandomDouble();
	}
	return array;
}

double* addRandomDouble(double* arr, int size){
	double* newArr = new double[size + 1];
	for(int i = 0; i < size; i++){
		newArr[i] = arr[i];
	}
	newArr[size] = getRandomDouble();
	delete[] arr;
	return newArr;
}

int main(int argc, char** argv){
	srand (time(NULL)); //needed for rand(). I don't like it here, but that's the way it's gotsa be.
	SortInfo<double> sorts[] = {
					SortInfo<double>( Sorts<double>::bogoSort, "Bogo Sort"),
					SortInfo<double>( Sorts<double>::bubbleSort, "Bubble Sort"),
					SortInfo<double>( Sorts<double>::insertionSort, "Insertion Sort"),
					SortInfo<double>( Sorts<double>::selectionSort, "Selection Sort"),
					SortInfo<double>( Sorts<double>::mergeSort, "Merge Sort"),
					SortInfo<double>( Sorts<double>::quickSort, "Quick Sort"),
					SortInfo<double>( Sorts<double>::quickSortMedian, "Quick Sort (median)")
	};

	int numSorts = 7;
	int bogoSize = 5;

	std::cout << "\nWelcome to the sort program. Let's sort some numbers!\n";
	std::cout << "Generating a random array of " << bogoSize << " doubles.\n";
	double* bogoArr = randomDoubleArray(bogoSize);
	std::cout << "BogoSort will now attempt to sort " << bogoSize << " numbers. Wish it luck!\n";
	sorts[0].setTime(sortTimer<double>(Sorts<double>::bogoSort, bogoArr, bogoSize));
	delete[] bogoArr;

	std::cout << "BogoSort needed " << sorts[0].getTime() << " seconds to sort " << bogoSize << " numbers.\n\n";
	for(int i = 1; i < numSorts; i++){
		sorts[i].setCount(1);
		std::cout << "Starting " << sorts[i].getName() << ".\n";
		double* baseArray = randomDoubleArray(1);
		double* sortingArray = new double[1];
		sortingArray[0] = baseArray[0];
		while(sorts[i].getTime() < sorts[0].getTime()){
			sorts[i].setTime(sortTimer(sorts[i].getSort(), sortingArray, sorts[i].getCount()));
			baseArray = addRandomDouble(baseArray, sorts[i].getCount());
			sorts[i].setCount(sorts[i].getCount() + 1);
			delete[] sortingArray;
			sortingArray = new double[ sorts[i].getCount() ];
			for(int j = 0; j < sorts[i].getCount(); j++){
				sortingArray[j] = baseArray[j];
			}

//			std::cout << sorts[i].getCount() << " " << sorts[0].getTime() << " " << sorts[i].getTime() << "\n"; //FOR TESTING
		}
		sorts[i].setCount(sorts[i].getCount() - 1);
		std::cout << sorts[i].getName() << " complete.\n\n";
		delete[] sortingArray;
		delete[] baseArray;
	}
	std::cout << "In that same time, the following sorts were able to sort through...\n";
	for(int i = 1; i < numSorts; i++){
		std::cout << sorts[i].getName() << " sorted " << sorts[i].getCount() << " in " << sorts[i].getTime() << " seconds.\n";
	}

return 0;
}
