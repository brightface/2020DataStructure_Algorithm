#include "BinaryTree.h"
#include <string>
#include <stack>
using namespace std;

int GetPriority(int op)
{
	switch (op) {
	case '(':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '^':
		return 3;
	}
	return 100;
}

void MakePostfix(char *Post, const char *Mid)
{
	const char *expression = Mid;
	char *newExp = Post;
	char c;

	stack<char> cS;

	while (*expression)
	{
		if (isdigit(*expression))
		{
			while (isdigit(*expression) || *expression == '.')
			{
				*newExp++ = *expression++;
			}
			*newExp++ = ' ';
		}
		else
		{
			if (strchr("^*/+-", *expression))
			{
				while (cS.empty() != true && GetPriority(cS.top()) >= GetPriority(*expression))
				{
					*newExp++ = cS.top();
					cS.pop();
				}
				cS.push(*expression++);
			}
			else
			{
				if (*expression == '(')
				{
					cS.push(*expression++);
				}
				else if (*expression == ')')
				{
					while (true)
					{
						c = cS.top();
						cS.pop();
						if (c == '(')
							break;
						*newExp++ = c;
					}
					expression++;
				}
			}
		}
	}

	while (cS.empty() == false) {

		*newExp++ = cS.top();
		cS.pop();
	}
	*newExp = 0;
}

void Expression(const char* postFix, BinaryTree::Node** node)
{
	char* str = const_cast<char*>(postFix);
	size_t length = strlen(str);	
	// strlen 이 공백문자를 제외하고 카운트를 한다.
	stack<char> cs;

	char token = str[length - 1];
	cs.push(token);
	str[length - 1] = '\0';

	switch (cs.top())
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		{
			// 문자열은 항상 맨 뒤에 공백이 있음을 기억하자
			char* temp = new char[2];
			temp[0] = cs.top();
			temp[1] = '\0';
			cs.pop();
			*node = BinaryTree::CreateNode(temp);

			Expression(postFix, &(*node)->right);
			Expression(postFix, &(*node)->left);

			break;
		}

		default:
		{
			token = str[length -= 2];

			while (isdigit(token) || token == '.')
			{
				cs.push(token);
				if (length - 1 == UINT_MAX)
					token = 'n';
				else
				{
					str[length--] = '\0';
					token = str[length];
				}
			}
			char* temp = new char[cs.size() + 1];
			int index = 0;
			int stackSize = cs.size();
			while (cs.empty() == false)
			{
				temp[index++] = cs.top();
				cs.pop();
			}
			temp[stackSize] = '\0';
			*node = BinaryTree::CreateNode(temp);

			break;
		}
	}
}

double Evaluate(BinaryTree::Node* node)
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
			double left = Evaluate(node->left);
			double right = Evaluate(node->right);

			switch (*node->data)
			{
				case '+': return left + right;
				case '-': return left - right;
				case '*': return left * right;
				case '/': return left / right;
				//case '%': return left % right;
			}

			break;
		}

		default:
		{
			return atof(node->data);
		}
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
	//string postFix = "34*14+-";

	char exp[255];
	char post[255];
	BinaryTree::Node* root = nullptr;

	cout << "수식을 입력하세요 : ";
	cin >> exp;
	MakePostfix(post, exp);
	cout << "후위표기식 : " << post << endl;
	Expression(post, &root);

	BinaryTree::PostOrder(root); cout << endl;
	cout << "Result : " << Evaluate(root) << endl;
	
	return 0;
}

