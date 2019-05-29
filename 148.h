#ifndef _148_H //排序链表, O(n log n) 时间复杂度和常数级空间复杂度
#define _148_H
#include "MyUtility.h"

class Solution_148 {
public:
	ListNode* sortList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return head;

		ListNode* slow = head;
		ListNode* fast = head->next;

		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode* head2 = slow->next;
		slow->next = nullptr;
		head = sortList(head);
		head2 = sortList(head2);

		return merge(head, head2);
	}

	ListNode* sortList_no_rec(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return head;

		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* cur = dummy;		

		int size = 1;
		while (size) {
			ListNode* pre = dummy;
			ListNode* cur = dummy;

			while (cur->next) {
				cur = pre;
				for (int i = 0; i < size && cur->next; i++) {
					cur = cur->next;
				}
				if (cur->next) {
					ListNode* pre2 = cur;
					for (int i = 0; i < size && cur->next; i++) {
						cur = cur->next;
					}
					ListNode* tail = nullptr;
					ListNode* next = cur->next;
					ListNode* head2 = pre2->next;
					pre2->next = nullptr;
					cur->next = nullptr;

					pre->next = merge_2(pre->next, head2, tail);
					pre = tail;
					pre->next = next;
				}
				if (pre == dummy)
					size = 0;
			}
			size *= 2;
		}
		
		cur = dummy->next;
		delete dummy;

		return cur;
	}

private:
	ListNode* merge(ListNode* head1, ListNode* head2) {
		ListNode* dummy = new ListNode(0);
		ListNode* cur = dummy;
		while (head1 && head2) {
			if(head1->val <= head2->val){
				cur->next = head1;
				cur = cur->next;
				head1 = head1->next;
				cur->next = nullptr;
			}
			else {
				cur->next = head2;
				cur = cur->next;
				head2 = head2->next;
				cur->next = nullptr;
			}
		}
		if (head1 == nullptr) {
			cur->next = head2;
		}
		else if (head2 == nullptr) {
			cur->next = head1;
		}
		cur = dummy->next;
		delete dummy;
		return cur;
	}

	ListNode* merge_2(ListNode* head1, ListNode* head2, ListNode* &tail) {
		ListNode* dummy = new ListNode(0);
		ListNode* cur = dummy;
		while (head1 && head2) {
			if (head1->val <= head2->val) {
				cur->next = head1;
				cur = cur->next;
				head1 = head1->next;
				cur->next = nullptr;
			}
			else {
				cur->next = head2;
				cur = cur->next;
				head2 = head2->next;
				cur->next = nullptr;
			}
		}
		if (head1 == nullptr) {
			cur->next = head2;
		}
		else if (head2 == nullptr) {
			cur->next = head1;
		}

		while (cur->next) {
			cur = cur->next;
		}
		tail = cur;
		
		cur = dummy->next;
		delete dummy;
		return cur;
	}
};
#endif // !_148_H
