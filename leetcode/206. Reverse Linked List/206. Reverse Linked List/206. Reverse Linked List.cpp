// 206. Reverse Linked List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

// URL: https://leetcode.com/problems/reverse-linked-list/

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	ListNode* result;
public:
	// Approach #1 (Iterative)
	ListNode* reverseList(ListNode* head) {
		ListNode* prev = nullptr;
		ListNode* curr = head;

		while (curr != nullptr)
		{
			ListNode* nextTemp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = nextTemp;
		}

		return prev;
	}

	// Approach #2 (Recursive)
	ListNode* reverseList2(ListNode* head)
	{
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode* p = reverseList2(head->next);
		head->next->next = head;
		head->next = nullptr;
		return p;
	}

};

int main()
{
	/*
	Input: 1->2->3->4->5->NULL
	Output: 5->4->3->2->1->NUL
	*/
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);


	Solution s;
	auto a = s.reverseList(head);
	auto b = s.reverseList2(a);
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
