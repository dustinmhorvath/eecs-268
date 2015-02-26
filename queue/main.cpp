#include <iostream>
#include <string>
#include "PreconditionViolationException.h"
#include "QueueInterface.h"
#include "BoxOfAnything.h"
#include "Queue.h"

void printMenu(){
	std::cout << "Select an action:" << std::endl;
	std::cout << "1) Get in check out lane 1" << std::endl;
 	std::cout << "2) Get in check out lane 2" << std::endl;
	std::cout << "3) See who is at the front of lane 1" << std::endl;
	std::cout << "4) See who is at the front of lane 2" << std::endl;
	std::cout << "5) Print all names in lane 1" << std::endl;
	std::cout << "6) Print all names in lane 2" << std::endl;
	std::cout << "7) Check out a customer in lane 1" << std::endl;
	std::cout << "8) Check out a customer in lane 2" << std::endl;
	std::cout << "9) Compare Queues" << std::endl;
	std::cout << "10) Quit" << std::endl;
	std::cout << "Enter choice: ";
}

template <typename T>
void compareQueues(const QueueInterface<T>& q1, const QueueInterface<T>& q2)
{
	std::cout 	<< "\nComparison of queues:\n"
			<< "lane 1 < lane 2: " <<  (q1 <  q2) 	<< "\n"
			<< "lane 1 > lane 2: " <<  (q1 >  q2) 	<< "\n"
			<< "lane 1 >= lane 2: " << (q1 >= q2) 	<< "\n"
			<< "lane 1 <= lane 2: " << (q1 <= q2) 	<< "\n"
			<< "lane 1 == lane 2: " << (q1 == q2) 	<< "\n"
			<< "lane 1 != lane 2: " << (q1 != q2) 	<< "\n";
}

int main(){
	int choice = 0;
	bool cont = true;
	std::string tempS = "";

	QueueInterface<std::string>* lane1 = new Queue<std::string>();
	QueueInterface<std::string>* lane2 = new Queue<std::string>();

	while(cont){
		printMenu();
		std::cin >> choice;
		switch(choice){
			case 1:
				std::cout << "Who is going in lane 1?:" << std::endl;
				std::cin >> tempS;
				lane1 -> enqueue(tempS);
			break;
			case 2:
				std::cout << "Who is going in lane 2?:" << std::endl;
				std::cin >> tempS;
				lane2 -> enqueue(tempS);
			break;
			case 3:
				try{
					std::cout << (lane1 -> peekFront()) << " is at the front of the lane 1." << std::endl;
				}
				catch(PreconditionViolationException e){
					std::cout << e.what() << std::endl;
				}
			break;
			case 4:
				try{
					std::cout << (lane2 -> peekFront()) << " is at the front of the lane 2." << std::endl;
				}
				catch(PreconditionViolationException e){
					std::cout << e.what() << std::endl;
				}
			break;
			case 5:
				lane1 -> print();
				std::cout << std::endl;
			break;
			case 6:
				lane2 -> print();
				std::cout << std::endl;
			break;
			case 7:
				try{
					std::cout << (lane1 -> peekFront()) << " checked out from lane 1." << std::endl;
					lane1 -> dequeue();
				}
				catch(PreconditionViolationException e){
					std::cout << e.what() << std::endl;
				}
			break;
			case 8:
				try{
				std::cout << (lane2 -> peekFront()) << " checked out from lane 2." << std::endl;
				lane2 -> dequeue();
				}
				catch(PreconditionViolationException e){
					std::cout << e.what() << std::endl;
				}
			break;
			case 9:
				compareQueues(*lane1,*lane2);
				std::cout << std::endl;
			break;
			case 10:
				cont = false;
			break;
		}
		std::cout << std::endl;
	}

	std::cout << "Program ending" << std::endl;
	return 0;
}

