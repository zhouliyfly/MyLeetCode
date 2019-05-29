#ifndef _24_H //两两交换链表中的节点
#define _24_H
#include "MyUtility.h"

class Solution_24 {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* pre = dummy;
		ListNode* cur = head;

		while (cur != nullptr && cur->next != nullptr) {
			ListNode* next = cur->next->next;
			pre->next = cur->next;
			cur->next->next = cur;
			cur->next = next;
			pre = cur;
			cur = next;
		}
		cur = dummy->next;
		delete dummy;

		return cur;
	}
};
#endif // !_24_H

