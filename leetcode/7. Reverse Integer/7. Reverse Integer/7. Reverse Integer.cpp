// 7. Reverse Integer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

// URL: https://leetcode.com/problems/reverse-integer/

#pragma warning (disable : 4146)

int multipleOvf(int* result, int a, int b)
{
	if (a > INT_MAX / b)
		return -1;
	else
	{
		return a * b;
		return 0;
	}
}


class Solution {
public:
	int reverse(int x) {
		int source = x;
		long result = 0;
		bool is_continue = true;
		do
		{
			int tmp = x % 10;
			x /= 10;
			if (x == 0)
			{
				is_continue = false;

				if ((source < 0 && result < INT_MIN / 10) ||
					(source > 0 && result > INT_MAX / 10))
				{
					return 0;
				}
				else
				{
					result = (result * 10) + tmp;
				}
			}
			else
			{
				result = (result * 10) + tmp;
			}
		} while (is_continue);

		return (int)result;
	}
};

int main()
{
	Solution s;
	//1534236469
	//int a = s.reverse(1534236469);
	//int b = s.reverse((int)-2147483648);

	int c = s.reverse(1463847412);
	
	
	//int a = s.reverse(-123);
	//2147483647
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
