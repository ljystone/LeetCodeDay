// 48RotateImage.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
	void RoateImage(vector<vector<int>> &matrix)
	{
		int rowCount = matrix.size();
		int coloumCount = matrix[0].size();
		for (int i = 0; i < rowCount; i++)
		{
			matrix.push_back(matrix[i]);
		}
		int newRowCount = 2 * rowCount;
		for (int i = 0; i < rowCount; i++)
		{
			for (int j = newRowCount - 1; j >= rowCount; --j)
			{

				matrix[i][newRowCount - 1 - j] = matrix[j][i];

				cout << matrix[j][i] << endl;
			}
		}
		for (int i = 0; i < rowCount; i++)
		{
			matrix.pop_back();
		}

	}
};
int main()
{
	vector<vector<int>> matrix = {
		{5, 1, 9,11},
		{2, 4, 8, 10},
		{13, 3, 6, 7},
		{15, 14, 12, 16}
	};
	Solution *sol = new Solution();
	sol->RoateImage(matrix);

	return 0;
}

