#ifndef _2_H //两数相加
#define _2_H
#include "MyUtility.h"

class Solution_2 {
public:
	// 数字不会以0开头
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* dummy = new ListNode(0);
		ListNode* cur = dummy;
		int carry = 0;
		while (l1 || l2) {
			if (l1 == nullptr) {
				cur->next = new ListNode((l2->val + carry) % 10);
				cur = cur->next;
				if (l2->val + carry >= 10)
					carry = 1;
				else
					carry = 0;
				l2 = l2->next;
			}
			else if (l2 == nullptr) {
				cur->next = new ListNode((l1->val + carry) % 10);
				cur = cur->next;
				if (l1->val + carry >= 10)
					carry = 1;
				else
					carry = 0;
				l1 = l1->next;
			}
			else { // l1!=nullptr && l2!=nullprt
				cur->next = new ListNode((l1->val + l2->val + carry) % 10);
				cur = cur->next;
				if (l1->val + l2->val + carry >= 10)
					carry = 1;
				else
					carry = 0;
				l1 = l1->next;
				l2 = l2->next;
			}
			
		}
		if (carry) {
			cur->next = new ListNode(1);
		}
		cur = dummy->next;
		delete dummy;

		return cur;
	}
};
#endif // !_2_H

