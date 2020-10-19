#include "BST.h"
#include <time.h>
#include <Windows.h>
int main()
{
	//srand((UINT)time(NULL));
	BST bst;
	BST::Node* root = nullptr;
	for (UINT i = 0; i < 20; i++)
	{
		bst.InsertNode(&root, rand() % 21);
	}
	cout << "완료" << endl;
	cout << "Node Count : " << bst.GetNodeCount(root) << endl;
	cout << "Tree Height : " << bst.GetHeight(root) << endl;
	
	bst.DeleteNode(&root, 13);
	
	bst.InOrder(root, 0);

	BST::Node* result = bst.SearchIteration(root, 30000);
	if (result)
		cout << result->key << endl;
	else
		cout << "없음" << endl;

	return 0;
}