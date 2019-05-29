#ifndef _328_H
#define _328_H
#include "MyUtility.h"

class Solution_328 {
public:
	ListNode* oddEvenList(ListNode* head) {
		ListNode* odd = head;
		ListNode* pre_odd = head;
		ListNode* pre = head;
		if (odd == nullptr || (pre = odd->next) == nullptr || (odd = odd->next->next) == nullptr)
			return head;

		while (odd != nullptr) {
			pre->next = odd->next;
			odd->next = pre_odd->next;
			pre_odd->next = odd;
			pre_odd = pre_odd->next;
			if (pre->next == nullptr || pre->next->next == nullptr) {
				break;
			}
			pre = pre->next;
			odd = pre->next;
		}
		return head;
	}
};
#endif //!_328_H
