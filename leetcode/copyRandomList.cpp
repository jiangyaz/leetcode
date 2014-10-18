/* Copy List with Random Pointer 
A linked list is given such that each node contains an additional 
random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/

RandomListNode *copyRandomList(RandomListNode *head) {
	if (head == NULL)  return NULL;
	RandomListNode *cur = head;

	// Create a copy and attach after it's original node.
	while (cur) {
		RandomListNode *copy = new RandomListNode(cur->val);
		copy->next = cur->next;
		cur->next = copy;
		cur = copy->next;
	}     
	// Copy the random pointer
	cur = head;
	while (cur) {
		if (cur->random) {
			cur->next->random = cur->random->next;
		}
		cur = cur->next->next;
	}   
	// Break down into 2 Lists;
	RandomListNode *headCopy = head->next;
	RandomListNode *curCopy = headCopy, *tmp = NULL;
	cur = head;
	while (curCopy->next) {
		tmp = curCopy->next;
		curCopy->next = tmp->next
		cur->next = tmp;
		
		cur = cur->next;
		curCopy = curCopy->next;
	}
	cur->next = NULL;
	return headCopy;
}