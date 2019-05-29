#ifndef _86_H //分隔链表
#define _86_H
#include "MyUtility.h"

// 题设并没有明确说明是否可以改变节点的值
class Solution_86 {
public:
	// 改变节点的值
	ListNode* partition(ListNode* head, int x) {
		
		ListNode* dummyNode = new ListNode(0);
		ListNode* r = dummyNode;
		dummyNode->next = head;
		//[head...r] < x, [r+1...) >= x

		ListNode* cur = head;
		ListNode* pre = dummyNode;
		while (cur != nullptr) {
			if (cur->val < x) {
				if (cur != r->next) {
					//ListNode* tmp = cur->next;
					pre->next = cur->next;
					cur->next = r->next;
					r->next = cur;
					cur = pre->next;
					r = r->next;
				}
				else {
					r = r->next;
					pre = cur;
					cur = cur->next;
				}
				
			}
			else {
				pre = cur;
				cur = cur->next;
			}	
		}
		head = dummyNode->next;
		delete dummyNode;

		return head;
	}
};
#endif // !_86_H
