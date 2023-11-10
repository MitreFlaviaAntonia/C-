#include <deque>
#include <vector>

template <typename T, typename Container = std::deque<T>>
class Stack
{
public:
	Container elems;
	Stack();
	template <typename T1, typename Container1>
	Stack<T, Container>& operator=(Stack<T1, Container1> const&);
	void push(T const&);
	T pop();
	T top() const;
};

template <typename T, typename Container>
Stack<T, Container>::Stack() {}

template <typename T, typename Container>
void Stack<T, Container>::push(T const& value)
{
	elems.push_back(value);
}

template <typename T, typename Container>
T Stack<T, Container>::pop()
{
	if (elems.empty())
	{
		throw std::out_of_range("Stack<>::pop(): empty stack");
	}
	T elem = elems.back();
	elems.pop_back();
	return elem;
}

template <typename T, typename Container>
T Stack<T, Container>::top() const
{
	if (elems.empty())
	{
		throw std::out_of_range("Stack<>::top(): empty stack");
	}

	return elems.back();
}

template <typename T, typename Container>
template <typename T1, typename Container1>
Stack<T, Container>& Stack<T, Container>::operator=(const Stack<T1, Container1>& other)
{
	elems.clear();

	for (const T& elem : other.elems)
	{
		T x = elem;
		elems.push_back(x);
	}

	return *this;
}