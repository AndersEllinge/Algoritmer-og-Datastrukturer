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

	std::cout << "Printing in-order tree: " << std::endl;
	T.printTree();

	std::cout << "Printing pre-order tree: " << std::endl;
	T.preOrderPrintTree();

	std::cout << "Printing post-order tree: " << std::endl;
	T.postOrderPrintTree();

	std::cout << "Printing level-order tree: " << std::endl;
	T.levelOrderPrintTree();
	
	std::cout << "There are " << T.getNodes() << " nodes in the tree." <<std::endl;
	std::cout << "There are " << T.getLeaves() << " leaves in the tree" << std::endl;
	std::cout << "There are " << T.getFullNodes() << " full nodes in the tree" << std::endl;
}
