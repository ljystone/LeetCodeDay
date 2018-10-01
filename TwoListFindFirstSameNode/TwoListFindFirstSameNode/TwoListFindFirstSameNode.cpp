// TwoListFindFirstSameNode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<map>
#include <iostream>
#include <unordered_map>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int val) :val(val), next(NULL)
	{}

};
class Solution
{
public:
	ListNode *sameNode = NULL;
	ListNode * FindSameNode(ListNode *lf, ListNode *lr)
	{
		unordered_map<ListNode *, int> umap;
		while (lf)
		{
			umap.insert(make_pair(lf, 1));
			lf = lf->next;
		}
		while (lr)
		{
			if (umap.count(lr) > 0)
			{
				return lr;
			}
			lr = lr->next;
		}
		return NULL;
	}
};
typedef union 
{
	int a;
	short b;
}UN_T;
int main()
{
	
	return 0;
}

