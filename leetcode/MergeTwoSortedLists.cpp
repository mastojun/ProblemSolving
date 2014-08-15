class Solution {
	public:
		ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
			ListNode* returnValue = NULL;
			ListNode* result = NULL;

			while(l1 != NULL || l2 != NULL) {
				ListNode** next = &l1;

				if(*next == NULL || (l2 != NULL && (*next)->val > l2->val)) next = &l2;

				if(returnValue == NULL) {
					returnValue = *next;
				}

				if(result != NULL) {
					result->next = *next;
				}
				result = *next;
				(*next) = (*next)->next;
			}

			return returnValue;
		}
};
