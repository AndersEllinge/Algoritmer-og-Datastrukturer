#include "BinarySearchTree.h"
#include <vector>

BinarySearchTree::BinarySearchTree() : root{ nullptr }
{
}


BinarySearchTree::BinarySearchTree(const BinarySearchTree & rhs) : root{ nullptr }
{
	root = clone(rhs.root);
}


BinarySearchTree::BinarySearchTree(BinarySearchTree && rhs) : root{ rhs.root }
{
	rhs.root = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
	makeEmpty();
}

const int & BinarySearchTree::findMin() const
{
	if (isEmpty())
		return -1;
	return findMin(root)->element;
}


const int & BinarySearchTree::findMax() const
{
	if (isEmpty())
		return -1;
	return findMax(root)->element;
}

bool BinarySearchTree::contains(const int & x) const
{
	return contains(x, root);
}

bool BinarySearchTree::isEmpty() const
{
	return root == nullptr;
}

void BinarySearchTree::printTree() const
{
	if (isEmpty())
		cout << "Empty tree" << endl;
	else
		printTree(root);
}

void BinarySearchTree::preOrderPrintTree()			// Public function, it uses the private function preOrderPrintTree(root).
{
	if (isEmpty())
		cout << "Empty tree" << endl;
	else
		preOrderPrintTree(root);
}

void BinarySearchTree::postOrderPrintTree()			// Public function, it uses the private function postOrderPrintTree(root).
{
	if (isEmpty())
		cout << "Empty tree" << endl;
	else
		postOrderPrintTree(root);
}

void BinarySearchTree::levelOrderPrintTree()		// Public function, it uses the private function levelOrderPrintTree(root).
{
	if (isEmpty())
		cout << "Empty tree" << endl;
	else
		levelOrderPrintTree(root);
}

int BinarySearchTree::getNodes() 					// Public function, it uses the private function getNodes(BinaryNode *t, int& temp).
{													// It works as a temp place holder for the recursive calls in above function.
	if (isEmpty())									// Otherwise a global variable would be needed to keep track of the amount of recursive calls.
	{
		cout << "Empty tree" << endl;
		return 0;
	}
	else
	{
		int temp = 0;
		getNodes(root, temp);
		return temp;
	}
}

int BinarySearchTree::getLeaves()					// Public function, it uses the private function getLeaves(BinaryNode *t, int& temp).
{													// It works as a temp place holder for the recursive calls in above function.
	if (isEmpty())									// Otherwise a global variable would be needed to keep track of the amount of recursive calls.		
	{
		cout << "Empty tree" << endl;
		return 0;
	}
	else
	{
		int temp = 0;
		getLeaves(root, temp);
		return temp;
	}
}

int BinarySearchTree::getFullNodes()				// Public function, it uses the private function getFullNodes(BinaryNode *t, int& temp).
{													// It works as a temp place holder for the recursive calls in above function.
	if (isEmpty())									// Otherwise a global variable would be needed to keep track of the amount of recursive calls.
	{
		cout << "Empty tree" << endl;
		return 0;
	}
	else
	{
		int temp = 0;
		getFullNodes(root, temp);
		return temp;
	}
}

void BinarySearchTree::makeEmpty()
{
	makeEmpty(root);
}


void BinarySearchTree::insert(const int & x)
{
	insert(x, root);
}

void BinarySearchTree::insert(int && x)
{
	insert(std::move(x), root);
}

void BinarySearchTree::remove(const int & x)
{
	remove(x, root);
}

void BinarySearchTree::insert(const int & x, BinaryNode * & t)
{
	if (t == nullptr)
		t = new BinaryNode{ x, nullptr, nullptr };
	else if (x < t->element)
		insert(x, t->left);
	else if (t->element < x)
		insert(x, t->right);
	else
		;  // Duplicate; do nothing
}


void BinarySearchTree::insert(int && x, BinaryNode * & t)
{
	if (t == nullptr)
		t = new BinaryNode{ std::move(x), nullptr, nullptr };
	else if (x < t->element)
		insert(std::move(x), t->left);
	else if (t->element < x)
		insert(std::move(x), t->right);
	else
		;  // Duplicate; do nothing
}

void BinarySearchTree::remove(const int & x, BinaryNode * & t)
{
	if (t == nullptr)
		return;   // Item not found; do nothing
	if (x < t->element)
		remove(x, t->left);
	else if (t->element < x)
		remove(x, t->right);
	else if (t->left != nullptr && t->right != nullptr) // Two children
	{
		t->element = findMin(t->right)->element;
		remove(t->element, t->right);
	}
	else
	{
		BinaryNode *oldNode = t;
		t = (t->left != nullptr) ? t->left : t->right;
		delete oldNode;
	}
}

