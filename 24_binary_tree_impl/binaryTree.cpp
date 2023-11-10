#include "binaryTree.h"
#include <iostream>

void binaryTree::printTreeInOrder()
{
	printInOrder(root);
	std::cout << std::endl;
}

void binaryTree::printInOrder(Node* current)
{
	if (current == nullptr)
	{
		return;
	}
	printInOrder(current->left);
	std::cout << current->data << " ";
	printInOrder(current->right);
}

void binaryTree::printTreePreOrder()
{
	printPreOrder(root);
	std::cout << std::endl;
}

void binaryTree::printPreOrder(Node* current)
{
	if (current == nullptr)
	{
		return;
	}
	std::cout << current->data << " ";
	printPreOrder(current->left);
	printPreOrder(current->right);
}

void binaryTree::printTreePostOrder()
{
	printPostOrder(root);
	std::cout << std::endl;
}

void binaryTree::printPostOrder(Node* current)
{
	if (current == nullptr)
	{
		return;
	}
	printPostOrder(current->left);
	printPostOrder(current->right);
	std::cout << current->data << " ";
}

void binaryTree::insertRecursive(int newData)
{
	root = insertRecursive(newData, root);
}

binaryTree::Node* binaryTree::insertRecursive(int newData, Node* current)
{
	if (current == nullptr)
	{
		current = new Node();
		current->data = newData;
		current->left = nullptr;
		current->right = nullptr;

		return current;
	}

	if (current->data > newData)
	{
		current->left = insertRecursive(newData, current->left);
	}
	else
	{
		current->right = insertRecursive(newData, current->right);
	}
	return current;
}

void binaryTree::insertIterative(int newData)
{
	Node* current = root;
	Node* parent_current = nullptr;

	while (current != nullptr)
	{
		parent_current = current;

		if (current->data > newData)
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
	}

	current = new Node();
	current->data = newData;
	current->left = nullptr;
	current->right = nullptr;

	if (parent_current != nullptr)
	{
		if (parent_current->data > newData)
		{
			parent_current->left = current;
		}
		else
		{
			parent_current->right = current;
		}
	}
	else
	{
		root = current;
	}
}

void binaryTree::deleteNodeIterative(int dataToDelete)
{

	Node* current = root;
	Node* parent_current = nullptr;

	while (current != nullptr && current->data != dataToDelete)
	{
		parent_current = current;
		if (current->data > dataToDelete)
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
	}

	if (current == nullptr)
	{
		return;
	}

	if (current->left == nullptr || current->right == nullptr)
	{
		Node* child;
		if (current->left != nullptr)
		{
			child = current->left;
		}
		else
		{
			child = current->right;
		}

		if (parent_current == nullptr)
		{
			root = child;
		}
		else if (parent_current->left == current)
		{
			parent_current->left = child;
		}
		else
		{
			parent_current->right = child;
		}

		delete current;
	}
	else
	{
		Node* newParent = current;
		Node* newChild = current->right;
		while (newChild->left != nullptr)
		{
			newParent = newChild;
			newChild = newChild->left;
		}
		current->data = newChild->data;
		if (newParent->left == newChild)
		{
			newParent->left = newChild->right;
		}
		else
		{
			newParent->right = newChild->right;
		}
		delete newChild;
	}
}