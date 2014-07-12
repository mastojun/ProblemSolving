class Solution {
	public:
		ListNode* deleteDuplicates(ListNode *head) {
			if(head == NULL) return head;

			ListNode* prev = head;
			ListNode* next = head->next;

			while(next != NULL) {
				if(prev->val == next->val) {
					prev->next = next->next;
				} else {
					prev = next;
				}

				next = next->next;
			}

			return head;
		}
};

