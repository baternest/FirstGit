// 102. Binary Tree Level Order Traversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

// URL: https://leetcode.com/problems/binary-tree-level-order-traversal/
// WIKI:


// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
	vector<vector<int>> final_result;
	queue<TreeNode*> q;
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (root == nullptr)
			return final_result;
		q.push(root);
		vector<int> level_result;

		queue<TreeNode*> next_q;
		while (!q.empty())
		{		
			auto cur_node = q.front();
			q.pop();

			level_result.push_back(cur_node->val);

			if (cur_node->left != nullptr)
			{
				next_q.push(cur_node->left);
			}
			if (cur_node->right != nullptr)
			{
				next_q.push(cur_node->right);
			}

			if (q.empty())
			{
				final_result.push_back(level_result);
				level_result.clear();
				if (next_q.size() > 0)
				{
					q.swap(next_q);
				}
			}
		}

		return final_result;
	}
};

int main()
{
	// Testcase:
	// [1,2,3,4,5]
	// [0,2,4,1,null,3,-1,5,1,null,6,null,8]

	// [3,9,20,null,null,15,7]
	//    3
	//   / \
	//  9  20
	//    /  \
	//   15   7
	//TreeNode* root = new TreeNode(3);
	//TreeNode* left = new TreeNode(9);
	//TreeNode* right = new TreeNode(20);
	//root->left = left;
	//root->right = right;
	//TreeNode* r1_left = new TreeNode(15);
	//TreeNode* r1_right = new TreeNode(7);
	//right->left = r1_left;
	//right->right = r1_right;

	TreeNode* root = new TreeNode(1);

	TreeNode* left = new TreeNode(2);
	TreeNode* right = new TreeNode(3);
	root->left = left;
	root->right = right;

	TreeNode* l1_left = new TreeNode(4);
	TreeNode* l1_right = new TreeNode(5);
	left->left = l1_left;
	left->right = l1_right;

	TreeNode* r1_left = new TreeNode(6);
	TreeNode* r1_right = new TreeNode(7);
	right->left = r1_left;
	right->right = r1_right;

	//[
	//	[3],
	//	[9, 20],
	//	[15, 7]
	//]
	Solution solution;
	auto zh = solution.levelOrder(root);


	//[0, 2, 4, 1, null, 3, -1, 5, 1, null, 6, null, 8]

	std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
