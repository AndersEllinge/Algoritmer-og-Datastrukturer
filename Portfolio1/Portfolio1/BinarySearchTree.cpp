#include "BinarySearchTree.h"

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

int BinarySearchTree::getNodes() 				// Public function, it uses the private function getNodes(BinaryNode *t, int& temp).
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

int BinarySearchTree::getLeaves() 
{
	if (isEmpty())									
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

int BinarySearchTree::getFullNodes()
{
	if (isEmpty())
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


void BinarySearchTree::printTree(BinaryNode *t) const
{
	if (t != nullptr)
	{
		cout << "Printing left:" << endl;
		printTree(t->left);
		cout << t->element << endl;
		cout << "Printing right:" << endl;
		printTree(t->right);
	}
}


int BinarySearchTree::getNodes(BinaryNode *t, int& temp) 
{
	if (t != nullptr)
	{
		getNodes(t->left,temp);
		getNodes(t->right,temp);
		temp++;		
	}
	return temp;
}

int BinarySearchTree::getLeaves(BinaryNode * t, int & temp) 
{
	if (t != nullptr)
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

int BinarySearchTree::getFullNodes(BinaryNode * t, int & temp)
{
	if (t != nullptr)
	{
		getFullNodes(t->left, temp);
		getFullNodes(t->right, temp);
		if (t->left == nullptr || t->right == nullptr)
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