// 101. Symmetric Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

// URL: https://leetcode.com/problems/symmetric-tree/
// WIKI:

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == nullptr)
			return true;

		return isSymmetric(root->left, root->right);
	}

	bool isSymmetric(TreeNode* left, TreeNode* right) {
		if (left == nullptr && right == nullptr)
			return true;

		if (left != nullptr && right != nullptr) {
			if (left->val != right->val) {
				return false;
			}
			return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
		}

		return false;
	}
};

int main()
{
	TreeNode* left1_l = new TreeNode(3);
	TreeNode* left1_r = new TreeNode(4);
	TreeNode* left1 = new TreeNode(2);
	left1->left = left1_l;
	left1->right = left1_r;

	TreeNode* right1_l = new TreeNode(4);
	TreeNode* right1_r = new TreeNode(3);
	TreeNode* right1 = new TreeNode(2);
	right1->left = right1_l;
	right1->right = right1_r;

	TreeNode* root = new TreeNode(1);
	root->left = left1;
	root->right = right1;

	Solution solution;
	auto zh = solution.isSymmetric(root);
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
