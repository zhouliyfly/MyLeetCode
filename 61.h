#ifndef _61_H //��ת����
#define _61_H
#include "MyUtility.h"

class Solution_61 {
public:
	// k>0
	ListNode* rotateRight(ListNode* head, int k) {
		// �ƶ�k�����ҵ��Ӻ���ǰ�ĵ�k���ڵ㣬��Ϊͷ���
		// ��Ҫ����k>n��nΪ�����ڵ�����ʱ�ظ�������
		// ʵ�ʿ����ƶ�k%n��

		// ���������ڵ����
		int sz = 0;
		
		ListNode* tail = nullptr;
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* cur = dummy;
		while (cur->next) {
			sz++;
			cur = cur->next;
		}
		tail = cur;

		if (sz <= 1 || 0 == k%sz)
			return head;

		// �ҵ��Ӻ���ǰ�ĵ�k%sz���ڵ�
		ListNode* first = head;
		ListNode* second = head;
		for (int i = 0; i < k%sz; i++) {
			second = second->next;
		}
		while (second->next) {
			first = first->next;
			second = second->next;
		}

		tail->next = head;
		dummy->next = first->next;
		first->next = nullptr;
		head = dummy->next;
		delete dummy;

		return head;
	}
};
#endif // !_61_H
