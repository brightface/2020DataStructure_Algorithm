#include "BinaryTree.h"
#include <string>
using namespace std;

//void Expression(const char* postFix, BinaryTree::Node** node)
//{
//	char* str = const_cast<char*>(postFix);
//	size_t length = strlen(str);	
//	// strlen �� ���鹮�ڸ� �����ϰ� ī��Ʈ�� �Ѵ�.
//
//	char token = str[length - 1];
//	str[length - 1] = '\0';
//
//	switch (token)
//	{
//		case '+':
//		case '-':
//		case '*':
//		case '/':
//		case '%':
//		{
//			*node = BinaryTree::CreateNode(token);
//
//			Expression(postFix, &(*node)->right);
//			Expression(postFix, &(*node)->left);
//
//			break;
//		}
//
//		default:
//		{
//			*node = BinaryTree::CreateNode(token);
//
//			break;
//		}
//	}
//}

void Expression(const char* postFix, BinaryTree::Node** node)
{
	const char* str = postFix;
	// strlen �� ���鹮�ڸ� �����ϰ� ī��Ʈ�� �Ѵ�.

	switch (*str)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		{
			*node = BinaryTree::CreateNode(str);

			Expression(postFix, &(*node)->right);
			Expression(postFix, &(*node)->left);

			break;
		}

		default:
		{
			*node = BinaryTree::CreateNode(str);

			break;
		}
	}	
}

int Evaluate(BinaryTree::Node* node)
{
	if (node == nullptr) return 0;

	switch (*node->data)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		{
			int left = Evaluate(node->left);
			int right = Evaluate(node->right);

			switch (*node->data)
			{
				case '+': return left + right;
				case '-': return left - right;
				case '*': return left * right;
				case '/': return left / right;
				case '%': return left % right;
			}

			break;
		}

		default:
		{
			const char* temp;
			temp = node->data;

			return atoi(temp);
		}

		int a = 0;
	}


	return 0;
}

int main()
{
	/*BinaryTree::Node* A = BinaryTree::CreateNode('A');
	BinaryTree::Node* B = BinaryTree::CreateNode('B');
	BinaryTree::Node* C = BinaryTree::CreateNode('C');
	BinaryTree::Node* D = BinaryTree::CreateNode('D');
	BinaryTree::Node* E = BinaryTree::CreateNode('E');
	BinaryTree::Node* F = BinaryTree::CreateNode('F');
	BinaryTree::Node* G = BinaryTree::CreateNode('G');

	A->left = B;
	A->right = C;

	B->left = D;
	B->right = E;

	C->left = F;
	C->right = G;

	cout << "PreOrder :";
	BinaryTree::PreOrder(A);
	cout << endl;

	cout << "InOrder :";
	BinaryTree::InOrder(A);
	cout << endl;

	cout << "PostOrder :";
	BinaryTree::PostOrder(A);
	cout << endl;*/

	// 3 * 4 - (1 + 4)
	string postFix = "34*14+-";
	BinaryTree::Node* root = nullptr;


	Expression(postFix.c_str(), &root);

	cout << Evaluate(root) << endl;
	
	return 0;
}

