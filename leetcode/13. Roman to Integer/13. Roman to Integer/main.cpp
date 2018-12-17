// 13. Roman to Integer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string.h>

// URL: https://leetcode.com/problems/roman-to-integer/
using namespace std;

//I             1
//V             5
//X             10
//L             50
//C             100
//D             500
//M             1000

class Solution {
public:
	int romanToInt(string s) {
		int total = 0;
		string prev;
		for (int index = 0; index < s.length(); index++) {
			std::string cur = s.substr(index, 1);
			switch (*cur.c_str())
			{
			case 'I':
				total += 1;
				break;
			case 'V':
				if (prev.compare("I") == 0)
					total += 3;
				else
					total += 5;
				break;
			case 'X':
				if (prev.compare("I") == 0)
					total += 8;
				else
					total += 10;
				break;
			case 'L':
				if (prev.compare("X") == 0)
					total += 30;
				else
					total += 50;
				break;
			case 'C':
				if (prev.compare("X") == 0)
					total += 80;
				else
					total += 100;
				break;
			case 'D':
				if (prev.compare("C") == 0)
					total += 300;
				else
					total += 500;
				break;
			case 'M':
				if (prev.compare("C") == 0)
					total += 800;
				else
					total += 1000;
				break;
			defaut:
				printf("error!");
			}
			prev = cur;
		}
		return total;
	}
};

int main()
{
	Solution solution;
	int a = solution.romanToInt("III");
	int b = solution.romanToInt("IV");
	int c = solution.romanToInt("IX");
	int d = solution.romanToInt("LVIII");
	int e = solution.romanToInt("MCMXCIV");

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
