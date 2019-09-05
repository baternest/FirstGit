// 94. Binary Tree Inorder Traversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <stack>

// URL: https://leetcode.com/problems/binary-tree-inorder-traversal/
// WIKI: https://en.wikipedia.org/wiki/Tree_traversal

using namespace std;
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
	//vector<int> inorderTraversal(TreeNode* root) {
	//	if (root == nullptr)
	//		return result;
	//	inorderTraversal(root->left);
	//	result.push_back(root->val);
	//	inorderTraversal(root->right);
	//	return result;
	//}

	// Approach 2: Iterating method using Stack
	//vector<int> inorderTraversal(TreeNode* root) {
	//	while (!s.empty() or root != nullptr)
	//	{
	//		if (root != nullptr)
	//		{
	//			s.push(root);
	//			root = root->left;
	//		}
	//		else
	//		{
	//			root = s.top();
	//			s.pop();
	//			result.push_back(root->val);
	//			root = root->right;
	//		}
	//	}
	//	return result;
	//}

	// Approach 3: Morris Traversal
	vector<int> inorderTraversal(TreeNode* root) {
		TreeNode* curr = root;
		TreeNode* pre;
		while (curr != nullptr) {
			if (curr->left == nullptr) {
				result.push_back(curr->val);
				curr = curr->right; // move to next right node
			}
			else { // has a left subtree
				pre = curr->left;
				while (pre->right != nullptr) { // find rightmost
					pre = pre->right;
				}
				pre->right = curr; // put cur after the pre node
				TreeNode* temp = curr; // store cur node
				curr = curr->left; // move cur to the top of the new tree
				temp->left = nullptr; // original cur left be null, avoid infinite loops
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
	auto zh = solution.inorderTraversal(root);
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
