// 15ThreeSum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
	vector<vector<int>> resVecVec;
	vector<vector<int>> ThreeSum(vector<int> &srcVec)
	{
		if (srcVec.size() < 3)
		{
			return;
		}
		sort(srcVec.begin(), srcVec.end());
		for (int i = 0; i < srcVec.size() - 2; i++)
		{
			if (i > 0 && srcVec[i] == srcVec[i - 1])
			{
				continue;
			}
			TwoSum(srcVec, i + 1, srcVec.size() - 1, srcVec[i]);
		}
		return resVecVec;
	}
	void TwoSum(vector<int> &nums, int begin, int end, int anchor)
	{
		int i = begin;
		int j = end;
		while (i < j)
		{
			if (nums[i] + nums[j] + anchor == 0)
			{
				vector<int> v;
				v.push_back(nums[i]);
				v.push_back(nums[j]);
				v.push_back(anchor);
				resVecVec.push_back(v);
				while (i < j && nums[i] == nums[i + 1])
					++i;  //相等的跳过
				while (i < j && nums[j] == nums[j - 1])
					--j;  //相等的跳过
				++i;
				--j;
			}
			else if (nums[i] + nums[j] + anchor < 0)
			{
				++i;
			}
			else
			{
				--j;
			}
		}
	}
};

int main()
{
	return 0;
}

