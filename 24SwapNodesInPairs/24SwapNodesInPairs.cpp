// 24SwapNodesInPairs.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <memory>
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
	ListNode *SwapListNodePairs(ListNode *head)
	{
		ListNode *newHead = NULL;
		
		ListNode *preNode = head;
		ListNode *curNode = head->next;
		//ListNode *nextNode = head->next->next;
		//shared_ptr<ListNode> newHead(curNode) ;
		while (!curNode)
		{
		    ListNode *nextNode = curNode->next;
			curNode->next = preNode;
			preNode = nextNode;
			curNode = nextNode->next;
			
		}
		return newHead;
	}
};

int main()
{
    return 0;
}

