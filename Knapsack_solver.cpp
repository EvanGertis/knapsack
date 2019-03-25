#include "pch.h"
#include "Knapsack_solver.h"
/*
File Name: Knapsack_solver.cpp
Author: Evan Gertis.
Date: 03/22/2019.
Purpose: Holds the class Knapsack_solver implementation.
*/


KN::Knapsack_solver::Knapsack_solver(int _numOfItems, int _capacityOfKnapsack, const std::vector<int> &_weights, const std::vector<int> &_values) 
	: m_nNumOfItems(_numOfItems), m_nCapacityOfKnapsack(_capacityOfKnapsack), m_vWeights(_weights), m_vValues(_values)
{
	//initialize the map that stores value and weight pairs.
	m_mapKnapsackTable.resize(m_nNumOfItems + 1);
	
	for (auto &item : m_mapKnapsackTable) {
		item.resize(m_nCapacityOfKnapsack + 1);
	}
}

void KN::Knapsack_solver::operator()()
{
	//loop down rows of values.
	for (int i = 1; i < m_nNumOfItems + 1; ++i)
	{
		//loop across weights.
		for (int w = 1; w < m_nCapacityOfKnapsack + 1; ++w)
		{
			int nNotInclude = m_mapKnapsackTable[i - 1][w];

			int nInclude = 0;

			//gaurd constraint. Weight cannot exceed knapsack capacity.
			if (m_vWeights[i] <= w) {
				nInclude = m_vValues[i] + m_mapKnapsackTable[i - 1][w - m_vWeights[i]];
			}
			
			//calculate the maximum profit.
			m_mapKnapsackTable[i][w] = std::max(nNotInclude, nInclude);
		}
	}

	//Finally max profit is the value of the last cell.
	m_nTotalBenefit = m_mapKnapsackTable[m_nNumOfItems][m_nCapacityOfKnapsack];
}

void KN::Knapsack_solver::showResult()
{
	printf("Total benefit: %d \n", m_nTotalBenefit);

	//start at the lat row and last column.
	for (int i = m_nNumOfItems, w = m_nCapacityOfKnapsack; i > 0; --i) {
		
		//select the item if it differs from the row above.
		if (m_mapKnapsackTable[i][w] != 0 && m_mapKnapsackTable[i][w] != m_mapKnapsackTable[i - 1][w]) {
			printf("Taking item #%d \n", i);
			w = w - m_vWeights[i];
		}
	}
}


KN::Knapsack_solver::~Knapsack_solver()
{
}
