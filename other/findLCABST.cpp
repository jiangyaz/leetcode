/* Lowest Common Ancestor BST

Given a binary search tree (BST), find the lowest common ancestor of two 
given nodes in the BST.
*/ 

// Recursive method
// Time complexity: O(h), h - height of tree
// Space complexity: O(h), h - height of tree

TreeNode *LCA(TreeNode *root, TreeNode *n1, TreeNode *n2) {
	if (root == NULL) return NULL;

	if (root->val < n1->val && root->val < n2->val) 
		return LCA(root->left, n1, n2);
	
	if (root->val > n1->val && root->val > n2->val) 
		return LCA(root->right, n1, n2);

	return root;
}


// Iterative method
// Time complexity: O(h), h - height of tree
// Space complexity: O(1)
TreeNode *LCA(TreeNode *root, TreeNode *n1, TreeNode *n2) {
	while (root) {
		if (root->val < n1->val && root->val < n2->val) 
			root = root->left;
		else if (root->val > n1->val && root->val > n2->val) 
			root = root->right;
		else 
			break;
	}
	return root;
}