BinaryNode * BinarySearchTree::findMin(BinaryNode *t) const
{
	if (t == nullptr)
		return nullptr;
	if (t->left == nullptr)
		return t;
	return findMin(t->left);
}

BinaryNode * BinarySearchTree::findMax(BinaryNode *t) const
{
	if (t != nullptr)
		while (t->right != nullptr)
			t = t->right;
	return t;
}

bool BinarySearchTree::contains(const int & x, BinaryNode *t) const
{
	if (t == nullptr)
		return false;
	else if (x < t->element)
		return contains(x, t->left);
	else if (t->element < x)
		return contains(x, t->right);
	else
		return true;    // Match
}

void BinarySearchTree::makeEmpty(BinaryNode * & t)
{
	if (t != nullptr)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t = nullptr;
}


void BinarySearchTree::printTree(BinaryNode *t) const			// This is in-order traversal
{																// Because the element is checked here:
	if (t != nullptr)
	{
		printTree(t->left);
		cout << t->element << endl;								// <-------- in between recursive calling. Therefor in-order
		printTree(t->right);
	}
}

void BinarySearchTree::preOrderPrintTree(BinaryNode * t)		// This is pre-order traversal
{																// Because the element is checked here:
	if (t != nullptr)
	{
		cout << t->element << endl;								// <-------- before recursive calling. Therefor pre-order
		preOrderPrintTree(t->left);
		preOrderPrintTree(t->right);
	}
}

void BinarySearchTree::postOrderPrintTree(BinaryNode * t)		// This is post-order traversal
{																// Because the element is checked here:
	if (t != nullptr)
	{
		postOrderPrintTree(t->left);
		postOrderPrintTree(t->right);
		cout << t->element << endl;								// <-------- after recursive calling. Therefor post-order
	}
}

void BinarySearchTree::levelOrderPrintTree(BinaryNode * t)		// I could not see a way to do this recursively, so I decided to use a queue
{																// I add the nodes once to a queue starting at the root, then I process the queue as a FIFO buffer.
																// when processing a node I check if the node has children, if it has, then they are added to the queue	
	if (t != nullptr)											// when the queue is empty, all nodes have been inspected.
	{															
		std::vector<BinaryNode*> queue;							// Making the queue

		queue.push_back(t);										// Root is the first node in the queue

		while (!queue.empty()) {								// Stop when all nodes in the queue has been processed
			
			std::cout << queue.front()->element << std::endl;	// print - or do what ever you want with the element
			
			if (queue.front()->left != nullptr) {				// check for left child
				queue.push_back(queue.front()->left);			// add child to be processed
			}
			if(queue.front()->right != nullptr) {				// check for right child
				queue.push_back(queue.front()->right);			// add child to be processed
			}
			queue.erase(queue.begin());							// current node (allways first element in the queue) processed, dont need it anymore
		}
	}

}

int BinarySearchTree::getNodes(BinaryNode *t, int& temp)		// After a node has been visited, temp is incremented, when temp is returned
{																// then temp should be amount of nodes in the tree.
	if (t != nullptr)
	{
		getNodes(t->left,temp);
		getNodes(t->right,temp);
		temp++;		
	}
	return temp;
}

int BinarySearchTree::getLeaves(BinaryNode * t, int & temp)		// After a node has been visited, the node is inspected
{																// if node has no children, then its a leaf and temp is incremented.			
	if (t != nullptr)											// When temp is returned, it should be the amount of leaves in the tree.
	{
		getLeaves(t->left, temp);
		getLeaves(t->right, temp);
		if (t->left == nullptr && t->right == nullptr)
		{
			temp++;
		}
	}
	return temp;
}

int BinarySearchTree::getFullNodes(BinaryNode * t, int & temp)	// After a node has been visited, the node is inspected
{																// if node has either 1 or 2 children, then its a full node and temp is incremented.
	if (t != nullptr)											// When temp is returned, it should be the amount of full nodes in the tree.
	{
		getFullNodes(t->left, temp);
		getFullNodes(t->right, temp);
		if (t->left != nullptr || t->right != nullptr)
		{
			temp++;
		}
	}

	return temp;
}




BinaryNode * BinarySearchTree::clone(BinaryNode *t) const
{
	if (t == nullptr)
		return nullptr;
	else
		return new BinaryNode{ t->element, clone(t->left), clone(t->right) };
}