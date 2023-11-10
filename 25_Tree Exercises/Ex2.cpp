#include <iostream>

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution
{
public:

	int height(TreeNode* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		
		int left = height(root->left);
		int right = height(root->right);
		return std::max(left, right) + 1;
	}

	bool isBalanced(TreeNode* root)
	{
		if (root == nullptr)
		{
			return true;
		}

		int leftHeight = height(root->left);
		int rightHeight = height(root->right);

		if (abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right))
		{
			return true;
		}

		return false;
	}
};

int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);

	Solution solution;

	if (solution.isBalanced(root))
	{
		std::cout << "The tree is balanced." << std::endl;
	}
	else
	{
		std::cout << "The tree is not balanced." << std::endl;
	}

	return 0;
}