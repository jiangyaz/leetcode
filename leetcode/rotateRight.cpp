/* Rotate List 
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

ListNode *rotateRight(ListNode *head, int k) {
	if (head == NULL || k == 0) return head;
	ListNode *p1 = head, *p2 = head;
	// First move p2 pointer k positions forward
	for (int i = 0; i < k; i++) {
		p2 = p2->next;
		if (p2 == NULL) p2 = head;
	}
	// Move p1 and p2 together    
	while (p2->next) {
	    p2 = p2->next;
	    p1 = p1->next;
	}
	
	p2->next = head;
	head = p1->next;
	p1->next = NULL;

	return head;  
}