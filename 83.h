#ifndef _83_H //删除排序链表中的重复元素
#define _83_H
#include "MyUtility.h"

class Solution_83 {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* cur = head;
		while (cur != nullptr) {
			ListNode* next = cur->next;
			if (next != nullptr) {
				if (cur->val == next->val) {
					cur->next = next->next;
					continue;
				}
			}
			cur = next;
		}
		return head;
	}
};
#endif // !_83_H
