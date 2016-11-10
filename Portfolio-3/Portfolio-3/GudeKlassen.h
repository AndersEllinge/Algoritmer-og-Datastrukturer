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
	GudeKlassen(int n, int b, int c);

	/*
	Give an O(N^2) algorithm to solve this problem. Returns with 1 if solved and prints the sum, otherwise returns 0.
	*/
	int exercise753a(int k);

	/*
	Give an O(NlogN) algorithm to solve this problem. Returns with 1 if solved and prints the sum, otherwise returns 0.
	*/
	int exercise753b(int k);

	
	void exercise744();

	int exercise738(int k);

	/*
	Prints the content of inputVector
	*/
	void printInputVector();
	void printCoordinates();
	void printSlopes();
	void printFourCollinearGroups();

	void drawShit();
	~GudeKlassen();


private:
	
	std::vector<int> inputVector;
	std::vector<std::vector<float>> fourOrMoreCollinear; // This vector holds any groups of lines with 4 or more collinear points. i.e. {slope, intersection, index coordinate1, index coordinate2 .. index coordinatenN }
	std::vector<std::vector<float>> coordinates; // Every coordinate also constains the slope of a line to every other coordinate. i.e. {x,y,a1,a2,a3,..,an}

	void removeDublicateCoordinates();
	void findCollinearPoints();
	int determineSlopes(size_t i);
	float determineIntersection(int i, int j);
	void findCollinearGroups(); 


	

	/*
	Random number generator, range is 0 to 99, can be changed.
	*/
	int randomNumber();
	int randomNumberTrueFalse(); // range is 0 to 1;

};

