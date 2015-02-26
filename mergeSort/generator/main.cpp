/*
/	Dustin Horvath
/	main.cpp for generator program. Creates output file of
/	ints or doubles, \n delimited. Run ./RNG for help.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <ctime>


int main(int argc, char** argv){



	if(argc < 5){
		std::cout << "Use RNG with the following arguments:" << std::endl << std::endl;

		std::cout << "./RNG filename count min max" << std::endl;
		std::cout << "filename is the ouput file name" << std::endl;
		std::cout << "count is the amount of random numbers to place in the file" << std::endl;
		std::cout << "min is the low end of the range of random numbers" << std::endl;
		std::cout << "max is the high end (non-inclusive) of the range of random numbers" << std::endl;
	}
	else{
		std::string filepath = argv[1];
		std::ofstream outFile(filepath);
		int start = std::stoi(argv[3]);
		int stop = std::stoi(argv[4]);
		int num = std::stoi(argv[2]);
		outFile << argv[2] << "\n";
		std::default_random_engine generator(time(nullptr));
		std::uniform_int_distribution<int> distribution(start,stop-1);
		int rand = 0;
		for(int i = 0; i < num; i++){
			rand = distribution(generator);
			outFile << rand << "\n";
		}
	}


ofstream.close();

return 0;
}
