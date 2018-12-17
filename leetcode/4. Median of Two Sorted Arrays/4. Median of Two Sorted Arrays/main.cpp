// 4. Median of Two Sorted Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

// URL: https://leetcode.com/problems/median-of-two-sorted-arrays/
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int totalLength = nums1.size() + nums2.size();
		int i = 0;
		int j = 0;

		int prev = 0;
		int prevprev = 0;

		for (int k = 0; k <= totalLength / 2; k++)
		{
			if (i < nums1.size() && j < nums2.size())
			{
				if (nums1[i] < nums2[j])
				{
					prevprev = prev;
					prev = nums1[i];
					i++;
				}
				else
				{
					prevprev = prev;
					prev = nums2[j];
					j++;
				}
			}
			else if (i >= nums1.size())
			{
				prevprev = prev;
				prev = nums2[j];
				j++;
			}
			else
			{
				prevprev = prev;
				prev = nums1[i];
				i++;
			}
		}

		if (totalLength % 2 == 1)
		{
			return prev;
		}
		else
		{
			return (prev + prevprev) / 2.0;
		}
	}
};

int main()
{
	vector<int> nums1 = { 1, 3 };
	vector<int> nums2 = { 2 };
	Solution solution;
	double a = solution.findMedianSortedArrays(nums1, nums2);

	nums1 = { 1, 2 };
	nums2 = { 3, 4 };
	double b = solution.findMedianSortedArrays(nums1, nums2);

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
