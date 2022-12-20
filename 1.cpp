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
	b.insert(23);

	cout << "Before find operation:" << endl;
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
}