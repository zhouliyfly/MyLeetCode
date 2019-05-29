#ifndef _147_H //对链表进行插入排序
#define _147_H
#include "MyUtility.h"

class Solution_147 {
public:
	ListNode* insertionSortList(ListNode* head) {
#if 0
		if (!head || !head->next) return head;

		ListNode* dummyHead = new ListNode(-1);
		dummyHead->next = head;

		ListNode* pre = dummyHead->next;
		while (pre->next) {
			int val = pre->next->val;
			ListNode* next = pre->next->next;
			ListNode* pi = dummyHead;
			for (; pi != pre; pi = pi->next)
				if (pi->next->val > val) {
					ListNode* pj = pi->next;
					ListNode* swapNode = pre->next;

					pi->next = swapNode;
					swapNode->next = pj;
					pre->next = next;

					break;
				}

			if (pi == pre) pre = pre->next;
		}
		return dummyHead->next;
#endif
		if (head == nullptr || head->next == nullptr)
			return head;

		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* pre = head;
		
		while (pre->next != nullptr) {
			ListNode* pi = dummy;
			int val = pre->next->val;
			while (pi != pre) {
				if (pi->next->val > val) { // >=时可以保持稳定排序
					ListNode* swapNode = pre->next;
					ListNode* pj = pi->next;
					pre->next = swapNode->next;
					swapNode->next = pj;
					pi->next = swapNode;
					break;
				}
				pi = pi->next;
			}
			if (pi == pre)
				pre = pre->next;
		}
		ListNode* res = dummy->next;
		delete dummy;

		return res;
	}
};
#endif // !_147_H

