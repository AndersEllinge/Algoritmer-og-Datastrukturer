#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include "SFML/Graphics.hpp"

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

	/*suppose you have an array of N elemetns containing only two distinct keys, true and false. 
	Give na O(N) algorithm to rearrange the list so that all false elemetns precede the true elements. 
	You may use only constant extra space.*/
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

