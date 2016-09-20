
#include "BinarySearchTree.h"

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
	T.insert(18);
	T.insert(12);
	T.insert(11);
	T.insert(14);
	T.insert(13);


	std::cout << T.getNodes() << std::endl;

	std::cout << T.contains(7) << std::endl;



	//T.printTree();
}
