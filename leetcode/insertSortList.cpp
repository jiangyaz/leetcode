/* Insert Sort List
Sort a linked list using insertion sort.

*/

ListNode *insertionSortList(ListNode *head) {
	ListNode *dummy = new ListNode(0);
	
	while (head) {
		ListNode *cur = dummy, *tmp = NULL;
		while (cur->next && cur->next->val < head->val) {
			cur = cur->next;
		}
		// head should be inserted after cur.
		tmp = head->next;
		head->next = cur->next;
		cur->next = head;
		head = tmp;
	}
	return dummy->next; 
}