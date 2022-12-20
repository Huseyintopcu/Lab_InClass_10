#include<iostream>
#include"BST.h"

int main()
{
	BST b;
	int key;

	b.insert(15);
	b.insert(6);
	b.insert(10);
	b.insert(2);
	b.insert(3);
	b.insert(12);
	b.insert(13);
	b.insert(20);
	
	cout << "Before insert operation:" << endl;
	b.PreOrder();
	b.InOrder();
	b.PostOrder();

	b.insert(23);

	cout <<endl<< "Before find operation:" << endl;
	b.PreOrder();
	b.InOrder();
	b.PostOrder();

	cout <<endl<< "enter the key to find: ";
	cin >> key;
	b.find(key);
	cout << endl << "After find operation:" << endl;
	b.PreOrder();
	b.InOrder();
	b.PostOrder();

	cout << endl << "Min value of tree:" << b.tree_min()->item << endl;
	cout << endl << "Max value of tree:" << b.tree_max()->item << endl;

	cout << endl << "enter a sub tree value:";
	cin >> key;
	cout << endl;

	cout << endl << "Max value of tree:" << b.min(b.find(key))->item << endl;
	cout << endl << "Max value of tree:" << b.max(b.find(key))->item << endl;
}