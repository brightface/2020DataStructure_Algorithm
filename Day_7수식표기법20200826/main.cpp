/*
전위 중위 후위 표기법

중위 표기법
(3 + (4 * 2)) 
3(42)*+
3 4 2 * +

3 + 4 * 2 / 2 + 32 - 12 * 32
(((3 + ((4 * 2) / 2)) + 32) - (12 * 32))
(((3 + ((4 2 *) 2 /) + 32) - (12 32 *)) 
3 4 2 * 2 / + 32 + 12 32 * -

(7 + ((2 * 5) / 3) - (3 * 2))
7 2 5 * 3 / + 3 2 * -

12 * 11 + 32 - 8 / 2 * 19 + 20 - 3 - 3 -> 후위로
12 11 * 32 + 8 2 / 19 * - 20 + 3 - 3 -

32 11 4 * - 3 / 12 + 2 + -> 중위로
(32 - (11 * 4)) / 3 + 12 + 2 

*/

/*
1. 숫자를 만나면 후위식 버퍼에 넣어준다. 숫자를 구성하는 연속된 문자를 모두 추출해서
하나의 숫자로 만들고, 이어지는 피연산자와의 구분을 위해 공백을 하나 삽입한다.
11 11 *
1 * 111
11 * 11
111 * 1
2. 연산자를 만나면 스택에 넣는다. 두번째부터는 스택을 검사하여 자신(연산자)보다
우선순위가 높은 연산자들을 모두 꺼내서 버퍼에 넣는다.
11 * 11 + 3
11 11 * /
stack
* ( * / 
3. 여는 괄호'(' 를 만나면 스택에 넣는다. '(' 를 스택에 
넣는 이유는 스택에서 우선순위의 연산자를
어디까지 꺼낼것인가 를 결정하기 위함이다.

4. 닫는 괄호 ')' 를 만나면 스택안에 있는 여는 괄호를 만날때 까지 스택 
안에 있는 연산자들을 모두 버퍼에 넣어준다.

5. 1 ~ 4 번까지 반복을 해고, 모든 과정이 끝나면, 스택에 남아있는 연산자들을
차례로 꺼내서 버퍼에 넣어준다.

( : 0
+, - : 1
*, / : 2
^    : 3

*/

#include "ArrayStack.h"
#include <iostream>
using namespace std;

int GetPriority(int op)
{
	switch (op)
	{
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

void MakePostfix(char* post, const char* mid)
{
	const char* expression = mid;
	char* newExp = post;
	char c;

	ArrayStack<char> cs(256);
	while (*expression)
	{
		//숫자면 4
		//10진수로 변환할수 없는 문자라면 0
		if (isdigit(*expression))
		{
			while (isdigit(*expression) || *expression == '.')
				*newExp++ = *expression++;

			*newExp++ = ' ';
		}
		else
		{
			if (strchr("^*/+-", *expression))
			{
				while (cs.Empty() != true
					&& GetPriority(cs.Top()) >= GetPriority(*expression))
				{
					*newExp++ = cs.Top();
					cs.Pop();
				}

				cs.Push(*expression++);
			}
			else
			{
				if (*expression == '(')
					cs.Push(*expression++);
				else if (*expression == ')')
				{
					while (true)
					{
						c = cs.Top();
						cs.Pop();
						if (c == '(')
							break;
						*newExp++ = c;
					}
					expression++;
				}
			}
		}
	}

	while (cs.Empty() != true)
	{
		*newExp++ = cs.Top();
		cs.Pop();
	}
	*newExp = 0;
}

int main()
{
	char post[256];
	char* mid = "(34+93)*2-(43/2)";
	char exp[256];
	//cin >> exp;
	MakePostfix(post, mid);
	cout << post << endl;

	return 0;
}