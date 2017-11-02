#ifndef TNODE_H
#define TNODE_H
#include <cstddef>

class tNode{
private:
	int nodeValue;
	tNode *left, *right, *parent;

public:
	friend class BST;
	tNode(const int &value);
	void printNode(tNode *node);
};

#endif