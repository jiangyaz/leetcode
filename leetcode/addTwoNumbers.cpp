/* Add two numbers
You are given two linked lists representing two non-negative numbers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
	ListNode *p1 = l1, *p2 = l2;
	int carry = 0;
	ListNode *head = NULL, *p;

	while (p1 || p2 || carry > 0) {
		int val1 = (p1 == NULL) ? 0 : p1->val;
		int val2 = (p2 == NULL) ? 0 : p2->val;

		int sum = val1 + val2 + carry;
		ListNode *newNode = new ListNode(sum % 10);
		carry = sum/10;

		if (head == NULL) {
			head = newNode;
			p = head;
		} else { 
			p->next = newNode;
			p = p->next;
		}
		if (p1) p1 = p1->next;
		if (p2) p2 = p2->next;
	}

	return head;
}