#ifndef _203_H
#define _203_H
#include "MyUtility.h"

class Solution_203 {
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* pre = dummy;
		ListNode* cur = pre->next;
		while (cur) {
			if (cur->val == val) {
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
#endif // !_203_H

