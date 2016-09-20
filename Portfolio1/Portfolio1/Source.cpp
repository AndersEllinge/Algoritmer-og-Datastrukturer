#include "BinarySearchTree.h"
#include <ctime>


int main()
{
		
	BinarySearchTree T;
	T.insert(6);
	T.insert(8);
	T.insert(2);
	T.insert(1);
	T.insert(4);
	T.insert(3);
	T.insert(16);

	T.printTree();
	
	std::cout << T.getNodes() << std::endl;
	std::cout << T.getLeaves() << std::endl;
	std::cout << T.getFullNodes() << std::endl;

	/*int start_s = clock();
	int stop_s = clock();
	cout << "time: " << (stop_s - start_s) / (double(CLOCKS_PER_SEC)) << endl;*/

	

	
	
	
}
