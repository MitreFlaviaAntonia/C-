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
	bool isValidBST(TreeNode* root)
	{
		return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
	}

private:
	bool isValidBSTHelper(TreeNode* root, long minVal, long maxVal)
	{
		if (root == nullptr)
		{
			return true;
		}

		if (root->val <= minVal || root->val >= maxVal)
		{
			return false;
		}

		return isValidBSTHelper(root->left, minVal, root->val) && isValidBSTHelper(root->right, root->val, maxVal);
	}
};

int main()
{
	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(3);
	root->right = new TreeNode(7);
	root->left->left = new TreeNode(2);
	root->left->right = new TreeNode(4);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(8);

	Solution solution;

	if (solution.isValidBST(root))
	{
		std::cout << "Valid BST" << std::endl;
	}
	else
	{
		std::cout << "Not valid BST" << std::endl;
	}

	return 0;
}