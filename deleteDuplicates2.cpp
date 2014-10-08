/* Remove Duplicates from Sorted List II 
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

ListNode *deleteDuplicates(ListNode *head) {
	if (head == NULL) return NULL;
	
	ListNode *dummy = new ListNode(0);
	dummy->next = head;
	ListNode *cur = head, *prev = dummy; 

	while (cur && cur->next) {
		while (cur->next && cur->val == cur->next->val) {
			cur = cur->next;
		}
		if (prev->next != cur) {     // Case 1: it's a duplicate, skip it
			prev->next = cur->next;
		} else {					 // Case 2: unique value, move prev pointer
			prev = prev->next;
		}	
		cur = cur->next;	
	}
	return dummy->next;
}

