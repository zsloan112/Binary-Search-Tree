#include "TNode.h"
#include <iostream>

using namespace std;

tNode::tNode(const int &value){
	nodeValue = value;
	left = NULL;
	right = NULL;
	parent = NULL;
}

void tNode::printNode(tNode *node){
	cout << node->nodeValue;
}
