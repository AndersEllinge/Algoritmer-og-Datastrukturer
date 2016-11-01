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


	void throwBalls();
	void throwBallsPOTC();
	
	void maxBallsInBin();
	void emptyBins();

	void printBins();

int randomNumber();

private:
	
	int checkBin();
	int getN();


	std::vector<int> bins;
	int balls;
	//std::vector<std::vector<int>> balls;


};

