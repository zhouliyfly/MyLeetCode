#ifndef _19_H //删除链表的倒数第N个节点
#define _19_H
#include "MyUtility.h"
#include <cassert>

class Solution_19 {
public:
	// 滑动窗口
	// 题设“给定的 n 保证是有效的”
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* first = dummy;
		ListNode* second = head;
		for (int i = 0; i < n; i++) {
			assert(second != nullptr);
			second = second->next;
		}
		while (second) {
			first = first->next;
			second = second->next;
		}
		ListNode* delNode = first->next;
		assert(delNode != nullptr);
		first->next = delNode->next;
		delete delNode;

		head = dummy->next;
		delete dummy;
		return head;
	}
};
#endif // !_19_H //删除链表的倒数第N个节点

