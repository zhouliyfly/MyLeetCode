#ifndef _23_H //合并K个排序链表
#define _23_H
#include "MyUtility.h"

#include <vector>
#include <queue>
#include <list>
#include <functional>

struct MyCompare {
	bool operator()(const ListNode* lhs, const ListNode* rhs) const{
		return lhs->val > rhs->val;
	}
};
class Solution_23 {
public:
	ListNode* mergeKLists(std::vector<ListNode*>& lists) {
		if (lists.empty())
			return nullptr;

		std::priority_queue<ListNode*, std::vector<ListNode*>, MyCompare> pq;

		ListNode* dummyNode = new ListNode(-1);
		ListNode* cur = dummyNode;

		for (size_t i = 0; i != lists.size(); i++) {
			if (lists[i] != nullptr) {
				pq.push(lists[i]);
			}
		}
		while (!pq.empty()) {
			auto p = pq.top();
			pq.pop();
			cur->next = p;
			cur = cur->next;
			if (p->next) {
				pq.push(p->next);
			}
		}
		//cur->next = nullptr;
		cur = dummyNode->next;
		delete dummyNode;
		return cur;
	}
};
#endif // !_23_H

