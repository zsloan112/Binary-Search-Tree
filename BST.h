#ifndef BST_H
#define BST_H
#include "TNode.h"


class BST{
public:
	friend class tNode;

	BST();
	~BST();
	void inOrder(tNode*);
	void preOrder(tNode*);
	void postOrder(tNode*);
	void bstInsert(tNode*);
	void bstDelete(tNode*, tNode*);
	tNode* bstSearch(tNode*,int);
	tNode* CreateNode(int value);

private:
	
	tNode *root;

	tNode* Maximum(tNode*);
	tNode* Minimum(tNode*);
	tNode* Successor(tNode*);
	tNode* Predeccessor(tNode*);
	


};

#endif