// 56. Merge Intervals.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// URL: https://leetcode.com/problems/merge-intervals/

// Definition for an interval.
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

bool myfunction(const Interval &lhs, const Interval &rhs) { return (lhs.start < rhs.start); }

class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		if (intervals.size() == 0)
			return vector<Interval>(0);

		sort(intervals.begin(), intervals.end(), [](const Interval &lhs, const Interval &rhs) { return (lhs.start < rhs.start); });

		vector<Interval> result;
		result.push_back(intervals[0]);

		for (size_t i = 1; i < intervals.size(); i++)
		{
			int start = intervals[i].start;
			int end = intervals[i].end;
			int z = 0;
			bool merged = false;
			for (size_t j = 0; j < result.size(); j++)
			{
				if (start <= result[j].start && end >= result[j].end)
				{
					if (!merged)
					{
						result[j] = intervals[i];
						merged = true;
					}
					else
					{
						result.erase(result.begin() + j);
						j--;
					}
				}
				else if (start >= result[j].start && end <= result[j].end)
				{
					merged = true;
				}
				else if (start >= result[j].start && start <= result[j].end)
				{
					if (end > result[j].end)
					{
						result[j].end = end;
					}
					merged = true;
				}
				else if (end >= result[j].start && end <= result[j].end)
				{
					if (start < result[j].start)
					{
						result[j].start = start;
					}
					merged = true;
				}
			}

			if (!merged)
			{
				result.push_back(intervals[i]);
			}

		}

		return result;
	}
};

int main()
{
	Solution solution;
	// [[1,4],[0,5]]
	// vector<Interval> intervals = { Interval(1, 4), Interval(4, 5) };

	// vector<Interval> intervals = { Interval(1, 3), Interval(2, 6), Interval(8, 10), Interval(15, 18) };	

	// [[2,3],[4,5],[6,7],[8,9],[1,10]]
	// vector<Interval> intervals = { Interval(2, 3), Interval(4, 5), Interval(6, 7), Interval(8, 9), Interval(1, 10) };

	// [[2,3],[4,6],[5,7],[3,4]]
	// vector<Interval> intervals = { Interval(2, 3), Interval(4, 6), Interval(5, 7), Interval(3, 4) };
	
	// [[0,2],[2,3],[4,4],[0,1],[5,7],[4,5],[0,0]]
	vector<Interval> intervals = { Interval(0, 2), Interval(2, 3), Interval(4, 4), Interval(0, 1), Interval(5, 7), Interval(4, 5), Interval(0, 0) };

	vector<Interval> anwser = solution.merge(intervals);
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
