#pragma once
#include<string>
#include<iostream>
#include<stack>

using namespace std;

struct BinarySearchTree {
	int item;
	BinarySearchTree* left, * right;
	BinarySearchTree(int item)
	{
		this->item = item;
		left = NULL;
		right = NULL;
	}
};

class BST
{
	BinarySearchTree* root;
	void deletenodes(BinarySearchTree* root);
	void PreOrderTraversal(BinarySearchTree* node);
	void InOrderTraversal(BinarySearchTree* node);
	void PostOrderTraversal(BinarySearchTree* node);
	void splay(stack<BinarySearchTree*>& S);

public:
	BST() { root = NULL; }
	~BST() { deletenodes(root); }
	void insert(int item);
	bool find(int key);
	void PreOrder();
	void InOrder();
	void PostOrder();
	BinarySearchTree* rightRotate(BinarySearchTree* x);
	BinarySearchTree* leftRotate(BinarySearchTree* x); 
	
	void splayLeft(BinarySearchTree* x, BinarySearchTree* p, BinarySearchTree* g);
	void splayRight(BinarySearchTree* x, BinarySearchTree* p, BinarySearchTree* g);
};


