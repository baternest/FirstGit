// 709. To Lower Case.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

//URL :

class Solution {
public:
	string toLowerCase(string str) {
		string output;
		for (size_t i = 0; i < str.length(); i++)
		{
			output += lowerChar(str.at(i));
		}
		return output;
	}

	char lowerChar(char c)
	{
		// 65 ~  90: A ~ Z
		// 97 ~ 122: a ~ z
		if (c >= 65 && c <= 90)
			c += 32;
		return c;
	}
};

int main()
{

	string data = "Hello";
	Solution s;
	auto a = s.toLowerCase(data);
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
