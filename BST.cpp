#include "BST.h"
#include "TNode.h"
#include <iostream>

using namespace std;

/*
	Public Member functions of BST
		- BST(): Initialize root as NULL
		- ~BST(): Clean all nodes in BST
		- void inOrder(tNode*): Print BST inOrder
		- void preOrder(tNode*): Print BST preOrder
		- void postOrder(tNode*): Print BST postOrder
		- void bstInsert(tnode*, tNode*): Insert new node into BST (Must be discrete)
		- void bstDelete(tNode*, tNode*): Delete node from BST
		- tNode* bstSearch(tNode*, tNode*): Search for a node in BST
*/


BST::BST(){
	root = NULL;
}

BST::~BST(){

}
	
void BST::inOrder(tNode *node){
	if(node != NULL){
		inOrder(node->left);
		cout << node->nodeValue << " ";
		inOrder(node->right);
	}
}

void BST::preOrder(tNode *node){
	if(node != NULL){
		cout << node->nodeValue << " ";
		preOrder(node->left);
		preOrder(node->right);
	}
}

void BST::postOrder(tNode *node){
	if(node != NULL){
		postOrder(node->left);
		postOrder(node->right);
		cout << node->nodeValue << " ";
	}
}


//Edit to enter only discrete values
void BST::bstInsert(tNode *newNode){
	tNode *x, *y;
	y = NULL;
	x = root;

	while(x != NULL){
		y = x;
		if(newNode->nodeValue < x->nodeValue)
			x = x->left;
		else
			x = x->right;
	}

	newNode->parent = y;

	if(y == NULL)
		root = newNode;
	else if(newNode->nodeValue < y->nodeValue){
		y->left = newNode;
	}else{
		y->right = newNode;
	}
}

void BST::bstDelete(tNode *node, tNode *z){
	tNode *y, *x;

	if(z->left == NULL || z->right == NULL){
		y = z;
	}
	else{
		y = Successor(z);
	}

	if(y->left != NULL){
		x = y->left;
	}else{
		x = y->right;
	}

	if(x != NULL)
		x->parent = y->parent;

	if(y->parent == NULL)
		node->parent = x;
	else if(y == y->parent->left){
		y->parent->left = x;
	}
	else{
		y->parent->right = x;
	}

	if(y != z){
		z->nodeValue = y->nodeValue;
	}

	delete y;
}

tNode* BST::bstSearch(tNode* root,int searchValue){
	tNode *y = root;

	while(y != NULL && searchValue != y->nodeValue){
		if(searchValue < y->nodeValue)
			y = y->left;
		else{
			y = y->right;
		}
	}
	return y;
}


/*
	Private Member Functions of BST
		- tNode* Maximum(tNode*): Returns the right most node in the BST
		- tNode* Minimum(tNode*): Returns the left most node in the BST
		- tNode* Successor(tNode*): Returns smallest value that is greater than node
	 	- tNode* Predeccessor(tNode*): Returns largest value that is smaller than node
		- tNode* CreateNode(int value): Create a new node
*/

tNode* BST::Maximum(tNode* root){
	tNode *y = root;

	while(y->right != NULL){
		y = y->right;
	}
	return y;
}

tNode* BST::Minimum(tNode* root){
	tNode *y = root;

	while(y->left != NULL){
		y = y->left;
	}
	return y;
}

tNode* BST::Successor(tNode* node){
	if(node->right != NULL){
		return Minimum(node->right);
	}else{
		tNode *y = node->parent;
		while(y != NULL && node == y->right){
			node = y;
			y = y->parent;
		}
		return y;
	}
}

tNode* BST::Predeccessor(tNode* node){
	if(node->left != NULL){
		return Maximum(node->left);
	}else{
		tNode *y = node->parent;
		while(y != NULL && node == y->left){
			node = y;
			y = y->parent;
		}
		return y;
	}
}


tNode* BST::CreateNode(int value){
	tNode *newNode = new tNode(value);
	return newNode;
}

