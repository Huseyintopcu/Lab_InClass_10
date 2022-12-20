#include "BST.h"
void BST::deletenodes(BinarySearchTree* node)
{
	if (node == NULL) return;
	deletenodes(node->left);
	deletenodes(node->right);
	delete node;
	root = NULL;
}
void BST::insert(int item)
{
	stack<BinarySearchTree*> S;
	BinarySearchTree* q = NULL;
	BinarySearchTree* p = root;

	while (p)
	{
		S.push(p);
		q = p;
		if (item == p->item)
		{
			throw std::exception("Duplicate Key !\n");
			return;
		}
		else if (item < p->item)
		{
			p = p->left;
		}
		else
		{
			p = p->right;
		}
	}
	BinarySearchTree* node = new BinarySearchTree(item);
	if (root == NULL)
	{
		root = node;
	}
	else if (item < q->item)
	{
		q->left = node;
	}
	else
	{
		q->right = node;
	}
	splay(S);
}

BinarySearchTree* BST::find(int key)
{
	stack<BinarySearchTree*> S;
	BinarySearchTree* p = root;

	while (p) {
		S.push(p);
		if (key == p->item) {
			splay(S);
			return p;
		}
		if (key < p->item) p = p->left;
		else			  p = p->right;
	}
	return NULL;
}



void BST::PreOrderTraversal(BinarySearchTree* root)
{
	if (root == NULL) return;
	cout << root->item << " ";
	PreOrderTraversal(root->left);
	PreOrderTraversal(root->right);
}
void BST::InOrderTraversal(BinarySearchTree* root)
{
	if (root == NULL) return;
	InOrderTraversal(root->left);
	cout << root->item << " ";
	InOrderTraversal(root->right);
}
void BST::PostOrderTraversal(BinarySearchTree* root)
{
	if (root == NULL) return;
	PostOrderTraversal(root->left);
	PostOrderTraversal(root->right);
	cout << root->item << " ";
}


void BST::splay(stack<BinarySearchTree*>& S)
{
	while (S.size() > 1)
	{
		BinarySearchTree* x = S.top(); S.pop();
		BinarySearchTree* p = S.top(); S.pop();
		BinarySearchTree* g = NULL;
		if (!S.empty()) { g = S.top(); S.pop(); }
		BinarySearchTree* pg = NULL;
		if (!S.empty()) pg = S.top();


		if (g == NULL) {
			if (x == p->left) {

				p->left = x->right;
				x->right = p;
			}
			else {

				p->right = x->left;
				x->left = p;
			}

			root = x;
			break;
		}
		else {

			if (p == g->left) {
				splayLeft(x, p, g);
			}
			else {
				splayRight(x, p, g);
			}

			if (pg == NULL) { root = x; break; }
			else if (g == pg->left) pg->left = x;
			else pg->right = x;

			S.push(x);

		}
	}
	
	}

	void BST::splayLeft(BinarySearchTree* x, BinarySearchTree* p, BinarySearchTree* g)
	{
		if (x == p->left) {
			// Zig - Zig
			g->left = p->right;
			p->right = g;
			p->left = x->right;
			x->right = p;
		}
		else {
			// Zig - Zag
			g->left = x->right;
			x->right = g;
			p->right = x->left;
			x->left = p;
		}
	}
	
	void BST::splayRight(BinarySearchTree* x, BinarySearchTree* p, BinarySearchTree* g)
	{
		if (x == p->right) {
			// Zag - Zag
			g->right = p->left;
			p->left = g;
			p->right = x->left;
			x->left = p;
		}
		else {
			// Zag - Zig
			g->right = x->left;
			x->left = g;
			p->left = x->right;
			x->right = p;
		}
	}

	BinarySearchTree* BST::tree_max()
	{
		return max(root);
	}

	BinarySearchTree* BST::tree_min()
	{
		return min(root);
	}

	BinarySearchTree* BST::max(BinarySearchTree* sub_root)
	{
		BinarySearchTree* tmp = sub_root;
		while (tmp->right!=NULL)
		{
			tmp = tmp->right;
		}
		return tmp;
	}

	BinarySearchTree* BST::min(BinarySearchTree* sub_root)
	{
		BinarySearchTree* tmp = sub_root;
		while (tmp->left != NULL)
		{
			tmp = tmp->left;
		}
		return tmp;
	}

	void BST::PreOrder()
	{
		cout << "Preorder:" << endl;
		PreOrderTraversal(root);
		cout << endl;
	}
	void BST::InOrder()
	{
		cout << "Inorder:" << endl;
		InOrderTraversal(root);
		cout << endl;
	}
	void BST::PostOrder()
	{
		cout << "Postorder:" << endl;
		PostOrderTraversal(root);
		cout << endl;
	}

	
