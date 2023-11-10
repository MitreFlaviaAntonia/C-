#include <iostream>
#include <vector>

void heapify(std::vector<int>& binTree, int binTreeSize, int parrentNodeIndex)
{
	int largestElemIndex = parrentNodeIndex;
	int leftIndex = 2 * parrentNodeIndex + 1;
	int rightIndex = 2 * parrentNodeIndex + 2;

	if (leftIndex < binTreeSize && binTree[leftIndex] > binTree[parrentNodeIndex])
	{
		largestElemIndex = leftIndex;
		std::swap(binTree[leftIndex], binTree[parrentNodeIndex]);
	}

	if (rightIndex < binTreeSize && binTree[rightIndex] > binTree[parrentNodeIndex])
	{
		largestElemIndex = rightIndex;
		std::swap(binTree[rightIndex], binTree[parrentNodeIndex]);
	}

	if (largestElemIndex != parrentNodeIndex)
	{
		heapify(binTree, binTreeSize, largestElemIndex);
	}
	//the algorithm finishes when no swaps were made, or when the largestElemIndex is a leaf
}

void heapsort(std::vector<int>& maxHeap, int maxHeapSize)
{
	for (int newHeapSize = maxHeapSize - 1; newHeapSize >= 0; newHeapSize--)
	{
		std::swap(maxHeap[0], maxHeap[newHeapSize]); //move the roots (max elements) at the back of the heap vector
		heapify(maxHeap, newHeapSize, 0); //rearrange the heap after "deleting" the root element
	}
}

int main()
{
	std::vector<int> binTree = { 10, 20, 15, 30, 40 };
	int binTreeSize = binTree.size();

	//transform the binary tree into a heap
	for (int i = binTreeSize / 2 - 1; i >= 0; --i) //binTreeSize / 2 - 1 is the index for the last non-leaf node in a binary tree
	{
		heapify(binTree, binTreeSize, i);
	}

	std::cout << "The constructed max heap: " << std::endl;
	for (int i = 0; i < binTreeSize; ++i)
	{
		std::cout << binTree[i] << " ";
	}

	heapsort(binTree, binTreeSize);

	std::cout << "The sorted elements from the heap: " << std::endl;
	for (int i = 0; i < binTreeSize; ++i)
	{
		std::cout << binTree[i] << " ";
	}
}