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

void printTree(TreeNode* root)
{
	if (root == nullptr)
	{
		return;
	}

	std::cout << root->val << " ";
	printTree(root->left);
	printTree(root->right);
}

class Solution
{
public:
	TreeNode* addOneRow(TreeNode* root, int val, int depth)
	{
		if (depth == 1) //If depth == 1 that means there is no depth depth - 1 at all, then create a tree node with value 
		{//val as the new root of the whole original tree, and the original tree is the new root's left subtree.
			TreeNode* newRoot = new TreeNode(val);
			newRoot->left = root;
			return newRoot; //return the new root
		}

		addOneRowRecursive(root, val, depth, 1);//the root node is at depth 1, so currentDepth = 1 here
		return root;
	}

private:
	void addOneRowRecursive(TreeNode* parent, int val, int depth, int currentDepth)
	{
		if (parent == nullptr)//if the tree is empty/the given depth is too big, return
		{
			return;
		}

		if (currentDepth == depth - 1) //localizing the depth where the row should be added and creating the new nodes
		{
			TreeNode* leftNode = new TreeNode(val);//creating the new left node
			leftNode->left = parent->left;// linking the new left node to the left child of the parent node
			parent->left = leftNode;// linking the parent node to the new left node

			TreeNode* rightNode = new TreeNode(val);//creating the new right node
			rightNode->right = parent->right;// linking the new right node to the right child of the parent node
			parent->right = rightNode;// linking the parent node to the new right node

			return;
		}

		//if the wanted depth was not found yet, continue searching
		addOneRowRecursive(parent->left, val, depth, currentDepth + 1);
		addOneRowRecursive(parent->right, val, depth, currentDepth + 1);
	}
};

int main()
{
	TreeNode* root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(6);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(1);
	root->right->left = new TreeNode(5);

	Solution solution;

	TreeNode* modifiedRoot = solution.addOneRow(root, 8, 2);
	std::cout << "Modified tree: ";
	printTree(modifiedRoot);
	std::cout << std::endl;

	return 0;
}