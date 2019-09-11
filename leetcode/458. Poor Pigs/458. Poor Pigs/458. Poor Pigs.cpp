// 458. Poor Pigs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

class Solution {
public:
	int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
		if (buckets <= 1)
			return 0;
		float runs = minutesToTest / minutesToDie + 1;
		float test = buckets;
		int pigs = 0;		
		do
		{
			pigs += 1;
			test /= runs;
		} while (test > 1.);
			
		return pigs;
	}
};

int main()
{
	Solution s;
	//int a = s.poorPigs(1000, 15, 60);
	int a = s.poorPigs(4, 15, 15);
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
