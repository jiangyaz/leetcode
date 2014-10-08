/* Reverse Linked List
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.
*/

ListNode *reverseBetween(ListNode *head, int m, int n) {
	ListNode *guard = new ListNode(0);
	guard->next = head;
	ListNode *p1 = guard, *p2 = guard;
	// Step 1: move p1 forward m - 1 positions, p2 forward n positions
	for (int i = 0; i < n; i++) {
		if (i < m-1) {
			p1 = p1->next;
		}
		p2 = p2->next;
	}
	// Step 2: 
	ListNode *tmp = p1->next;
	p1->next = p2;
	p1 = tmp;
	// Step 3: 
	while (p1 != p2) {
		tmp = p1->next;
		p1->next = p2->next;
		p2->next = p1;
		p1 = tmp;
	}
	return guard->next;
}