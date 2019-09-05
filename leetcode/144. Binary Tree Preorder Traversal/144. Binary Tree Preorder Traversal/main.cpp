// 144. Binary Tree Preorder Traversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
// URL: https://leetcode.com/problems/binary-tree-preorder-traversal/


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
	vector<int> preorderTraversal(TreeNode* root) {
		if (root == nullptr)
			return result;
		result.push_back(root->val);
		preorderTraversal(root->left);		
		preorderTraversal(root->right);
		return result;
	}

	// Approach 2: Iterating method using Stack
	//vector<int> preorderTraversal(TreeNode* root) {
	//	if (root == nullptr)
	//		return result;
	//	s.push(root);
	//	while (!s.empty())
	//	{
	//		TreeNode* node = s.top();
	//		s.pop();
	//		result.push_back(node->val);
	//		if (node->right != nullptr)
	//			s.push(node->right);
	//		if (node->left != nullptr)
	//			s.push(node->left);
	//	}
	//	return result;
	//}
};

int main()
{
	TreeNode* left = new TreeNode(3);
	TreeNode* right = new TreeNode(2);
	right->left = left;

	TreeNode* root = new TreeNode(1);
	root->right = right;

	Solution solution;
	auto zh = solution.preorderTraversal(root);
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
