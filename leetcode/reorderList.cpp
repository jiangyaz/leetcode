/* Reorder List
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/

void reorderList(ListNode *head) {
    stack<ListNode *> rList;
    if (head == NULL) return;
    ListNode *p1 = head, *p2 = head, *tmp = NULL;

    while (p2 && p2->next) {
    	p1 = p1->next;
	    p2 = p2->next;
	    if (p2) p2 = p2->next;
    }

    p2 = p1->next;
    p1->next = NULL;
    while (p2) {
	    rList.push(p2);
	    p2 = p2->next;
    }

    p1 = head;
    while (!rList.empty()) {
	    p2 = rList.top();
	    rList.pop();
	    p2->next = p1->next;
	    p1->next = p2;
	    p1 = p1->next->next;
    }
}