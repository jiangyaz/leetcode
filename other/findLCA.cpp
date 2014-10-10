/* Lowest Common Ancestor Binary Tree

Given a binary tree, find the lowest common ancestor of two given nodes in the tree.

*/

// Time complexity: O(n)
// Assume that n1 and n2 are present in the tree.
TreeNode *LCA(TreeNode *root, TreeNode *n1, TreeNode *n2) {
	if (root == NULL) return NULL;

	if (root->val == n1->val || root->val == n2->val) 
		return root;

	TreeNode *leftLCA = LCA(root->left, n1, n2);
	TreeNode *rightLCA = LCA(root->right, n1, n2);

	if (leftLCA && rightLCA) return root;

	return (leftLCA == NULL) ? rightLCA : leftLCA;
}