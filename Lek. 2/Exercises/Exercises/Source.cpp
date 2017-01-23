
#include<iostream>
#include<string>
#include<stack>

#include "CircularQueue.h"

using namespace std;

bool balPar(string text);

std::stack<char> myStack;

int main()
{
	CircularQueue firstQueue;
	for (size_t i = 0; i < 10; i++)
	{
		firstQueue.enQueue(i);
	}
	firstQueue.deQueue();
	firstQueue.enQueue(50);
	

	firstQueue.print();

	//std::cout << balPar(")(") << std::endl;

}

bool balPar(string text)
{
	for (size_t i = 0; i < text.size(); i++)
	{
		if (text[i] == ')')
		{
			if (myStack.empty() == true)
				return false;
			myStack.pop();
		}
		else 
			if (text[i] == '(')
				myStack.push(text[i]);
	}

	if (myStack.empty())
		return true;
	else
		return false;
}



