//A dice rolling program!
#include <iostream>
#include <random>
#include <string>


int dicethrow(int i) //PRNG + counter function
{
	int z;

	if (i <= 1) { //Throwing a 0 or 1 sided dice acts as a 0 or 1 counter 
		z = i;
	}
// The code of interest
	if (i > 1) {
		std::random_device rd; // obtain a random number from hardware
		std::mt19937 eng(rd()); // seed the generator
		std::uniform_int_distribution<> distr(1, i); //  range
		z = distr(eng);
	}
// End of code of interest
	return z;
}


void term_roll_loop(){
	std::string b("y");       //I don't know best practices for this sort of thing in Cpp
	int a(0);
	int value(0);
	int numthrows(0);

	do {
		std::cout << "Input dice sides:";
		std::cin >> a;
		++numthrows;
		value = value + dicethrow(a);
		std::cout << "Throw another die? y/n\n";
		std::cin >> b;

	} while (b == "y");

	std::cout << "Your total rolled:" << value << "\n";
	std::cout << "Your total number of dice throws:" << numthrows << "\n";
	
}




int main()
{
	
	term_roll_loop();
	
	system("pause");

	return 0;
}
