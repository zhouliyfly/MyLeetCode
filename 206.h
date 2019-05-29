#ifndef _206_H //反转链表
#define _206_H
#include "MyUtility.h"
/**
 * 本题思路非常重要，cur记录当前要操作的节点，next记录cur的下一个节点，pre记录cur的前一个节点
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

