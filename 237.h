#ifndef _237_H //删除链表中的节点
#define _237_H
#include "MyUtility.h"

class Solution_237 {
public:
	// 删除某个链表中给定的（非末尾）节点
	// 非尾节点可以在O(1)时间复杂度完成
	void deleteNode(ListNode* node) {
		if (node == nullptr)
			return;

		// 非尾节点node->next != nullptr
		node->val = node->next->val;
		ListNode* delNode = node->next;
		node->next = delNode->next;
		delete delNode;
	}
};
#endif // !_237_H

