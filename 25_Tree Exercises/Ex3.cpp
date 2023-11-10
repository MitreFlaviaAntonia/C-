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

	bool hasPathSum(TreeNode* root, int targetSum)
	{
		if (root == nullptr)
		{
			return false;
		}

		if (root->left == nullptr && root->right == nullptr)
		{
			if(root->val == targetSum)
			{
				return true;
			}

			return false;
		}

		int newTargetSum = targetSum - root->val;

		if (hasPathSum(root->left, newTargetSum))
		{
			return true;
		}

		if (hasPathSum(root->right, newTargetSum))
		{
			return true;
		}
		
		return false;
	}
};

int main()
{

	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(4);
	root->right = new TreeNode(8);
	root->left->left = new TreeNode(11);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->right->right->right = new TreeNode(1);

	int targetSum = 22;

	Solution solution;

	if (solution.hasPathSum(root, targetSum))
	{
		std::cout << "Path with sum " << targetSum << " exists" << std::endl;
	}
	else
	{
		std::cout << "Path with sum " << targetSum << " does not exist" << std::endl;
	}

	return 0;
}