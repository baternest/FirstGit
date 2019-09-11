// 92. Reverse Linked List II.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

// URL: https://leetcode.com/problems/reverse-linked-list-ii/


// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		/*
		// Empty list
		if (head == nullptr) {
			return nullptr;
		}

		// Move the two pointers until they reach the proper starting point
		// in the list.
		ListNode* prev = nullptr;
		ListNode* curr = head;
		while (m > 1) {
			prev = curr;
			curr = curr->next;
			m--;
			n--;
		}

		// The two pointers that will fix the final connections.
		ListNode* conn = prev;
		ListNode* tail = curr;

		// Iteratively reverse the nodes until n becomes 0.
		ListNode* third = nullptr;
		while (n > 0) {
			third = curr->next;
			curr->next = prev;
			prev = curr;
			curr = third;
			n--;
		}

		// Adjust the final connections as explained in the algorithm
		if (conn != nullptr) {
			conn->next = prev;
		}
		else {
			head = prev;
		}

		tail->next = curr;
		return head;
		*/

		if (m == n || head == nullptr)
			return head;
		ListNode* prev = nullptr;
		ListNode* curr = head;
		int index = 0;
		ListNode* start = nullptr;
		ListNode* conn = nullptr;

		while (curr != nullptr)
		{
			index++;
			if (index > n)
				break;
			else if (index == m)
			{
				start = curr;
				conn = prev;
			}
			//else if (index == n)
			//	end = curr;

			ListNode* nextTemp = curr->next;
			if (index >= m && index <= n)
				curr->next = prev;

			prev = curr;
			curr = nextTemp;
		}

		start->next = curr;
		if (conn != nullptr)
		{
			conn->next = prev;
			return head;
		}
		else
		{
			return prev;
		}
	}
};
int main()
{
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);

	//ListNode* head = new ListNode(3);
	//head->next = new ListNode(5);


	Solution s;
	//auto a = s.reverseBetween(head, 3, 4);
	auto a = s.reverseBetween(head, 1, 5);


	std::cout << "Hello World!\n";
}

//[1, 2, 3]
//2
//3
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
