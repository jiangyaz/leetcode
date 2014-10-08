/* Remove Nth Node From End of List

Given a linked list, remove the nth node from the end of list and return its head.

For example,
   Given linked list: 1->2->3->4->5, and n = 2.
   After removing the second node from the end, the linked list becomes 1->2->3->5.
*/

ListNode *removeNthFromEnd(ListNode *head, int n) {
	ListNode *dummy = new ListNode(0);     // Think about dummy node for all link-list related problems
    dummy->next = head;

	ListNode *front = head, *back = dummy;
	// Let the front pointer move forward for n nodes
	for (int i = 0; i < n; i++) {
		front = front->next;
	}
	// Let both pointers move together
	while (front) {
		front = front->next;
		back = back->next;
	}
	back->next = back->next->next;
	return dummy->next;
}