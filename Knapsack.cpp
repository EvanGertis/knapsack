/* 
File Name: Knapsack.cpp  
Author: Evan Gertis
Date: 03/22/2019
Purpose: This file contains the 'main' function. Program execution begins and ends there.
*/
#include "pch.h"
#include "Knapsack_solver.h"
//main entry point.

int main()
{
	std::vector<int> weights	= { 0, 4, 2, 3 };
	std::vector<int> values = { 0, 10, 4, 7 };
	KN::Knapsack_solver kn(3,5,weights,values);

	kn();
	kn.showResult();
	
}


