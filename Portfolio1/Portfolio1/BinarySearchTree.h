#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <iostream>
#include <algorithm>
using namespace std;

class BinaryNode
{
public:
	int element;
	BinaryNode *left;
	BinaryNode *right;

	BinaryNode(const int & theElement, BinaryNode *lt, BinaryNode *rt)
		: element{ theElement }, left{ lt }, right{ rt } { }

	BinaryNode(int && theElement, BinaryNode *lt, BinaryNode *rt)
		: element{ std::move(theElement) }, left{ lt }, right{ rt } { }
};


class BinarySearchTree
{
public:
	BinarySearchTree(); 
	BinarySearchTree(const BinarySearchTree & rhs); 
	BinarySearchTree(BinarySearchTree && rhs); 
	~BinarySearchTree();
	
	const int & findMin() const;
	const int & findMax() const;
	bool contains(const int & x) const;
	bool isEmpty() const;
	void printTree() const;

	void preOrderPrintTree();
	void postOrderPrintTree();
	void levelOrderPrintTree();

	int getNodes();
	int getLeaves();
	int getFullNodes();
	
	void makeEmpty();
	void insert(const int & x);
	void insert(int && x);
	void remove(const int & x);
	
private:
	BinaryNode *root;

	void insert(const int & x, BinaryNode * & t);
	void insert(int && x, BinaryNode * & t);
	void remove(const int & x, BinaryNode * & t);
	BinaryNode * findMin(BinaryNode *t) const;
	BinaryNode * findMax(BinaryNode *t) const;
	
	bool contains(const int & x, BinaryNode *t) const;
	
	void makeEmpty(BinaryNode * & t);
	void printTree(BinaryNode *t) const;

	void preOrderPrintTree(BinaryNode* t);
	void postOrderPrintTree(BinaryNode* t);
	void levelOrderPrintTree(BinaryNode* t);


	int getNodes(BinaryNode *t, int& temp);
	int getLeaves(BinaryNode *t, int& temp);
	int getFullNodes(BinaryNode *t, int& temp);


	BinaryNode * clone(BinaryNode *t) const;
	
};

#endif
