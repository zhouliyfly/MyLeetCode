#ifndef _237_H //ɾ�������еĽڵ�
#define _237_H
#include "MyUtility.h"

class Solution_237 {
public:
	// ɾ��ĳ�������и����ģ���ĩβ���ڵ�
	// ��β�ڵ������O(1)ʱ�临�Ӷ����
	void deleteNode(ListNode* node) {
		if (node == nullptr)
			return;

		// ��β�ڵ�node->next != nullptr
		node->val = node->next->val;
		ListNode* delNode = node->next;
		node->next = delNode->next;
		delete delNode;
	}
};
#endif // !_237_H
