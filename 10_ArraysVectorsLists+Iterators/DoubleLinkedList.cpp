#include <iostream>

template <typename T>
class MyLinkedList
{
private:
	struct Node
	{
		T m_data;
		Node* m_prev;
		Node* m_next;
		Node(const T& _value) : m_data(_value), m_prev(nullptr), m_next(nullptr) {}
	};

	Node* m_head;
	Node* m_tail;
	int m_size;

public:

	class Iterator
	{
	private:
		Node* m_current;

	public:
		Iterator(Node* node) : m_current(node) {}

		T& operator*()
		{
			return m_current->m_data;
		}

		Iterator& operator++()
		{
			m_current = m_current->m_next;
			return *this;
		}

		bool operator!=(const Iterator& other)
		{
			return m_current != other.m_current;
		}
	};

	MyLinkedList() : m_head(nullptr), m_tail(nullptr), m_size(0) {}

	Iterator begin() const
	{
		return Iterator(m_head);
	}

	Iterator end() const
	{
		return Iterator(nullptr);
	}

	bool Empty() const
	{
		return m_size == 0;
	}

	int Size() const
	{
		return m_size;
	}

	void PushBack(const T& _value)
	{
		Node* newNode = new Node(_value);
		if (Empty())
		{
			m_head = newNode;
		}
		else
		{
			newNode->m_prev = m_tail;
			m_tail->m_next = newNode;
			m_tail = newNode;
		}
		m_size++;
	}

	void PopBack()
	{
		if (Empty())
		{
			return;
		}
		if (m_size == 1)
		{
			delete m_tail;
			m_head = nullptr;
			m_tail = nullptr;
		}
		else
		{
			Node* prevNode = m_tail->m_prev;
			prevNode->m_next = nullptr;
			delete m_tail;
			m_tail = prevNode;
		}
		m_size--;
	}

	void PushFront(const T& _value)
	{
		Node* newNode = new Node(_value);
		if (Empty())
		{
			m_head = newNode;
			m_tail = newNode;
		}
		else
		{
			newNode->m_next = m_head;
			m_head->m_prev = newNode;
			m_head = newNode;
		}
		m_size++;
	}

	void PopFront()
	{
		if (Empty())
		{
			std::cout << "Empty list" << std::endl;
			return;
		}
		if (m_size == 1)
		{
			delete m_head;
			m_head = nullptr;
			m_tail = nullptr;
		}
		else
		{
			Node* nextNode = m_head->m_next;
			nextNode->m_prev = nullptr;
			delete m_head;
			m_head = nextNode;
		}
		m_size--;
	}

	T At(int _index) const
	{
		if (_index < 0 || _index >= m_size)
		{
			throw std::out_of_range("Index out of bounds");
		}
		Node* currentNode = m_head;
		for (int i = 0; i < _index; i++)
		{
			currentNode = currentNode->m_next;
		}
		return currentNode->m_data;
	}

	T& operator[](int _index)
	{
		return At(_index);
	}

	void Resize(int newSize)
	{
		if (newSize < 0) {
			throw std::invalid_argument("Invalid size");
		}
		while (m_size < newSize)
		{
			PushBack(T());
		}
		while (m_size > newSize)
		{
			PopBack();
		}
	}

	void Clear()
	{
		while (!Empty())
		{
			PopBack();
		}
	}

	void Insert(Node* node, const T& _value)
	{
		if (node == nullptr)
		{
			throw std::invalid_argument("Invalid node");
		}

		Node* newNode = new Node(_value);
		m_size++;
		if (node->m_next == nullptr)
		{
			m_tail->m_next = node;
		}
		newNode->m_prev = node->m_prev;
		newNode->m_next = node;
		node->m_prev->m_next = newNode;
		node->m_prev = newNode;
	}

	void Erase(int _index)
	{
		if (_index < 0 || _index >= m_size)
		{
			throw std::out_of_range("Index out of bounds");
		}
		if (_index == 0)
		{
			PopFront();
		}
		else if (_index == m_size - 1)
		{
			PopBack();
		}
		else
		{
			Node* currentNode = m_head;
			for (int i = 0; i < _index; i++)
			{
				currentNode = currentNode->m_next;
			}
			currentNode->m_prev->m_next = currentNode->m_next;
			currentNode->m_next->m_prev = currentNode->m_prev;
			delete currentNode;
			m_size--;
		}
	}

	void Merge(MyLinkedList& listToMerge)
	{
		if (listToMerge.Empty())
		{
			return;
		}
		if (Empty())
		{
			m_head = listToMerge.m_head;
			m_tail = listToMerge.m_tail;
		}
		else
		{
			m_tail->m_next = listToMerge.m_head;
			listToMerge.m_head->m_prev = m_tail;
			m_tail = listToMerge.m_tail;
		}
		m_size += listToMerge.m_size;
		listToMerge.m_head = nullptr;
		listToMerge.m_tail = nullptr;
		listToMerge.m_size = 0;
	}
};

int main()
{
	MyLinkedList<int> firstList;
	firstList.PushBack(43);
	firstList.PushBack(54);
	firstList.PushBack(67);

	std::cout << "Size: " << firstList.Size() << std::endl;
	std::cout << "Element at index 1: " << firstList.At(1) << std::endl;

	firstList.PopFront();
	std::cout << "Size after PopFront: " << firstList.Size() << std::endl;

	firstList.Insert(firstList.begin(), 25);
	std::cout << "Element at index 1 after Insert: " << firstList.At(1) << std::endl;

	firstList.Erase(2);
	std::cout << "Size after Erase: " << firstList.Size() << std::endl;

	MyLinkedList<int> secondList;
	secondList.PushBack(76);
	secondList.PushBack(56);

	firstList.Merge(secondList);
	std::cout << "Size after Merge: " << firstList.Size() << std::endl;

	return 0;
}