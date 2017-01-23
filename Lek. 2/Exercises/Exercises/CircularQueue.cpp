#include "CircularQueue.h"
#include <iostream>


CircularQueue::CircularQueue()
{
	front=0;
	end=0;
	size=10;
	elements=0;
}

CircularQueue::~CircularQueue()
{
}

bool CircularQueue::empty()
{
	if (elements == 0)
		return true;
	return false;
}

bool CircularQueue::full()
{
	if (elements == size)
		return true;
	return false;
}

void CircularQueue::enQueue(int aValue)
{
	if (full())
	{
		std::cout << "Queue is full" << std::endl;
		return;
	}
	else
	{
		arr[end] = aValue;
		if (end == 9)
		{
			end = 0;
		}
		else
		{
			end++;
		}
		elements++;
	}
}

int CircularQueue::deQueue()
{
	int temp;
	if (empty())
	{
		std::cout << "Queue is empty" << std::endl;
		return 0;
	}
	else
	{
		temp = arr[front];
		if (front == 9)
		{
			front = 0;
		}
		else
		{
			front++;
		}
		elements--;
		return temp;
	}
}

void CircularQueue::print()
{
	if (empty())
	{
		std::cout << "Queue is empty" << std::endl;
		return;
	}
	if (end > front)
		for (size_t i = front; i < end; i++)
		{
			std::cout << "Array element " << i << " is : " << arr[i] << std::endl;
		}
	else
	{
		for (size_t i = front; i <= size-1 ; i++)
		{
			std::cout << "Array element " << i << " is : " << arr[i] << std::endl;
		}
		for (size_t i = 0; i < end; i++)
		{
			std::cout << "Array element " << i << " is : " << arr[i] << std::endl;
		}
	}
}


