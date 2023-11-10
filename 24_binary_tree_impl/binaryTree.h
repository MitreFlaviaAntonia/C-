#pragma once
#include <iostream>

class binaryTree
{
private:
	 
	struct Node
	{
		int data;
		Node* left;
		Node* right;
	};
	
	Node* root = nullptr;

public:

	Node* insertRecursive(int newData, Node* current);
	void insertRecursive(int newData);
	void insertIterative(int newData);
	void deleteNodeIterative(int dataToDelete);
	void printTreeInOrder();
	void printInOrder(Node* current);
	void printTreePreOrder();
	void printPreOrder(Node* current);
	void printTreePostOrder();
	void printPostOrder(Node* current);
};