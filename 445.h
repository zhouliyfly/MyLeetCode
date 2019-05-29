#ifndef _445_H
#define _445_H
#include "MyUtility.h"
#include <stack>

class Solution_445 {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		std::stack<int> s1;
		std::stack<int> s2;
		while (l1) {
			s1.push(l1->val);
			l1 = l1->next;
		}
		while (l2) {
			s2.push(l2->val);
			l2 = l2->next;
		}
		int carry = 0;
		std::stack<int> s;
		while (!s1.empty() || !s2.empty()) {
			if (s1.empty()) {
				//cur->next = new ListNode((s2.top() + carry) % 10);
				s.push((s2.top() + carry) % 10);
				if (s2.top() + carry >= 10)
					carry = 1;
				else
					carry = 0;
				s2.pop();
				//cur = cur->next;
			}
			else if (s2.empty()) {
				//cur->next = new ListNode((s1.top() + carry) % 10);
				s.push((s1.top() + carry) % 10);
				if (s1.top() + carry >= 10)
					carry = 1;
				else
					carry = 0;
				s1.pop();
				//cur = cur->next;
			}
			else {
				//cur->next = new ListNode((s1.top() + s2.top() + carry) % 10);
				s.push((s1.top() + s2.top() + carry) % 10);
				if (s1.top() + s2.top() + carry >= 10)
					carry = 1;
				else
					carry = 0;
				s1.pop();
				s2.pop();
				//cur = cur->next;
			}
		}
		if (carry)
			s.push(1);
		ListNode* dummy = new ListNode(0);
		ListNode* cur = dummy;
		while (!s.empty()) {
			cur->next = new ListNode(s.top());
			s.pop();
			cur = cur->next;
		}
		cur = dummy->next;
		delete dummy;

		return cur;
	}
};
#endif // !_445_H

