// 23MergeKSortedLists.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL)
	{

	}
};
class Solution
{
public:
	//Sort Two List and merge them
	ListNode* MergerTwoList(ListNode *lr, ListNode *lf)
	{
		ListNode *headListNode = new ListNode(-1);
		ListNode *currentListNode = headListNode;
		while (lr!=NULL&&lf!=NULL)
		{
			if (lr->val > lf->val)
			{
				currentListNode->next = lf;
				lf = lf->next;
			}
			else
			{
				currentListNode->next = lr;
				lr = lr->next;
			}
			currentListNode = currentListNode->next;
		}
		if (lr)
		{
			currentListNode->next = lr;
		}
		if (lf)
		{
			currentListNode->next = lf;
		}
		return headListNode->next;
	}
	ListNode* MergeKLists(vector<ListNode *> &lists)
	{
		if (lists.size()==0)
		{
			return NULL;
		}
		int n = lists.size();
		while (n>1)
		{
			int k = (n + 1) / 2;
			for (int i=0;i<n/2;++i)
			{
				lists[i] = MergerTwoList(lists[i], lists[i + k]);
			}
			n = k;
		}
		return lists[0];
	}
};

int main()
{
	ListNode *listr01 = new ListNode(1);
	ListNode *listr02=new ListNode(4);
	ListNode *listr03 = new ListNode(5);
	listr01->next = listr02;
	listr02->next = listr03;
	listr03->next = NULL;

	ListNode *listf01 = new ListNode(1);
	ListNode *listf02 = new ListNode(3);
	ListNode *listf03 = new ListNode(4);
	listf01->next = listf02;
	listf02->next = listf03;
	listf03->next = NULL;
	vector<ListNode *> lists;
	lists.push_back(listr01);
	lists.push_back(listf01);
	Solution solu;
	ListNode *resultList =solu.MergeKLists(lists);
	while (resultList->next!=NULL)
	{
		cout << resultList->val << endl;
		resultList = resultList->next;
	}
	return 0;
}

