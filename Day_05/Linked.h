#pragma once

// RankingList

/*
	Stack 같은 경우에는 단방향 연결리스트
	그 외에는 대부분 양방향 연결리스트를 사용한다.
*/

#include <iostream>
#include <string>
using namespace std;

struct Character
{
	string name;
	int level;
	int elo;
};


class RankingList
{
public:
	struct Node
	{
		Node* prev = nullptr;	// 이전 노드
		Node* next = nullptr;	// 다음 노드

		Character* data;
	};

	static Node* Create(Character* data)
	{
		Node* node = new Node();
		node->data = data;


		return node;
	}

	static void Destroy(Node** node)
	{
		delete (*node)->data;
		*node = nullptr;
	}
	
	static Character* CreateCha
	{
		Character* character = new Character();
		
	}
public:
	~RankingList()
	{
		Clear();
	}

	void Push_Back(Character* data)
	{
		Node* node = Create(data);

		if (head == nullptr)
		{
			head = node;
			tail = node;
		}
		else
		{
			tail->next = node;
			node->prev = tail;
			tail = tail->next;
		}

		size++;
	}

	void Push_Front(Character* data)
	{
		Node* node = Create(data);

		if (head == nullptr)
		{
			head = node;
			tail = node;
		}
		else
		{
			head->prev = node;
			node->next = head;
			head = node;
		}

		size++;
	}

	void Pop_Back()
	{
		// 항상 코딩할 때 예외처리를 먼저 생각해라
		// assert 는 debug 모드에서만 먹힌다.
		if (size == 0) return;

		if (size == 1)
		{
			Destroy(&head);
			tail = nullptr;
		}
		else
		{
			Node* tempNode = tail->prev;

			Destroy(&tail);
			tail = tempNode;

			tail->next = nullptr;
		}

		size--;
	}

	void Pop_Front()
	{
		if (size == 0) return;

		if (size == 1)
		{
			Destroy(&head);
			tail = nullptr;
		}
		else
		{
			Node* tempNode = head;
			head = head->next;
			Destroy(&tempNode);
			head->prev = nullptr;
		}

		size--;
	}

	void Insert(Node* target, Character* data)
	{
		if (target == nullptr) return;

		if (target == tail)
			Push_Back(data);

		else
		{
			Node* newNode = Create(data);
			Node* tempNode = target->next;


			target->next = newNode;
			newNode->prev = target;
			newNode->next = tempNode;
			tempNode->prev = newNode;

			size++;
		}
	}

	Node* operator[](int index)
	{
		if (index >= size)
		{
			cout << "인덱스 에러" << endl;
			return nullptr;
		}

		Node* node = head;

		while (node != nullptr && index-- > 0)
			node = node->next;

		return node;
	}

	int Size() { return size; }

	void Clear()
	{
		for (int i = size; i > 0; i--)
			Pop_Back();
	}

	/*void PrintList()
	{
		for (int i = 0; i < size; i++)
			cout << operator[](i)->data << " ";
		cout << endl;
	}*/

	void PushCharacter(Character* data)
	{
		if (head == nullptr)
		{
			Node* node = Create(data);
			head = node;
			tail = node;
			size++;
		}

		else
		{
			if (data->elo > head->data->elo)
			{
				Push_Front(data);
				return;
			}
			else if (data->elo < tail->data->elo)
			{
				Push_Back(data);
				return;
			}
			Node* temp = head;
			while (temp->next != nullptr)
			{
				Character* nextData = temp->next->data;
				if (data->elo > nextData->elo && data->elo < temp->data->elo)
				{
					Insert(temp, data);
					return;
				}
				temp = temp->next;
			}
		}
	}

	void PrintRank()
	{
		cout << "이름\t랭크\t레벨\telo" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << operator[](i)->data->name
				<< "\t" << i + 1
				<< "\t" << operator[](i)->data->level
				<< "\t" << operator[](i)->data->elo << endl;
		}
	}
private:
	Node* head = nullptr;
	Node* tail = nullptr;

	int size = 0;

};