#ifndef _92_H
#define _92_H
#include "MyUtility.h" //ListNode

// 1 <= m <= n <= ListNode.size
class Solution_92 {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode* cur = head;
		ListNode* pre = nullptr;
		int i = 1;
		ListNode* m_pre = nullptr;
		ListNode* m_node = nullptr;
		ListNode* n_next = nullptr;
		while (cur != nullptr) {
			ListNode* next = cur->next;
			if (i >= m && i <= n) {
				if (i == m) {
					m_pre = pre;
					m_node = cur;
				}
				cur->next = pre;
				if (i == n) {
					n_next = next;
					break;
				}	
			}
			pre = cur;
			cur = next;
			i++;
		}
		if (m_pre != nullptr)
			m_pre->next = cur;	
		else
			head = cur;
		if(m_node != nullptr)
			m_node->next = n_next;

		return head;
	}
};
#endif // !_92_H

