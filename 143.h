#ifndef _143_H //重排链表
#define _143_H
#include "MyUtility.h"

// 1.定位中间节点
// 2.单链表倒转
class Solution_143 {
public:
	void reorderList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return;

		// 定位中间的节点
		ListNode* slow = head;
		ListNode* fast = head->next;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		
		ListNode* head1 = head;
		ListNode* head2 = slow->next;
		slow->next = nullptr;

		// head2链表倒转
		ListNode* curHead2 = head2;
		ListNode* preHead2 = nullptr;
		while (curHead2) {
			ListNode* next = curHead2->next;
			curHead2->next = preHead2;
			preHead2 = curHead2;
			curHead2 = next;
		}
		head2 = preHead2;

		ListNode* dummy = new ListNode(0);
		ListNode* cur = dummy;
		while (head2) {
			cur->next = head1;
			head1 = head1->next;
			cur = cur->next;
			cur->next = head2;
			head2 = head2->next;
			cur = cur->next;
		}
		if (head1) {
			cur->next = head1;
			cur = cur->next;
			cur->next = nullptr;
		}	

		delete dummy;
	}
};
#endif // !_143_H
