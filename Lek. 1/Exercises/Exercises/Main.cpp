#include<iostream>
#include<string>
#include<math.h>

int getNaturalSum(int n);
int isPrime(int n, int x);

int main()
{
	std::cout << getNaturalSum(4) << std::endl;
	//std::cout << isPrime(81, 81) << std::endl;
}

int getNaturalSum(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else
	{	
		std::cout << n << std::endl;
		return getNaturalSum(n - 1) + n;
	}	
}

int isPrime(int n, int x)		//start from 2 then go up to sqrt(n).
{								//look up table.
	if (n == x)
	{
		x = x - 1;
	}					

	if (x == 1)
	{
		return 1;
	}

	else
	{
		if (n % x == 0)
		{
			return 0;
		}
		else
		{
			return isPrime(n, x - 1);
		}
	}
}

