/* Linked List Cycle II 
Given a linked list, return the node where the cycle begins. 
If there is no cycle, return null.
*/

ListNode *detectCycle(ListNode *head) {
	ListNode *fastP = head, *slowP = head;

	while (fastP && fastP->next) {
		fastP = fastP->next->next;
		slowP = slowP->next;
		if (!fastP) return NULL;
		if (slowP == fastP) break;
	}  

	slowP = head;
	while (slowP && fastP) {
		slowP = slowP->next;
		fastP = fastP->next;
		if (slowP == fastP) break;
	}
	return slowP;
}