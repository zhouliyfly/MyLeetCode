#ifndef _25_H //k��һ�鷭ת����
#define _25_H
#include "MyUtility.h"
#include <cassert>

class Solution_25 {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		assert(k > 0);
		if (k == 1)
			return head;

		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* pre = dummy;
		ListNode* cur = head;
		ListNode* kth = dummy;
		ListNode* pre_k = dummy;

		while ((kth = get_kth_node(pre_k, k))) {
			ListNode* next = cur->next;
			for (int i = 0; i < k; i++) {
				next = cur->next;
				cur->next = pre;
				pre = cur;
				cur = next;
			}
			kth = pre_k->next; // ��ǰ������һ��Ԫ��
			pre_k->next->next = cur;
			pre_k->next = pre;
			pre_k = kth;
		}

		cur = dummy->next;
		delete dummy;

		return cur;
	}
private:
	// ����cur��ĵ�k��Ԫ��
	inline ListNode* get_kth_node(ListNode* cur, int k) {
		ListNode* res = cur;
		for (int i = 0; i < k; i++) {
			if (res == nullptr)
				break;
			res = res->next;
		}
		return res;
	}
};
#endif // !_25_H