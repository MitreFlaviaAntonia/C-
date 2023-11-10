/*1.	Create an Array class that does the following operations:
-	Size – returns the current size of the array
-	Empty – returns true of the size is 0
-	Front – returns the first element from the list
-	Back – returns the last element from the list
-	Reverse – reverses the list, the first element becomes the last, the second, becomes the second last… 
-	At – returns the element from the specified position
-	Operator [] – the same as at
-	Swap(Array& arr) – swaps the elements from arr with the elements from the current class
*/


#include <cstdlib>
#include <iostream>
using namespace std;

class Array {
private:
	int* ptr;
	int size;

public:
	Array(int*, int);

	~Array() {
		if (ptr != nullptr) {
			delete ptr;
		}
	}

	int& operator[](int);

	void printArray() const;

	int getSize() {
		return size;
	}

	bool isEmpty() {
		if (size == 0)
			return true;

		return false;
	}

	int frontElement() {
		if (!isEmpty())
			return ptr[0];

		return -1;
	}

	int lastElement() {
		if (!isEmpty())
			return ptr[size - 1];

		return -1;
	}

	void reverseElements() {
		int arr[100] = {};
		for (int i = 0; i < size; i++) {
			if (i < size / 2 + 1) {
				arr[i] = ptr[i];
				ptr[i] = ptr[size - i - 1];
			}
			else
				ptr[i] = arr[size - i - 1];
		}
	}

	int elementAtPos(int pos) {

		if (pos >= size)
			return -1;

		return ptr[pos];
	}

	void swap(int* ptr1) {
		for (int i = 0; i < size; i++) {
			ptr[i] = ptr1[i];
		}
	}
};

int& Array::operator[](int index)
{
	if (index >= size) {
		cout << "Array index out of bound, exiting";
		exit(0);
	}
	return ptr[index];
}

Array::Array(int* p = NULL, int s = 0)
{
	size = s;
	ptr = NULL;
	if (s != 0) {
		ptr = new int[s];
		for (int i = 0; i < s; i++)
			ptr[i] = p[i];
	}
}

void Array::printArray() const
{
	for (int i = 0; i < size; i++)
		cout << ptr[i] << " ";
	cout << endl;
}

int main()
{
	int len;
	cout << "How many integers does your array got? ";
	cin >> len;

	int a[100] = {};

	for (int i = 0; i < len; i++) {
		cin >> a[i];
	}

	Array arr1(a, len);

	cout << endl << "The size of the array is: " << arr1.getSize();

	cout << endl << "Is the array empty? ";
	if (arr1.isEmpty() == 1)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	if (arr1.frontElement() == -1)
		cout << "Cannot print the first element as the array is empty" << endl;
	else
		cout << "The first element of the array is: " << arr1.frontElement() << endl;

	if (arr1.lastElement() == -1)
		cout << "Cannot print the first element as the array is empty" << endl;
	else
		cout << "The last element of the array is: " << arr1.lastElement() << endl;

	cout << "The array with reversed elements is: " << endl;
	arr1.reverseElements();
	arr1.printArray();

	int pos;

	cout << "Choose a position to print the element at is: ";
	cin >> pos;

	cout << "Using the function -at-, the element at pos " << pos << " is: " << arr1.elementAtPos(pos) << endl;

	cout << "Using [], the element at pos " << pos << " is: " << arr1[pos] << endl;

	arr1.printArray();

	int array[100] = {};

	cout << "To swap all elements, read another array of " << len << " elements:";

	for (int i = 0; i < len; i++) {
		cin >> array[i];
	}

	arr1.swap(array);

	cout << "After swap: ";
	arr1.printArray();


	return 0;
}
