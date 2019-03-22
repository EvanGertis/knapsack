#pragma once
#include "pch.h"
/*
File Name: Knapsack_solver.h
Author: Evan Gertis.
Date: 03/22/2019.
Purpose: Holds the class definitions for Knapsack_solver implementation.
*/

/*BEGIN namespace*/
namespace KN {

	/*BEGIN class*/
	class Knapsack_solver
	{
		//members.
		int mNumOfItems;
		int mCapcityOfKnapsack;
		std::vector<std::vector<int>> mKnapsackTable;
		int totalBenefit = 0;
		std::vector<int> mWeights;
		std::vector<int> mValues;

	/**************************************/
	/*************************************/
	/*************************************/
	public:
		Knapsack_solver();
		void operator()();
		void showResult();

		~Knapsack_solver();

	/**************************************/
	/*************************************/
	/*************************************/
	private:

	};
	/*END class*/

}
/*END namespace*/