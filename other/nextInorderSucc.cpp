/* Inorder traversal successor
   (Damn FB interview question)
*/

// Iterative method
TreeNode* nextInorderSucc(TreeNode *root, TreeNode *n) {
	if (n->right) {     // If the right subtree is not NULL, find min value of right subtree
		return findMin(n->right);
	}
	TreeNode* succ = NULL;
	while (root) {
		if (root->val == n->val) {
			break;
		} else if (root->val > n->val) { 
			succ = root;          // Update the succ variable
			root = root->left;
		} else {
			root = root->right;   // Keep on searching in the right subtree
		}
	}
	return succ;
}

TreeNode* findMin(TreeNode *node) {
	while (node->left) {
		node = node-left;
	}
	return node;
}

