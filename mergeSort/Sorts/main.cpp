/*
/Dustin Horvath
/10/27/14
/Main for Sorts program. Takes in an input file and uses bubbleSort and mergeSort on it.
/Also outputs to a file called sorted.txt to verify output.
*/

#include "Sorts.h"
#include <string>
#include <chrono>
#include <iostream>
#include <fstream>

int main(int argc, char** argv){
if(argc > 1){
	std::string inputfile = argv[1];
	std::ifstream instream(inputfile);
	std::ofstream outstream("sorted.txt");


	int size;
	instream >> size;

	double* a1 = new double[size];
	double* a2 = new double[size];

	for(int i = 0; i < size; i++){
		instream >> a1[i];
		a2[i] = a1[i];
	}

	Sorts<double> mySort;

	//Declaring chrono components
	std::chrono::system_clock::time_point start;
	std::chrono::system_clock::time_point end;
	std::chrono::duration<double> elapsed;

	//Begin bubbleSort block
	std::cout << "Starting bubble sort.\n";
	start = std::chrono::system_clock::now();

	mySort.Sorts<double>::bubbleSort(a1, size);

	end = std::chrono::system_clock::now();
	elapsed = (end - start);
	std::cout << "BubbleSort completed in " << elapsed.count() << " seconds\n";
	//End bubbleSort block

	//Begin mergeSort block
	std::cout << "Starting merge sort.\n";
	start = std::chrono::system_clock::now();

	a2 = mySort.Sorts<double>::mergeSort(a2, size);

	end = std::chrono::system_clock::now();
	elapsed = (end - start);
	std::cout << "MergeSort completed in " << elapsed.count() << " seconds\n";

	//For testing
	for(int i = 0; i < size; i++){
		outstream << i << " " << a2[i] << "\n";
	}

delete a1;
delete a2;

instream.close();
outstream.close();
}//ends if(argc > 1)
else{
	std::cout << "This program requires an input file of return" << std::endl;
	std::cout << "delimited integers, or doubles. Please rerun" << std::endl;
	std::cout << "with valid input" << std::endl;
}

return 0;
}
