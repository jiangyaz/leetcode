/* Populating Next Right Pointers in Each Node
Given a binary tree
    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, 
the next pointer should be set to NULL. Initially, all next pointers are set to NULL.

Note:
You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, 
and every parent has two children).
*/

void connect(TreeLinkNode *root) {
	if (root == NULL) return;
	if (!root->left && !root->right) return;

	// Connect the left to the right
	root->left->next = root->right;    
	// Connect right to parent's next's left child
	root->right->next = root->next ? root->next->left : NULL; 
	connect(root->right);
	connect(root->left);  
}
