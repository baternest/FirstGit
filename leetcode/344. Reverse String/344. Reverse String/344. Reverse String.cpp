// 344. Reverse String.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

// URL: https://leetcode.com/problems/reverse-string/

class Solution {
public:
	void reverseString(vector<char>& s) {
		int len = s.size();
		for (int i = 0; i < len / 2; i++)
		{
			char tmp = s[i];
			s[i] = s[len - i - 1];
			s[len - i - 1] = tmp;
		}
	}
};

int main()
{
	vector<char> data;
	data.push_back('h');
	data.push_back('e');
	data.push_back('l');
	data.push_back('l');
	data.push_back('o');

	Solution s;
	s.reverseString(data);

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
