#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <queue>

class Vertex
{
public:
	Vertex(int id, int x);
	Vertex(int n);
	void neighbors(int v, int w, int weight);

	void topSort();

	int findNewVertexOfIndegreeZero();

	void printGraph();
	void printTopSort();

	~Vertex();


private:
	int getId();
	bool getKnown();
	double getInf();
	void incrementIndegree();
	void decrementIndegree();
	int getIndegree();
	void setTopNum(int num);
	int getTopNum();

	std::vector<Vertex*> verticies;
	std::vector<Vertex*> adjacencyList;
	std::vector<int> weightVector;
	//std::queue<Vertex*> topSortedVerticies;

	int topNum; // top sorted number
	int indegree;
	Vertex* path;
	int vertexId;
	bool known;
	int distance;
	double inf = std::numeric_limits<double>::infinity();
};

