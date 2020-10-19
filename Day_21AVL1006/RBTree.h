#pragma once

/*
	<< Red-Black Tree ( 레드-블랙 트리 ) >>
	- 연관배열을 구현할 때 사용된다.

	<< AVL 과의 차이점 >>
	1. AVL 트리는 RB 트리에 비해 좀 더 엄격하게 균형을 유지한다. ( RB 보다는 탐색이 빠르다. ), ( 회전이 더 많이 일어난다. ), ( 삽입, 삭제시에 시간이 좀 더 오래 걸릴수도 있다. )
	2. RB 트리는 색상 정보를 저장하기 위한 추가 데이터가 필요하다.
	3. RB 트리는 대다수의 프로그래밍 언어에서 연관배열( Map, Set, MultiMap, MultiSet )을 구현하기 위한 자료구조로 사용된다.
	4. AVL 트리는 더 빠른 순회가 필요한 데이터베이스에서 많이 쓴다.

	<< RB 트리의 속성 >>
	1. 모든 노드들은 Black 이거나 Red 이다.
	2. 루트 노드는 항상 Black 이다.
	3. 모든 Leaf 노드들은 항상 Black 이다.
	4. 만약에 노드가 Red 라면, 그 노드의 자식들은 둘 다 Black 이다.
		-> Red 노드가 연속적으로 나올 수 없다.
		-> Red 노드의 부모는 항상 Black 이다.
	5. 각 노드 ~ 자손 Left 노드 사이의 모든 경로에 대해 검은색 노드의 수가 같다.
		-> 루트 노드부터 가장 먼 경로까지의 거리가, 가장 가까운 경로까지의 거리의 두 배 보다 항상 작게 된다.

	<< RB 트리의 삽입 >>
	1. 삽입되는 모든 노드의 색깔은 Red 이다.
	
	<< Red 가 연달아 나올 때 취할 수 있는 2 가지 방법 >>
	A. Recoloring
	- 삽입된 노드의 부모의 형제 색상이 Red 일 때
	- 삽입된 노드의 부모와 부모 형제 노드를 Black 으로 바꾼다.
	- 부모의 부모노드가 Root 가 아니라면, 부모의 부모 노드를 Red 로 바꾼다.

	B. Restructuring
	- 삽입된 노드의 부모의 형제 색상이 Black 이거나 nullptr 일 때
	- 삽입된 노드, 부모, 부모의 부모를 오름차순으로 정렬한다.
	- 중앙값을 부모 노드로 만들고, 나머지 노드를 자식으로 변환한다.
	- 부모가 된 노드를 Black 으로, 나머지 노드를 Red 로 변환한다.

*/

enum EColor
{
	RED,
	BLACK,
};

class RBTree
{
public:
	struct Node
	{
		int data;
		bool color = RED;
		Node* left = nullptr;
		Node* right = nullptr;
		Node* parent = nullptr;
	};

	static Node* Creat(int data)
	{
		Node* node = new Node();
		node->data = data;

		return node;
	}

	void Destroy(Node** node)
	{
		delete(*node);
		*node = nullptr;
	}

private:
	Node* Parent(Node* node)
	{
		return node == nullptr ? nullptr : node->parent;
	}

	Node* GrandParent(Node* node)
	{
		return Parent(Parent(node));
	}

	Node* Uncle(Node* node)
	{
		Node* grandParent = GrandParent(node);
		if (grandParent == nullptr)
			return nullptr;


		if (node->parent == grandParent->left)
			return grandParent->right;
		else
			return grandParent->left;
	}

	///////////////////////////////////////////////////////////////////////////

	/**  Node 가 Tree 의 Root 일 때  **/
	void InsertCase1(Node* node)
	{
		if (node->parent == nullptr)
			node->color = BLACK;
		else
			InsertCase2(node);
	}

	/**  부모 Node 가 Black 일 때  **/
	void InsertCase2(Node* node)
	{
		if (node->parent->color == BLACK)
			return;
		else
			InsertCase3(node);
	}

	/**  부모 Node 가 Red 일 때  **/
	void InsertCase3(Node* node)
	{
		Node* uncle = Uncle(node);
		Node* grandParent = GrandParent(node);

		if (uncle != nullptr && uncle->color == RED)
		{
			node->parent->color = BLACK;
			uncle->color = BLACK;
			grandParent->color = RED;

			InsertCase1(grandParent);
		}
		else
			InsertCase4(node);
	}

	void InsertCase4(Node* node)
	{

	}
};