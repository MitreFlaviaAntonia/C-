#include <iostream>
#include <vector>

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* constructBST(std::vector<int>& nums, int left, int right)
{
	if (left > right)
	{
		return nullptr;
	}

	int mid = left + (right - left) / 2;
	TreeNode* root = new TreeNode(nums[mid]);

	root->left = constructBST(nums, left, mid - 1);
	root->right = constructBST(nums, mid + 1, right);

	return root;
}

TreeNode* balanceBST(TreeNode* root)
{
	std::vector<int> nums;
	inorderTraversal(root, nums);

	return constructBST(nums, 0, nums.size() - 1);
}

void inorderTraversal(TreeNode* root, std::vector<int>& nums)
{
	if (root == nullptr)
	{
		return;
	}

	inorderTraversal(root->left, nums);
	nums.push_back(root->val);
	inorderTraversal(root->right, nums);
}

void printInorder(TreeNode* root)
{
	if (root == nullptr)
	{
		return;
	}

	printInorder(root->left);
	std::cout << root->val << " ";
	printInorder(root->right);
}

int main()
{

	TreeNode* root1 = new TreeNode(1);
	root1->right = new TreeNode(2);
	root1->right->right = new TreeNode(3);
	root1->right->right->right = new TreeNode(4);

	TreeNode* balanced1 = balanceBST(root1);
	printInorder(balanced1);
	std::cout << std::endl;

	TreeNode* root2 = new TreeNode(2);
	root2->left = new TreeNode(1);
	root2->right = new TreeNode(3);

	TreeNode* balanced2 = balanceBST(root2);
	printInorder(balanced2);
	std::cout << std::endl;

	return 0;
}