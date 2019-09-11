// 979. Distribute Coins in Binary Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
//#include <math.h>
#include <stack>

using namespace std;

// URL: https://leetcode.com/problems/distribute-coins-in-binary-tree/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	int moves = 0;
	stack<TreeNode*> s;
public:
	int distributeCoins(TreeNode* root) {
		postorderTraversal(root);
		return moves;
	}
	

	int postorderTraversal(TreeNode* node) {
		if (node == nullptr)
			return 0;
		int L = postorderTraversal(node->left);
		int R = postorderTraversal(node->right);

		moves += abs(L) + abs(R);
		return node->val + L + R - 1;
	}

	// Approach 2: Iterating method using Stack
	int postorderTraversal2(TreeNode* root) {
		int remain;
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
					int remain = peekNode->val - 1 + remain;
					moves += abs(remain);
					//result.push_back(peekNode->val);
					lastNodeVisited = s.top();
					s.pop();
				}
			}
		}
		return moves;
	}
		//if (root == top)
		//	return moves;

		////root->val += remain;

		//if (root->val == 0)
		//{
		//	moves += 1;
		//	remain -= 1;
		//}
		//else
		//{
		//	int tmp = root->val - moves;
		//	if (tmp < 0)
		//	{
		//		moves -= tmp;
		//	}
		//	else if (tmp == 0)
		//	{
		//		moves += 1;
		//	}
		//	else if (tmp > 0)
		//	{
		//		remain = tmp - 1;
		//		moves += remain;
		//	}
		//	//if (root->val> moves)
		//}
		////else if (root->val > moves)
		////{
		////	moves += root->val - moves - 1;
		////}
		//return moves;
	//}
};

int main()
{
	TreeNode* root = new TreeNode(1);
	TreeNode* left = new TreeNode(0);
	TreeNode* right = new TreeNode(0);
	root->left = left;
	root->right = right;

	TreeNode* l1_right = new TreeNode(5);
	root->left->right = l1_right;

	TreeNode* r1_left = new TreeNode(0);
	TreeNode* r1_right = new TreeNode(0);
	root->right->left = r1_left;
	root->right->right = r1_right;

	Solution s;
	int a = s.distributeCoins(root);


	
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
