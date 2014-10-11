/* Convert Sorted List to Binary Search Tree

Given a singly linked list where elements are sorted in ascending order, 
convert it to a height balanced BST.
*/


TreeNode *sortedListToBST(ListNode *head) {
	int len = 0;
	ListNode *cur = head;
	while (cur) {
		len++;
		cur = cur->next;
	}        
	return listToBST(head, 0, len-1);
}

TreeNode *listToBST(ListNode* &head, int start, int end) {  // don't forget the & sign
	if (start > end) return NULL;
	int mid = (start + end)/2;
	
	TreeNode *leftTree = listToBST(head, start, mid-1);
	
	TreeNode *root = new TreeNode(head->val);
	head = head->next;
	
	TreeNode *rightTree = listToBST(head, mid+1, end);

	root->left = leftTree;
	root->right = rightTree;
	return root;
}