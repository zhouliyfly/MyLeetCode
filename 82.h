#ifndef _82_H //删除排序链表中的重复元素 II
#define _82_H
#include "MyUtility.h"
class Solution_82 {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* pre = dummy;
		ListNode* cur = pre->next;

		while (cur != nullptr && cur->next != nullptr) {
			ListNode* next = cur->next;
			if (cur->val == next->val) {
				while (next != nullptr && cur->val == next->val) {
					ListNode* delNode = next;
					cur->next = next->next;
					next = next->next;
					delete delNode;
				}
				ListNode* delNode = cur;
				pre->next = cur->next;
				cur = cur->next;
				delete delNode;
			}
			else {
				pre = cur;
				cur = cur->next;
			}
		}
		cur = dummy->next;
		delete dummy;

		return cur;
	}
};
#endif // !_82_H

