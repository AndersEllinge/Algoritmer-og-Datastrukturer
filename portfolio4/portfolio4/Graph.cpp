#include "Graph.h"



Graph::Graph()
{
}

Graph::Graph(int n)
{
	for (size_t i = 0; i < n; i++) {
		verticies.push_back(new Vertex(i + 1, n));
	}
}

void Graph::addEdge(int v, int w, int weight)
{
	verticies[v - 1]->adjacencyList.push_back(verticies[w - 1]);	// Add to w to v's adjacencyList
	verticies[v - 1]->weightVector.push_back(weight); // Add weight, vertex->adjacencyList[i] is a pointer to w and vertex->weightVector[i] is the weight from v to w, therfore addEdge(v,w,weight).
	verticies[w - 1]->incrementIndegree();	// Increment the indegree of w vertex.
}

void Graph::printGraph()
{
	for (size_t i = 0; i < verticies.size(); i++) {
		for (size_t j = 0; j < verticies[i]->adjacencyList.size(); j++) {
			std::cout << verticies[i]->vertexId << " goes to " << verticies[i]->adjacencyList[j]->vertexId << std::endl;
		}
	}
}

void Graph::topSort()
{
	int counter = 0; // This is a variable that keeps track of which index a vertex has in the Top Sort
	std::queue<Vertex*> queue; // queue to hold verticies with 0 indegree
	
	for (size_t i = 0; i < verticies.size(); i++) { // find all verticies with 0 indegree
		if (verticies[i]->indegree == 0)
			queue.push(verticies[i]);	// push back the verticies unto the queue
	}
	while (!queue.empty()) { // Keep going as long there are verticies with 0 indegree
		Vertex* v = queue.front(); // Look at the front element of the queue, the first vertex with indegree 0
		queue.pop(); // also pop it, dont need it in the queue anymore when we are done
			
		v->topNum = ++counter; // update the vertex topNum, which will be the number of the vertex in the Top Sort
		for (size_t i = 0; i < v->adjacencyList.size(); i++ ) // For every neighbor to the current vertex
		{
			v->adjacencyList[i]->decrementIndegree(); // Decrease the indgree of neighbor
			if (v->adjacencyList[i]->indegree == 0) // If the indgree of the neighbor is 0, then add it to the queue
			{
				queue.push(v->adjacencyList[i]); // Adding a neighbor to the queue
			}
		}
	}
	if (counter != verticies.size()) // If the counter variable and the number of verticies does not add up, then we its an cyclic graph.
		std::cout << "Cant Top Sort fam" << std::endl;
}

void Graph::printTopSort()
{
	std::cout << "Top Sort" << std::endl;
	for (size_t i = 0; i < verticies.size(); i++) {
		std::cout << "Vertex: " << verticies[i]->topNum<< std::endl;
	}
}

void Graph::Dijkstra(int vertex)
{
	for (size_t i = 0; i < verticies.size(); i++) { // Initialize the verticies with inf distance and make them unknown
		verticies[i]->distance = inf;
		verticies[i]->known = false;
	}	
	
	Vertex* v = verticies[vertex-1]; // This is the start vertex
	v->distance = 0; // This distance is zero, because its the start vertex

	while (isUnknownVertex()) // repeat until no unknown vertex is left.
	{	
		v = smallestUnknownDistanceVertex(); // Return the pointer to the unknown vertex with the smallest distance

		if (v == nullptr || v->distance == inf) { // When there is no new smallesUnknownDistanceVertex, or if the distance is inf,
			return;								  // then we are done when the Dijkstra graph.	
		}

		v->known = true;	// We now know this vertex
		
		for (size_t i = 0; i < v->adjacencyList.size(); i++) { // For every neighbor
			if (!v->adjacencyList[i]->known) {	// If a neighbor is unknown
				int cvw = v->weightVector[i];   // cost of edge from v to unknown neighbor w, weightVector holds the costs of v to w1, w2, w3...wn  

				if (v->distance + cvw < v->adjacencyList[i]->distance) { // If we have a cheaper cost then we update the dijkstra graph
					v->adjacencyList[i]->distance = v->distance + cvw ; // update the distance to the cheaper distance
					v->adjacencyList[i]->path = v;	// New path to take, since its cheaper
				}
			}
		}
	}
}

void Graph::printPath(int vertex)
{
	if (verticies[vertex-1]->path != nullptr) // V1 is element verticies[0], therfore verticies[vertex-1], also the base of this recursive function
	{										  // is when verticies is pointing at a nullptr
		printPath(verticies[vertex-1]->path->vertexId); // recursive printPath the Vertex that vertex is pointing at.
		std::cout << " to " ;
	}
	std::cout << verticies[vertex-1]->vertexId;
}

Graph::~Graph()
{
}

Vertex* Graph::smallestUnknownDistanceVertex()
{
	Vertex* temp = nullptr; // Temp initialized to point at nothing, because if there is no new unknown vertex, then we return this nullptr
	for (size_t i = 0; i < verticies.size(); i++) { // Look through all the verticies
		if (!verticies[i]->known) { // If we find an unknown
			if (temp != nullptr) { // If temp is pointing at a vertex, when we need to check if the new vertex has a smaller distance
				if (temp->distance > verticies[i]->distance) 
					temp = verticies[i]; // update temp, if new vertex is smaller than temp
			}
			else {
				temp = verticies[i]; // First time we find a unknown vertex
			}
		}
	}
	return temp; // return the smallest unknown distance vertex
}

bool Graph::isUnknownVertex()
{
	for (size_t i = 0; i < verticies.size(); i++) { // Look through verticies
		if (!verticies[i]->known) // If there is an unknown vertex, then return true
			return true;
	}
	return false;
}
