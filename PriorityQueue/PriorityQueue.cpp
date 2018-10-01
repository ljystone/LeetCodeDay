// PriorityQueue.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <functional>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL)
	{

	}
};
template<class T>
void print_queue(T &q)
{
	while (!q.empty())
	{
		cout << q.top() << " ";
		q.pop();
	}
}
auto cmp = [](const ListNode *lr, const ListNode*lf)
{
	return lr->val > lf->val;
};
ListNode *mergeKLists(vector<ListNode *> &lists) {
	priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);
	for (int i = 0; i < lists.size(); ++i) {
		if (lists[i]) q.push(lists[i]);
	}
	ListNode *head = NULL, *pre = NULL, *tmp = NULL;
	while (!q.empty()) {
		tmp = q.top();
		q.pop();
		if (!pre) head = tmp;
		else pre->next = tmp;
		pre = tmp;
		if (tmp->next) q.push(tmp->next);
	}
	return head;
}
int main()
{
	priority_queue<int> p;

	for (auto n : { 1,8,5,6,3,4,0,9,7,2 })
	{
		p.push(n);
	}
	print_queue(p);
	priority_queue<int, vector<int>, greater<int>> q;
	for (auto n : { 1,8,5,6,3,4,0,9,7,2 })
	{
		q.push(n);
	}
	print_queue(q);
	return 0;
}

