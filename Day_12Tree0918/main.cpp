#include "Tree.h"

int main()
{
	Tree::Node* Root = Tree::Create('R');
	Tree::Node* A = Tree::Create('A');
	Tree::Node* B = Tree::Create('B');
	Tree::Node* C = Tree::Create('B');
	Tree::Node* D = Tree::Create('D');
	Tree::Node* E = Tree::Create('D');
	Tree::Node* F = Tree::Create('E');
	Tree::Node* G = Tree::Create('E');

	Tree tree;
	tree.AddChild(Root, A);
	tree.AddChild(Root, B);

	tree.AddChild(A, C);
	tree.AddChild(A, D);

	tree.AddChild(C, E);
	tree.AddChild(C, F);

	tree.AddChild(B, G);

	//tree.PrintNode(Root, 0);

	vector<Tree::Node*> result;
	tree.GetNode(Root, 'E', result);


	
	return 0;
}