Animals: main.o CyberChicken.o Chicken.o Cow.o FarmAnimal.o AnimalPen.o
	g++ -g -std=c++0x main.o CyberChicken.o Chicken.o Cow.o FarmAnimal.o AnimalPen.o -o Animals

main.o: main.cpp CyberChicken.h Chicken.h Cow.h FarmAnimal.h AnimalPen.h StackOfAnything.h StackOfAnything.hpp BoxOfAnything.h BoxOfAnything.hpp
	g++ -g -std=c++0x -c main.cpp

CyberChicken.o: CyberChicken.h CyberChicken.cpp
	g++ -g -std=c++0x -c CyberChicken.cpp
Chicken.o: Chicken.h Chicken.cpp
	g++ -g -std=c++0x -c Chicken.cpp
Cow.o: Cow.h Cow.cpp
	g++ -g -std=c++0x -c Cow.cpp
FarmAnimal.o: FarmAnimal.h FarmAnimal.cpp
	g++ -g -std=c++0x -c FarmAnimal.cpp
AnimalPen.o: AnimalPen.h AnimalPen.cpp
	g++ -g -std=c++0x -c AnimalPen.cpp

clean: 
	rm *.o main
	clean done

