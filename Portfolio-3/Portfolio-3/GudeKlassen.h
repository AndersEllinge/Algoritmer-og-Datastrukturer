#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>

class GudeKlassen
{
public:
	GudeKlassen();
	GudeKlassen(int n, int b);

	/*
	Give an O(N^2) algorithm to solve this problem. Returns with 1 if solved and prints the sum, otherwise returns 0.
	*/
	int exercise753a(int k);

	/*
	Give an O(NlogN) algorithm to solve this problem. Returns with 1 if solved and prints the sum, otherwise returns 0.
	*/
	int exercise753b(int k);

	
	void exercise744();

	/*
	Prints the content of inputVector
	*/
	void printInputVector();

	~GudeKlassen();


private:
	
	std::vector<int> inputVector;

	/*
	Random number generator, range is 0 to 99, can be changed.
	*/
	int randomNumber();

	int randomNumberTrueFalse(); // range is 0 to 1;

};

