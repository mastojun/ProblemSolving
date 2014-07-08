#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode* mergeKLists(vector<ListNode *> &lists) {
			if(lists.size() == 0) {
				return NULL;
			}
			if(lists.size() == 1) {
				return lists[0];
			}

			return mergeLists(lists, 0, lists.size() - 1);
		}

		ListNode* mergeLists(vector<ListNode*> &lists, int s, int e) {
			if(s == e) {
				return lists[s];
			}
			ListNode *left = mergeLists(lists, s, (s + e)/2);
			ListNode *right= mergeLists(lists, (s + e)/2 + 1, e);

			ListNode* head = NULL, *backNode = NULL;

			while(left != NULL || right != NULL) {
				ListNode** select = &left;
				if(left == NULL) select = &right;
				else if(right != NULL) {
					if(left->val > right->val) select = &right;
				}
				if(backNode == NULL) backNode = *select;
				else{
					backNode->next = *select;
					backNode = *select;
				}
				*select = (*select)->next;

				if(head == NULL) head = backNode;
			}

			return head;
		}
};

int main() {
	return 0;
}
