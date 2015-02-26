#include <iostream>
#include <string>
#include "BinarySearchTree.h"

int main(int argc, char* argv[]){

	BinarySearchTree<int>* tree = new BinarySearchTree<int>;
	BinarySearchTree<int> copy = BinarySearchTree<int>();

	if(argc > 1){
		std::cout << "Number of nodes to add: " << argc - 1 << "\n\n";
		std::cout << "Filling original array with " << argc - 1 << " values.\n";

		for(int i = 1; i < argc; i++){
			std::cout << "Adding " << std::atoi(argv[i]) << " to original tree.\n";
			tree -> add(std::atoi(argv[i]));
		}
	std::cout << std::endl;
	}

	bool exists = true;
	int choice = 0;
	bool cont = true;
	while(cont){
		std::cout << "Input a selection" << std::endl;
		std::cout << "1) Add more values to original tree" << std::endl;
		std::cout << "2) Copy the original tree" << std::endl;
		std::cout << "3) Delete the original tree (one time only)" << std::endl;
		std::cout << "4) Print original tree" << std::endl;
		std::cout << "5) Print copy" << std::endl;
		std::cout << "6) Search original tree" << std::endl;
		std::cout << "7) Search copy" << std::endl;
		std::cout << "8) Exit" << std::endl;
		std::cout << "Your choice: ";
		std::cin >> choice;

		switch(choice){
			case 1:
				std::cout << "Input a value to add to the original: ";
				std::cin >> choice;
				tree -> add(choice);
			break;
			case 2:
				copy = BinarySearchTree<int>(*tree);
			break;
			case 3:
				delete tree;
				exists = false;
			break;
			case 4:
				std::cout << "print order options:" << std::endl;
				std::cout << "0 - pre-order" << std::endl;
				std::cout << "1 - in-order" << std::endl;
				std::cout << "2 - post-order" << std::endl;
				std::cout << "Choice: ";
				std::cin >> choice;
				switch(choice){
					case 0:
						tree -> printTree(PRE_ORDER);
					break;
					case 1:
						tree -> printTree(IN_ORDER);
					break;
					case 2:
						tree -> printTree(POST_ORDER);
					break;
					default:
						std::cout << "Invalid choice. Please give valid input.\n";
				}
			break;
			case 5:
				std::cout << "print order options:" << std::endl;
				std::cout << "0 - pre-order" << std::endl;
				std::cout << "1 - in-order" << std::endl;
				std::cout << "2 - post-order" << std::endl;
				std::cout << "Choice: ";
				std::cin >> choice;
				switch(choice){
					case 0:
						copy.printTree(PRE_ORDER);
					break;
					case 1:
						copy.printTree(IN_ORDER);
					break;
					case 2:
						copy.printTree(POST_ORDER);
					break;
					default:
						std::cout << "Invalid choice. Please give valid input.\n";
				}
			break;
			case 6:
				std::cout << "Enter a value to find: ";
				std::cin >> choice;
				tree -> search(choice);
			break;
			case 7:
				std::cout << "Enter a value to find: ";
				std::cin >> choice;
				copy.search(choice);
			break;
			case 8:
				cont = false;
			break;
			default:
				cont = false;
		}
	}

	std::cout << "Exiting...\n";
	if(exists){
		delete tree;
	}
	return 0;
}
