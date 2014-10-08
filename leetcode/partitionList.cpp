/* Partiion List
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/

ListNode *partition(ListNode *head, int x) {
	if (head == NULL) return NULL;
	ListNode *guard = new ListNode(0);
    guard->next = head;
	ListNode *p1 = guard, *p2 = NULL, *tmp = NULL;

	while (p1->next && p1->next->val < x)
		p1 = p1->next;

	p2 = p1->next;
	while (p2) {
		if (p2->next && p2->next->val < x) {
			tmp = p2->next;
			p2->next = p2->next->next;
			tmp->next = p1->next;
			p1->next = tmp;
			p1 = p1->next;
		} else {
			p2 = p2->next;
		}
	}
	return guard->next;
}