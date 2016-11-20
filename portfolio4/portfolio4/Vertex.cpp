#include "Vertex.h"


Vertex::Vertex(int n)
{
	//verticies.resize(n);
	//adjacencyList.resize(n);
	for (size_t i = 0; i < n; i++) {
		verticies.push_back(new Vertex(i+1, n));
	}
}

Vertex::Vertex(int id, int x)
{
	indegree = 0;
	topNum = 0;
	vertexId = id;
	path = nullptr;
	known = false;
	distance = 0;
	adjacencyList;
	weightVector;
}


void Vertex::neighbors(int v,  int w, int weight)
{
	
	verticies[v - 1]->adjacencyList.push_back(verticies[w - 1]);	// Add to w to v's adjacencyList
	verticies[v - 1]->weightVector.push_back(weight); // Add weight, iterators of adjacencyList and weightVector makes pairs of edges. Since we need to topsort (otherwise i would have just made an edge list)
	verticies[w - 1]->incrementIndegree();	// Increment the indegree of w vertex.
}

void Vertex::topSort()
{
	int counter = 0;
	std::queue<Vertex*> queue;

	for (size_t i = 0; i < verticies.size(); i++) {
		if (verticies[i]->getIndegree() == 0)
			queue.push(verticies[i]);
	}
	while (!queue.empty())
	{
		Vertex* v = queue.front();
		queue.pop();
		
		v->setTopNum(++counter);
		for (size_t i = 0; i < v->adjacencyList.size(); i++ )
		{
			v->adjacencyList[i]->decrementIndegree();
			if (v->adjacencyList[i]->getIndegree() == 0)
			{
				queue.push(v->adjacencyList[i]);
			}
		}
	}
	if (counter != verticies.size())
		std::cout << "Cant Top Sort fam" << std::endl;
}


int Vertex::findNewVertexOfIndegreeZero()
{
	for (size_t i = 0; i < verticies.size(); i++) {
		if (verticies[i]->getIndegree() == 0)
		{
			return i;
		}
	}
}

void Vertex::printGraph()
{
	for (size_t i = 0; i < verticies.size(); i++) {
		for (size_t j = 0; j < verticies[i]->adjacencyList.size(); j++) {
			std::cout << verticies[i]->getId() << " goes to " << verticies[i]->adjacencyList[j]->vertexId << std::endl;
		}
	}
}

void Vertex::printTopSort()
{
	std::cout << "Top Sort" << std::endl;
	for (size_t i = 0; i < verticies.size(); i++)
	{
		std::cout << verticies[i]->getTopNum() << std::endl;
	}
}

Vertex::~Vertex()
{
}

int Vertex::getId()
{
	return vertexId;
}

bool Vertex::getKnown()
{
	return known;
}

double Vertex::getInf()
{
	return distance;
}

void Vertex::incrementIndegree()
{
	indegree++;
}

void Vertex::decrementIndegree()
{
	indegree--;
}

int Vertex::getIndegree()
{
	return indegree;
}

void Vertex::setTopNum(int num)
{
	topNum = num;
}

int Vertex::getTopNum()
{
	return topNum;
}
