/* Sort List
Sort a linked list in O(n log n) time using constant space complexity.
*/

ListNode *sortList(ListNode *head) {
    if (!head || !head->next) 
        return head;
    
    ListNode *fast = head->next, *slow = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *head2 = slow->next;
    slow->next = NULL;
    
    ListNode *l1 = sortList(head);
    ListNode *l2 = sortList(head2);
    return mergeList(l1, l2);
}

ListNode *mergeList(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode(0);
	ListNode *cur = dummy;
    while (l1 || l2) {
	    if (!l1) {
		    cur->next = l2;
		    l2 = l2->next;
    	} else if (!l2) {
		    cur->next = l1;
		    l1 = l1->next;
	    } else {
		    if (l1->val < l2->val) {
			    cur->next = l1;
			    l1 = l1->next;
		    } else {
			    cur->next = l2;
			    l2 = l2->next;
		    }
	    }
	    cur = cur->next;
    }
    return dummy->next;
}