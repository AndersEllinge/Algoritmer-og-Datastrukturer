#include "GudeKlassen.h"


GudeKlassen::GudeKlassen()
{
}

GudeKlassen::GudeKlassen(int n, int b) // if b = 1, then we work with a bool vector.
{
	if (b) {		// generate b random true false statements
		inputVector.resize(n);
		for (size_t i = 0; i < n; i++)
		{
			inputVector[i] = randomNumberTrueFalse();		
		}
	}

	else {
		inputVector.resize(n);	// generate n random numbers
		for (size_t i = 0; i < n; i++)
		{
			inputVector[i] = randomNumber();
		}
	}
}

int GudeKlassen::exercise753a(int k)
{
	for (size_t i = 0; i < inputVector.size(); i++) {			// Nested for loop, this means the list is run through the list 2 times, which is N^2.
		for (size_t j = 0; j < inputVector.size(); j++) {
			if ((inputVector[i] + inputVector[j]) == k) {
				std::cout << "Exercise 753a found: " << std::endl;
				std::cout << inputVector[i] << " + " << inputVector[j] << " = " << k << std::endl;
				printInputVector(); std::cout << std::endl;
				return 1;
			}
		}
	}
	return 0;
}

int GudeKlassen::exercise753b(int k)
{
	std::sort(inputVector.begin(), inputVector.end());	// A standard C++ NlogN sort in ascending order.
	
	int left = 0;	// left index
	int right = inputVector.size()-1;	// right index

	while (left <= right) // Break criteria, indexes have met.
	{
		if ((inputVector[left] + inputVector[right]) == k) { // print and return 1 if a valid sum is found.
			std::cout << "Exercise 753b found: " << std::endl;
			std::cout << inputVector[left] << " + " << inputVector[right] << " = " << k << std::endl;
			printInputVector(); std::cout << std::endl;
			return 1;
		}
		if ((inputVector[left] + inputVector[right]) < k) // if the sum is less than k, then we increase the lowest value, which is an increment of the left index.
			left++;
		if ((inputVector[left] + inputVector[right]) > k) // if the sum is greater than k, then we decrease the highest value, which is a decrement of the right index.
			right--;
	}
	return 0;
}

void GudeKlassen::exercise744()
{
	int left = 0;	// left index
	int right = inputVector.size() - 1;	// right index

	while (left <= right) { // break crieria, indexes have met.
		if (inputVector[left] > inputVector[right]) // if left index is true and righ index is false, then swap 
			std::swap(inputVector[left], inputVector[right]);
		if (inputVector[left] == 0) // increment left index if its a false
			left++;
		if (inputVector[right] == 1) // decrement right index if its a true
			right--;
	}
}

void GudeKlassen::printInputVector()
{
	std::cout << "InputVector is: ";
	for (size_t i = 0; i < inputVector.size(); i++)
			std::cout << inputVector[i] << " ";
	std::cout << std::endl;
	std::cout << std::endl;
}

int GudeKlassen::randomNumber()
{
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 eng(rd()); // seed the generator
	std::uniform_int_distribution<> distr(0, 50); // define the range

	return distr(eng);
}

int GudeKlassen::randomNumberTrueFalse()
{
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 eng(rd()); // seed the generator
	std::uniform_int_distribution<> distr(0, 1); // define the range

	return distr(eng);
}

GudeKlassen::~GudeKlassen()
{
}
