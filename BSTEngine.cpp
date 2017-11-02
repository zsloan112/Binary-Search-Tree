#include <iostream>
#include "BST.h"
#include "TNode.h"

using namespace std;

int main(){

	BST tree;
	tNode* root;
	tNode* newNode;
	int selection;
	int nodeCount = 0;
	while (selection != 4){
		
		cout << "1. Insert Element into Binary Search Tree" << endl;
		cout << "2. Delete Element from Binary Search Tree" << endl;
		cout << "3. Print Elemets of Binary Search Tree   " << endl;
		cout << "4. Exit Program                          " << endl;
		cout << "-----------------------------------------" << endl;
		cout << "Selection: ";
		cin >> selection;

		if(selection == 1){
			int newNodeVal;
			
			if(nodeCount == 0){

				cout << "Please enter the value if the new node: ";
				cin >> newNodeVal;
				root = tree.CreateNode(newNodeVal);
				tree.bstInsert(root);
				nodeCount++;
			}else{
				cout << "Please enter the value of the new node: ";
				cin >> newNodeVal;
				tNode *searchNode = tree.bstSearch(root, newNodeVal);
				if(searchNode == NULL){
					newNode = tree.CreateNode(newNodeVal);
					tree.bstInsert(newNode);
				}else{
					cout << "Value is already in the tree! Please insert another value!" << endl;
				}
				
			}
			cout << endl;

		}else if(selection == 2){
			int searchVal;
			cout << "Enter a value to remove: ";
			cin >> searchVal;

			tNode *delNode = tree.bstSearch(root, searchVal);
			if(delNode == NULL){
				cout << "The element you are trying to delete does not exist in the Binary Tree!" << endl;
				cout << endl;
			}else{
				tree.bstDelete(root, delNode);
			}
		}
		else if(selection == 3){
			cout << endl;
			cout << "Binary Tree Values" << endl;
			cout << "------------------" << endl;
			cout << "In Order: ";
			tree.inOrder(root);
			cout << endl << "Pre Order: ";
			tree.preOrder(root);
			cout << endl << "Post Order: ";
			tree.postOrder(root);
			cout << endl << endl;
		}
	}
}