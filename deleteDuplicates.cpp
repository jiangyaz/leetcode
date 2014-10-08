/* Remove Duplicates from Sorted List

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/ 

ListNode *deleteDuplicates(ListNode *head) {
	if (head == NULL) return NULL;
	ListNode *checkNode = head->next, *curNode = head;
	int lastVal = head->val;

	while (checkNode) {
		if (checkNode->val != lastVal) {
			curNode->next = checkNode;
			curNode = curNode->next;
			lastVal = checkNode->val;
		}
		checkNode = checkNode->next;
	}
	curNode->next = NULL;
	return head;
}