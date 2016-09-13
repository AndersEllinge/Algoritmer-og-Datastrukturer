#pragma once
#include <array>
using namespace std;

class CircularQueue
{
public:
	CircularQueue();
	~CircularQueue();
	bool empty();
	bool full();
	void enQueue(int aValue);
	int deQueue();
	void print();

private:
	array<int, 10> arr;
	int front;
	int end;
	int size;
	int elements;
};