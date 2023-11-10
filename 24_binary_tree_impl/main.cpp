#include <iostream>
#include "binaryTree.h"

int main()
{
	binaryTree myTree;

	myTree.insertRecursive(5);
	myTree.insertRecursive(3);
	myTree.insertRecursive(6);
	myTree.insertRecursive(10);
	myTree.insertRecursive(1);
	myTree.printTreeInOrder();
	myTree.printTreePreOrder();
	myTree.printTreePostOrder();

	int deleteData = 10;
	myTree.deleteNodeIterative(deleteData);
	std::cout << "After the node " << deleteData << " was deleted: ";
	myTree.printTreeInOrder();

	return 0;
}