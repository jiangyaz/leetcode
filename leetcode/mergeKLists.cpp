/* Merge k Sorted Lists
Merge k sorted linked lists and return it as one sorted list. 
Analyze and describe its complexity.
*/

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *head = new ListNode(0);
    ListNode *p = head;  

    while (l1 || l2) {
	    if (l1 == NULL) {
		    p->next = l2;
		    l2 = l2->next;
	    } else if (l2 == NULL) {
		    p->next = l1;
		    l1 = l1->next;
	    } else {
		    if (l1->val >= l2->val) {
			    p->next = l2;
			    l2 = l2->next;
		    } else {
			    p->next = l1;
			    l1 = l1->next;
		    }
	    }
	    p = p->next;
    }  
    return head->next;    
}

ListNode *mergeKLists(vector<ListNode *> &lists) {
    int n = lists.size();
    if (n == 0) return NULL;
    while (n > 1) {
        int k = (n+1)/2;
        for (int i = 0; i < n/2; i++) {
            lists[i] = mergeTwoLists(lists[i], lists[i+k]);
        }
        n = k;
    }
    return lists[0];
}