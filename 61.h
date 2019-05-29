#ifndef _61_H //旋转链表
#define _61_H
#include "MyUtility.h"

class Solution_61 {
public:
	// k>0
	ListNode* rotateRight(ListNode* head, int k) {
		// 移动k步，找到从后向前的第k个节点，即为头结点
		// 需要考虑k>n（n为链表节点数）时重复的情形
		// 实际考虑移动k%n次

		// 计算链表节点个数
		int sz = 0;
		
		ListNode* tail = nullptr;
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* cur = dummy;
		while (cur->next) {
			sz++;
			cur = cur->next;
		}
		tail = cur;

		if (sz <= 1 || 0 == k%sz)
			return head;

		// 找到从后向前的第k%sz个节点
		ListNode* first = head;
		ListNode* second = head;
		for (int i = 0; i < k%sz; i++) {
			second = second->next;
		}
		while (second->next) {
			first = first->next;
			second = second->next;
		}

		tail->next = head;
		dummy->next = first->next;
		first->next = nullptr;
		head = dummy->next;
		delete dummy;

		return head;
	}
};
#endif // !_61_H

