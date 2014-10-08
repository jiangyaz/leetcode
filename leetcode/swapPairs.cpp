/* Swap Nodes in Pairs 
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, 
only nodes itself can be changed.
*/

ListNode *swapPairs(ListNode *head) {
	if (head == NULL || head->next == NULL) return head;
	ListNode *guard = new ListNode(0);
	guard->next = head;
	ListNode *p1 = guard, *p2 = head->next, *tmp;

	while (p2) {
		tmp = p1->next;
		p1->next = p2;
		tmp->next = p2->next;
		p2->next = tmp;

		p1 = tmp;
		if (tmp->next == NULL)    // Must check here, otherwise tmp->next->next might give errors
			break;
		else 
			p2 = tmp->next->next;
	}
	return guard->next;
}