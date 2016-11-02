#include "BallsAndBins.h"

int main()
{
	BallsAndBins bin1(100022);

	for (size_t i = 0; i < 10; i++)
	{
		std::cout << "Uden power of 2 choises: ";
		
		bin1.throwBalls();
		bin1.maxBallsInBin();
		bin1.emptyBins();

		std::cout << "Med power of 2 choises: ";
		bin1.throwBallsPOTC();
		bin1.maxBallsInBin();
		bin1.emptyBins();
		std::cout << std::endl;
	}
}