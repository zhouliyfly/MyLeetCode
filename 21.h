#ifndef _21_H //合并两个有序链表
#define _21_H
#include "MyUtility.h"

class Solution_21 {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* dummy = new ListNode(0);
		ListNode* cur = dummy;
		while (l1 || l2) {
			if (l1 == nullptr) {
				cur->next = l2;
				l2 = l2->next;
				cur = cur->next;
				
			}
			else if (l2 == nullptr) {
				cur->next = l1;
				l1 = l1->next;
				cur = cur->next;
			}
			else {
				if (l1->val <= l2->val) {
					cur->next = l1;
					cur = cur->next;
					l1 = l1->next;
				}
				else { //l1->val > l2->val
					cur->next = l2;
					cur = cur->next;
					l2 = l2->next;
				}
			}
		}
		cur = dummy->next;
		delete dummy;

		return cur;
	}
};
#endif // !_21_H

