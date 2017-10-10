// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>    // std::max
#include <iostream>
using namespace std;

int dpKnapSack(int maxWeight, int numItems, int w[], int v[])
{
	//notice the dimensions should be numItems+1,maxWeight+1, not numItems, maxWeight, 
	vector<vector<int> > dp(numItems+1, vector<int>(maxWeight+1, 0)); 
	//No need to begin with i=0 and j=0, because the dp[0][j] or dp[i][0] are zeros and they 
	//are already initialized
	for (int i = 1; i <= numItems; i++)
	{
		for (int j = 1; j <= maxWeight; j++)
		{
			if (j - w[i] >= 0) //Pay attention to the constraint here
			{
				dp[i][j] = max(dp[i - 1][j], dp[i-1][j - w[i]] + v[i]);
			}
			else
			{
				dp[i][j] = dp[i - 1][j]; 
			}
		}
	}
	return dp[numItems][maxWeight];
}

int main()
{
	int maxWeight = 10;
	int numItems = 5;
	int w[] = { 0,3,6,3,8,6 };
	int v[] = { 0,4,6,6,12,10 };
	int maxVal = dpKnapSack(maxWeight, numItems, w, v);
	cout << "The maximum value is:" << maxVal << endl;
    return 0;
}

