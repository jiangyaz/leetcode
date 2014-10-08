/* Merge Two Sorted Lists
Merge two sorted linked lists and return it as a new list. The new list should be made 
by splicing together the nodes of the first two lists.
*/
 
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
	ListNode *head = new ListNode(0);
	ListNode *p = head;  

	while (l1 || l2) {
		if (l1 == NULL) {
			p->next = l2;
			l2 = l2->next;
		} else if (l2 == NULL) {
			p->next = l1;
			l1 = l1->next;
		} else {
			if (l1->val >= l2->val) {
				p->next = l2;
				l2 = l2->next;
			} else {
				p->next = l1;
				l1 = l1->next;
			}
		}
		p = p->next;
	}  
	return head->next;    
}