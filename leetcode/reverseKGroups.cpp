/* Reverse Nodes in k-Group 
Given a linked list, reverse the nodes of a linked list k at a time and 
return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the 
end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5
*/

ListNode *reverseKGroup(ListNode *head, int k) {
    if (head == NULL) return NULL;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *prev = dummy, *cur = head;
    stack<ListNode *> s;

    while (cur) {
	    int count = k;
	    while (count > 0) {
		    s.push(cur);
		    cur = cur->next;
		    count--;
		    if (!cur && count > 0) return dummy->next;
	    }
	    while (!s.empty()) {
		    prev->next = s.top();
		    s.pop();
		    prev = prev->next;
	    }
	    prev->next = cur;
    }
    return dummy->next;         
}
