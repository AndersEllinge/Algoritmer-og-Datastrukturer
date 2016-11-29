#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <queue>

class Vertex
{
public:
	Vertex(int id, int x);

	void incrementIndegree();
	void decrementIndegree();

	~Vertex();
	
	// I could have made all these attributes private, but to be honest, there would be set and get function for them all so what is the point of setting them private
	std::vector<Vertex*> adjacencyList; // list of neighbors a vertex has
	std::vector<int> weightVector; // cost of the edges between a vertex and its neighbors
	int topNum;  // Index of the vertex when the graph is top sorted
	int indegree; // Indgree of the vertex
	Vertex* path; // Pointer to the next vertex in the dijkstra graph
	int vertexId; // An ID to identify a vertex, not really used in this project
	bool known; // Bool to determine wether the vertex is known or unknown in the dijkstra graph
	double distance; // The distance to the vertex

private:
	double inf = std::numeric_limits<double>::infinity();
	
};

