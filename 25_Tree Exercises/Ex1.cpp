#include <iostream>

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
	bool isSymmetric(TreeNode* root)
	{
		if (root == nullptr)
		{
			return true;
		}

		return isSymmetricCheck(root->left, root->right);
	}

private:
	bool isSymmetricCheck(TreeNode* leftNode, TreeNode* rightNode)
	{
		if (leftNode == nullptr && rightNode == nullptr)
		{
			return true;
		}

		if (leftNode == nullptr || rightNode == nullptr)
		{
			return false;
		}

		if (leftNode->val != rightNode->val)
		{
			return false;
		}

		if (isSymmetricCheck(leftNode->left, rightNode->right) == false)
		{
			return false;
		}

		if (isSymmetricCheck(leftNode->right, rightNode->left) == false)
		{
			return false;
		}

		return true;
	}
};

int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(3);

	Solution solution;

	std::cout << "Is the binary tree symmetric? ";
	if (solution.isSymmetric(root))
	{
		std::cout << "Yes";
	}
	else
	{
		std::cout << "No";
	}

	return 0;
}