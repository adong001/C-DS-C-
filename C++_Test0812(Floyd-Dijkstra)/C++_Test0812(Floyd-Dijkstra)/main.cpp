#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == nullptr)
	{
		return pHead2;
	}

	if (pHead2 == nullptr)
	{
		return pHead1;
	}
	ListNode* newHead = nullptr;
	ListNode* newTail = nullptr;
	while (pHead1 && pHead2)
	{
		if (pHead1->val < pHead2->val)
		{
			newTail = pHead1;
			pHead1 = pHead1->next;
		}
		else
		{
			newTail = pHead2;
			pHead2 = pHead2->next;
		}
		if (newHead == nullptr)//��һ�β���
		{
			newHead = newTail;
		}
		newTail = newTail->next;
	}

	if (pHead1 != nullptr)//��pHeadÿһ������
	{
		newTail = pHead1;
	}
	else
	{
		newTail = pHead2;
	}
	return newHead;
}
int main()
{
	
	ListNode p1(1);
	ListNode p2(3);
	ListNode p3(5);
	ListNode p4(2);
	ListNode p5(4);
	ListNode p6(6);
	p1.next = &p2;
	p2.next = &p3;
	p4.next = &p5;
	p5.next = &p6;
	Merge(&p1, &p4);
    return 0;
}