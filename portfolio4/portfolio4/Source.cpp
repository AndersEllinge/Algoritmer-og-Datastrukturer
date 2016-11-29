#include "Vertex.h"
#include "Graph.h"

int main()
{
	Graph graph(7); // Making the same graph as the one in the book, figure 9.20 page 412, except that the direction of the edge from v1 to v3 is changed, so we can top sort aswell
	graph.addEdge(1, 2, 2); //v0 -> vn, cost
	graph.addEdge(1, 3, 4); //v0 -> vn, cost
	graph.addEdge(1, 4, 1); //v0 -> vn, cost
	graph.addEdge(2, 4, 3); //v0 -> vn, cost
	graph.addEdge(2, 5, 10); //v0 -> vn, cost
	graph.addEdge(3, 6, 5); //v0 -> vn, cost
	graph.addEdge(4, 3, 2); //v0 -> vn, cost
	graph.addEdge(4, 6, 8); //v0 -> vn, cost
	graph.addEdge(4, 7, 4); //v0 -> vn, cost
	graph.addEdge(4, 5, 2); //v0 -> vn, cost
	graph.addEdge(5, 7, 6); //v0 -> vn, cost
	graph.addEdge(7, 6, 1); //v0 -> vn, cost

	graph.topSort(); 
	graph.printTopSort();std::cout << std::endl;
	
	graph.Dijkstra(1); // create dijkstra graph with base vertex 1
	
	std::cout << "Dijkstra path is: " << std::endl;
	graph.printPath(6); // print path to vertex 6
	std::cout << std::endl;
	
	// Feel free to change the path to print or the edges to test the program

	return 1;
}