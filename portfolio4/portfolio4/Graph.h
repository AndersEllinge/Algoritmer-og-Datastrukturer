#pragma once
#include "Vertex.h"

class Graph
{
public:
	Graph();
	
	/*
	Create a graph with n verticies
	*/
	Graph(int n);

	/*
	Add and edges to the graph
	*/
	void addEdge(int v, int w, int weight); 
	
	/*
	Print the graph
	*/
	void printGraph();
	
	/*
	Function to top sort the graph
	*/
	void topSort();

	/*
	Print the top sorted graph
	*/
	void printTopSort();

	/*
	Create dijkstra graph with base vertex
	*/
	void Dijkstra(int vertex);

	/*
	Print path from base to any connected point on the dijkstra graph
	*/
	void printPath(int vertex);

	~Graph();



private:
	Vertex* smallestUnknownDistanceVertex(); // Function find smallest unknown vertex distance
	bool isUnknownVertex(); // returns true if there is a unknown vertex
	std::vector<Vertex*> verticies; // Vector holding all the verticies in the graph
	double inf = std::numeric_limits<double>::infinity(); // Defining infinity
};

