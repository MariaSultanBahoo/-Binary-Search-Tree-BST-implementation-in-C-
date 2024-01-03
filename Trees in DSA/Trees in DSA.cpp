// Trees in DSA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
using namespace std;
struct node
{
	node* left, * right;
	int data;

	node()
	{
		left = right = NULL;
	}
};
class bst
{
	node* root;
public:
	bst()
	{
		root = NULL;
	}
	bool isempty()
	{
		return (root == NULL);
	}
	void insert(int item)
	{
		node* ptr = root;
		node* prev = 0;
		while (ptr != 0)
		{
			prev = ptr;
			if (item < ptr->data)
				ptr = ptr->left;
			else if (item > ptr->data)
				ptr = ptr->right;
			else
			{
				cout << ptr->data << " value already exists 1 time\n";
				return;
			}
		}
		node* temp = new node;
		temp->data = item;
		temp->left = 0;
		temp->right = 0;
		if (prev == NULL)
		{
			root = temp;
		}
		else if (item < prev->data)
		{
			prev->left = temp;
		}
		else
		{
			prev->right = temp;
		}
	}
	bool search(int item)
	{
		node* ptr = root;
		bool found = false;
		while (!found && ptr != NULL)
		{
			if (item < ptr->data)
				ptr = ptr->left;
			else if (item > ptr->data)
				ptr = ptr->right;
			else
				found = true;
		}
		return found;
	}
	node* getroot()
	{
		return root;
	}
	void Preorder(node* ptr)
	{
		if (ptr != NULL)
		{
			cout << ptr->data << "\t";
			Preorder(ptr->left);
			Preorder(ptr->right);
		}
	}
	void Postorder(node* ptr)
	{
		if (ptr != NULL)
		{
			Postorder(ptr->left);
			Postorder(ptr->right);
			cout << ptr->data << "\t";
		}
	}
	void Inorder(node* ptr)
	{
		if (ptr != NULL)
		{
			Inorder(ptr->left);
			cout << ptr->data << "\t";
			Inorder(ptr->right);
		}
	}
};
int main()
{
	bst b1;
	node* temp;
	temp = b1.getroot();
	b1.insert(10);
	b1.insert(27);
	b1.insert(8);
	b1.insert(19);
	b1.insert(3);
	b1.insert(27);


	cout << "\nPost-Order\n";
	b1.Postorder(b1.getroot());
	cout << endl;
	cout << "\nPre-Order\n";
	b1.Preorder(b1.getroot());
	cout << endl;
	cout << "\nIn-Order\n";
	b1.Inorder(b1.getroot());
	cout << endl;
	if (b1.search(18))
	{
		cout << "\nvalue found\n";
	}
	else
		cout << "\n\nvalue not found\n";
	return 0;
}
