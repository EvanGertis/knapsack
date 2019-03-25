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
		int m_nNumOfItems;
		int m_nCapacityOfKnapsack;
		std::vector<std::vector<int>> m_mapKnapsackTable;
		int m_nTotalBenefit = 0;
		std::vector<int> m_vWeights;
		std::vector<int> m_vValues;

	/**************************************/
	/*************************************/
	/*************************************/
	public:
		Knapsack_solver(int numOfItems, int capacityOfKnapsack, const std::vector<int> &weights, const std::vector<int> &values);
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