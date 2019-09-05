// 145. Binary Tree Postorder Traversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// URL: https://leetcode.com/problems/binary-tree-postorder-traversal/

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	vector<int> result;
	stack<TreeNode*> s;
public:
	// Approach 1 : Recursive Approach
	//vector<int> postorderTraversal(TreeNode* root) {
	//	if (root == nullptr)
	//		return result;
	//	postorderTraversal(root->left);
	//	postorderTraversal(root->right);
	//	result.push_back(root->val);
	//	return result;
	//}

	// Approach 2: Iterating method using Stack
	vector<int> postorderTraversal(TreeNode* root) {
		TreeNode* lastNodeVisited = nullptr;
		while (!s.empty() || root != nullptr)
		{
			if (root != nullptr)
			{
				s.push(root);
				root = root->left;
			}
			else
			{
				TreeNode* peekNode = s.top();
				// if right child exists and traversing node
				// from left child, then move right
				if (peekNode->right != nullptr && lastNodeVisited != peekNode->right)
				{
					root = peekNode->right;
				}
				else
				{
					result.push_back(peekNode->val);
					lastNodeVisited = s.top();
					s.pop();
				}
			}
		}
		return result;
	}
};

int main()
{
	TreeNode* left = new TreeNode(3);
	TreeNode* right = new TreeNode(2);
	right->left = left;

	TreeNode* root = new TreeNode(1);
	root->right = right;

	Solution solution;
	auto zh = solution.postorderTraversal(root);
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
