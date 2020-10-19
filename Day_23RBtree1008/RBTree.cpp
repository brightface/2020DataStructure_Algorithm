#include "RBTree.h"

int main()
{
	RBTree rb;
	RBTree::Node* root = nullptr;

	int input = 0;
	int selection = 0;
	while (true)
	{
		cout << "1. »ðÀÔ  2. »èÁ¦" << endl;
		cin >> selection;
		switch (selection)
		{
			case 1:
			{
				cin >> input;
				system("cls");
				root = rb.Insert(root, RBTree::Create(input));
				rb.Display(root);
				break;
			}
			case 2:
			{
				cin >> input;
				system("cls");
				rb.DeleteNode(root, rb.Find(root, input));
				rb.Display(root);
				break;
			}
		}
		
		
	}
	/*root = rb.Insert(root, RBTree::Create(5));
	root = rb.Insert(root, RBTree::Create(15));
	root = rb.Insert(root, RBTree::Create(25));
	root = rb.Insert(root, RBTree::Create(18));
	root = rb.Insert(root, RBTree::Create(37));
	root = rb.Insert(root, RBTree::Create(1));
	root = rb.Insert(root, RBTree::Create(3));
	root = rb.Insert(root, RBTree::Create(9));
	root = rb.Insert(root, RBTree::Create(12));
	root = rb.Insert(root, RBTree::Create(14));*/

	//rb.InOrder(root);
	//rb.Display(root);




	return 0;
}