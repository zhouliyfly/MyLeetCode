#ifndef _234_H //回文链表
#define _234_H
#include "MyUtility.h"

// O(n) 时间复杂度和 O(1) 空间复杂度
class Solution_234 {
public:
	bool isPalindrome(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return true;

		ListNode* slow = head;
		ListNode* fast = head->next;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode* head2 = slow->next;
		ListNode* head1 = head;
		slow->next = nullptr;
		// 倒转链表
		ListNode* pre = nullptr;
		ListNode* cur = head2;
		while (cur) {
			ListNode* next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		head2 = pre;

		while (head2) {
			if (head1->val != head2->val)
				return false;
			head1 = head1->next;
			head2 = head2->next;
		}
		return true;
	}
};
#endif // !_234_H

