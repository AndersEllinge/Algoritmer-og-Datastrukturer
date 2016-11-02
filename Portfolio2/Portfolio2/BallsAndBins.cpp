#include "BallsAndBins.h"

BallsAndBins::BallsAndBins()
{
}

BallsAndBins::BallsAndBins(int n)
{
	bins.resize(n, 0);
	balls = n;
}

void BallsAndBins::throwBalls()
{
	for (size_t i = 1; i <= balls; i++)
	{
		bins[randomNumber()]++;
	}
}

void BallsAndBins::throwBallsPOTC()
{
	int bin1;
	int bin2;
	for (size_t i = 1; i <= balls; i++)
	{
		bin1 = randomNumber();
		bin2 = randomNumber();
		if (bins[bin1] <= bins[bin2])
		{
			bins[bin1]++;
		}
		else
		{
			bins[bin2]++;
		}
	}
}

void BallsAndBins::maxBallsInBin()
{
	int tmp = 0;
	for (size_t i = 0; i < getN(); i++)
	{
		if (bins[i] > tmp)
		{
			tmp = bins[i];
		}
	}
	std::cout << "Max balls in a bin: " << tmp << std::endl;
}

void BallsAndBins::emptyBins()
{
	fill(bins.begin(), bins.end(), 0);
}

BallsAndBins::~BallsAndBins()
{
}

void BallsAndBins::printBins()
{
	for (size_t i = 0; i < bins.size(); i++)
	{
		std::cout << bins[i] << std::endl;
	}
}

int BallsAndBins::randomNumber()
{
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 eng(rd()); // seed the generator
	std::uniform_int_distribution<> distr(0, getN()-1); // define the range

	return distr(eng);
}

int BallsAndBins::getN()
{
	return bins.size();
}
