#ifndef _206_H //��ת����
#define _206_H
#include "MyUtility.h"
/**
 * ����˼·�ǳ���Ҫ��cur��¼��ǰҪ�����Ľڵ㣬next��¼cur����һ���ڵ㣬pre��¼cur��ǰһ���ڵ�
 **/
 //struct ListNode {
 //	int val;
 //	ListNode *next;
 //	ListNode(int x) : val(x), next(nullptr) {}
 //};

class Solution_206 {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* cur = head;
		ListNode* pre = nullptr;

		while (cur != nullptr) {
			ListNode* next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		return pre;
	}
};

#endif // !_206_H
