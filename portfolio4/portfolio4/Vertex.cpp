#include "Vertex.h"

Vertex::Vertex(int id, int x)
{
	indegree = 0;
	topNum = 0;
	vertexId = id;
	path = nullptr;
	known = false;
	distance = inf;
	adjacencyList;
	weightVector;
}

Vertex::~Vertex()
{
}

void Vertex::incrementIndegree()
{
	indegree++;
}

void Vertex::decrementIndegree()
{
	indegree--;
}
