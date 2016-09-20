
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

	std::cout << T.contains(7) << std::endl;

	T.printTree();
}
