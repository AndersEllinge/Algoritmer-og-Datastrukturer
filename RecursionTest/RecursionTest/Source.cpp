
#include <iostream>


int count = 0;

int f(int x) {
	if (x == 0)
	{
		return 0;
	}
	else
	{
		return 2 * f(x - 1) + x*x;
	}
}

int fibo(int x) {
	if (x == 0 || x == 1)
		return 1;
	else {
		count++;
		return fibo(x - 1) + fibo(x - 2);
	}
}

void printOut(int n) {
	if (n >= 10)
		printOut(n / 10);
	std::cout << n % 10 << std::endl;
}

int main() {
	std::cout << fibo(38) << std::endl;
	std::cout << count << std::endl;
	
	//printOut(i);

	std::cout << 456 << std::endl;
	printOut(456);
}

