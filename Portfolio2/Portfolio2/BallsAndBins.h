#pragma once
#include <vector>
#include <iostream>
#include <cstdlib>
#include <random>

class BallsAndBins
{
public:
	BallsAndBins();
	BallsAndBins(int n);
	~BallsAndBins();

	/*
	This function just throws balls randomly
	*/
	void throwBalls();

	/*
	This fucntion throws balls with the power of 2 choises
	*/
	void throwBallsPOTC();
	
	/*
	This function finds the bin with the most balls in it
	*/
	void maxBallsInBin();

	/*
	This function empties the bins
	*/
	void emptyBins();

	/*
	This function prints the number of balls in the bins
	*/
	void printBins();

	

private:

	/*
	This function return a psudo random number of up to 32-bit integer, the size is determined by the number of bins.
	*/
	int randomNumber();

	int getN();

	std::vector<int> bins;
	int balls;
};

