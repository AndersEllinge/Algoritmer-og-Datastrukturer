#include "Vertex.h"

int main()
{
	Vertex verticies(7);

	verticies.neighbors(1, 2, 2); //v0 -> vn
	verticies.neighbors(1, 3, 1); //v0 -> vn
	verticies.neighbors(1, 4, 4); //v0 -> vn
	verticies.neighbors(2, 4, 3); //v0 -> vn
	verticies.neighbors(2, 5, 10); //v0 -> vn
	verticies.neighbors(3, 6, 5); //v0 -> vn
	verticies.neighbors(4, 3, 2); //v0 -> vn
	verticies.neighbors(4, 6, 8); //v0 -> vn
	verticies.neighbors(4, 7, 4); //v0 -> vn
	verticies.neighbors(5, 4, 2); //v0 -> vn
	verticies.neighbors(5, 7, 6); //v0 -> vn
	verticies.neighbors(7, 6, 1); //v0 -> vn
	
	


	verticies.printGraph();

	verticies.topSort();
	verticies.printTopSort();


	return 1;
}