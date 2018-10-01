// 02AddTwoNumbers.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int val) :val(val), next(NULL)
	{

	}
};
class Solution
{
public:
	ListNode * AddTwoNumbers(ListNode *lf, ListNode *lr)
	{
		ListNode *headNode=NULL, *preNode=NULL, *curNode = NULL;
		int carryRes = 0;
		while (lf||lr)
		{
			int lfval = lf ? lf->val : 0;
			int lrval = lr ? lr->val : 0;
			int lrAddLfResult = lfval + lrval+carryRes;
			carryRes = lrAddLfResult / 10;
			int res = lrAddLfResult % 10;
			ListNode *curNode = new ListNode(res);
			if (!headNode)
			{
				headNode = curNode;
			}
			if (preNode)
			{
				preNode->next = curNode;
			}
			preNode = curNode;
			lf = lf->next ? lf->next : NULL;
			lr = lr->next ? lr->next : NULL;
			if (carryRes>0)
			{
				ListNode *carry = new ListNode(carryRes);
				preNode->next = carry;
			}
		}
		return headNode;
	}
};

int main()
{
	ListNode *lf = new ListNode(2);
	lf->next = new ListNode(4);
	lf->next->next = new ListNode(3);
	ListNode *lr = new ListNode(5);
	lr->next = new ListNode(6);
	lr->next->next = new ListNode(4);
	Solution slou;
	ListNode *resHeadNode = slou.AddTwoNumbers(lr, lf);
	cout << resHeadNode->next->next->val << endl;
    return 0;
}

