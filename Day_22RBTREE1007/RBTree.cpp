#include "RBTree.h"

int main()
{
	RBTree rb;
	RBTree::Node* root = nullptr;
	root = rb.Insert(root, RBTree::Create(5));
	root = rb.Insert(root, RBTree::Create(15));
	root = rb.Insert(root, RBTree::Create(25));
	root = rb.Insert(root, RBTree::Create(18));
	root = rb.Insert(root, RBTree::Create(37));
	root = rb.Insert(root, RBTree::Create(1));
	root = rb.Insert(root, RBTree::Create(3));
	root = rb.Insert(root, RBTree::Create(9));
	root = rb.Insert(root, RBTree::Create(12));
	root = rb.Insert(root, RBTree::Create(14));
	root = rb.Insert(root, RBTree::Create(20));
	root = rb.Insert(root, RBTree::Create(80));
	root = rb.Insert(root, RBTree::Create(7));

	int input = 0;
	while (true)
	{
		cin >> input;
		system("cls");
		root = rb.Insert(root, RBTree::Create(input));
		rb.Display(root);
	}

	//rb.InOrder(root);


	return 0;
}