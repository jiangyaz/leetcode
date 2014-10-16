/* Linked List Cycle
Given a linked list, determine if it has a cycle in it.
*/


bool hasCycle(ListNode *head) {
	ListNode *fastP = head, *slowP = head;
	while (fastP && fastP->next) {
		fastP = fastP->next->next;
		slowP = slowP->next;
		if (fastP == slowP) return true;
	}
    return false;
}