#include "AVL.h"

int main()
{
	AVL avl;
	AVL::Node* root = nullptr;
	root = avl.Insert(root, 5);
	root = avl.Insert(root, 15);
	root = avl.Insert(root, 25);
	root = avl.Insert(root, 18);
	root = avl.Insert(root, 37);
	root = avl.Insert(root, 1);
	root = avl.Insert(root, 3);
	root = avl.Insert(root, 9);
	root = avl.Insert(root, 12);
	root = avl.Insert(root, 14);
	root = avl.Insert(root, 20);
	root = avl.Insert(root, 80);
	root = avl.Insert(root, 7);


	//avl.InOrder(root);
	//cout << avl.Find(root, 20)->data << endl;
	
	//avl.Display(root, 0, 40);
	avl.Display(root);

	return 0;
}