#include <iostream>

class MyLinkedList
{
private:
	struct Node
	{
		int m_data = -1;
		Node* m_prev = nullptr;
		Node* m_next = nullptr;
	};

	Node* m_Head = nullptr;
	Node* m_Tail = nullptr;
	int m_size = 0;

public:

	Node* getHead()
	{
		return m_Head;
	}

	Node* getTail()
	{
		return m_Tail;
	}

	int getSize()
	{
		return m_size;
	}

	void push_back(int data) //add an element to the back of the list
	{
		Node* newNode = new Node();
		newNode->m_data = data;

		if (m_size == 0)
		{
			m_Head = newNode;
			m_Tail = m_Head;
		}
		else
		{
			newNode->m_prev = m_Tail;
			m_Tail->m_next = newNode;
			m_Tail = newNode;
		}
		m_size++;
	}

	void pop_back() //deletes the last element from the list
	{
		if (m_size == 0)
		{
			return;
		}

		if (m_size == 1)
		{
			m_Head = nullptr;
			m_Tail = nullptr;
			delete m_Tail;
		}
		else
		{
			Node* node = m_Tail;
			m_Tail->m_data = m_Tail->m_prev->m_data;
			m_Tail = m_Tail->m_prev;
			delete node;
		}
		m_size--;
	}

	void insert(Node* insertAfter, int data) //inserts a new node that contains some data, after a given node
	{
		Node* newNode = new Node();
		newNode->m_data = data;
		insertAfter->m_next->m_prev = newNode;
		newNode->m_next = insertAfter->m_next;
		insertAfter->m_next = newNode;
		newNode->m_prev = insertAfter;
		m_size++;
	}

	Node* at(int index) //returns the node that is found at a given index
	{
		if (index > m_size)
		{
			std::cout << "The index given is not a part of the list" << std::endl;
			return nullptr;
		}

		Node* it = m_Head;
		for (int i = 1; i <= index; i++)
		{
			it = it->m_next;
		}
		return it;
	}

	void erase(Node* node) //erases a given node from the list
	{
		if (m_size == 0)
		{
			return;
		}

		if (m_size == 1)
		{
			m_Head = nullptr;
			m_Tail = nullptr;
			delete node;
		}
		else
		{
			if (m_size == 2)
			{
				if (node == m_Head)
				{
					delete node;
					m_Head = m_Tail;
					m_Head->m_data = m_Tail->m_data;
				}
				else
				{
					if (node == m_Tail)
					{
						delete node;
						m_Tail = m_Head;
						m_Tail->m_data = m_Head->m_data;
					}
				}
			}
			else
			{
				if (node == m_Head)
				{
					m_Head = node->m_next;
					delete node;
				}
				else
				{
					if (node == m_Tail)
					{
						m_Tail = node -> m_prev;
						delete node;
					}
					else
					{
						node -> m_prev -> m_next = node -> m_next;
						node -> m_next -> m_prev = node -> m_prev;
						delete node;
					}
				}
			}
		}
		m_size--;
	}

	void printList(MyLinkedList myList)
	{
		Node* it = myList.m_Head;
		for (int i = 0; i < myList.m_size; i++)
		{
			std::cout << it->m_data << " ";
			it = it->m_next;
		}
		std::cout << std::endl;
	}
};

int main()
{
	MyLinkedList myList;
	myList.push_back(10);
	myList.push_back(20);
	myList.push_back(30);
	myList.push_back(40);
	myList.printList(myList);
	myList.insert(myList.getHead(), 15);
	myList.printList(myList);
	myList.pop_back();
	std::cout << myList.at(1) -> m_data << std::endl;
	myList.erase(myList.getHead() -> m_next);
	myList.printList(myList);
	return 0;
}

