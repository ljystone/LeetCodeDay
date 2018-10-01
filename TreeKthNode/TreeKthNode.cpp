// TreeKthNode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() {}
	TreeNode(int val) :val(val),  left(NULL), right(NULL)
	{
	}
};
class Solution
{
public:
	TreeNode * KthTreeNode(TreeNode *root, int k)
	{
		if (root == NULL)
		{
			return NULL;
		}
		TreeNode * resTreeNode;
		int count = 0;
		if ((resTreeNode = KthTreeNode(root->left, k)) != NULL)
		{
			return resTreeNode;
		}
		count++;
		cout << "count" << count << ",val=" << root->val << endl;
		if (count == k)
		{
			return root;
		}
		if ((resTreeNode = KthTreeNode(root->right, k)) != NULL)
		{
			return resTreeNode;
		}
		return NULL;
	}
};
int main()
{
	TreeNode tree[7];
	tree[0].val = 5;
	tree[0].left = &tree[1];
	tree[0].right = &tree[2];

	tree[1].val = 3;
	tree[1].left = &tree[3];
	tree[1].right = &tree[4];

	tree[2].val = 7;
	tree[2].left = &tree[5];
	tree[2].right = &tree[6];

	tree[3].val = 2;
	tree[3].left = NULL;
	tree[3].right = NULL;

	tree[4].val = 4;
	tree[4].left = NULL;
	tree[4].right = NULL;

	tree[5].val = 6;
	tree[5].left = NULL;
	tree[5].right = NULL;

	tree[6].val = 8;
	tree[6].left = NULL;
	tree[6].right = NULL;

	Solution solu;
	TreeNode *res = NULL;
	if ((res = solu.KthTreeNode(tree, 3)) != NULL)
	{
		cout << res->val << endl;
	}
	else
	{
		cout << "null node" << endl;
	}
	return 0;



}

