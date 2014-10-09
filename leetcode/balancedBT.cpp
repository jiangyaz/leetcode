/* Balanced Binary Tree

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree 
in which the depth of the two subtrees of every node never differ by more than 1.

*/

int maxDepth(TreeNode *node) {
	if (node == NULL) 
		return 0;
	else 
		return max(maxDepth(node->left), maxDepth(node->right)) + 1;
}

bool isBalanced(TreeNode *root) {
	if (root == NULL)
		return true;
	else if (abs(maxDepth(root->left) - maxDepth(root->right)) > 1)
		return false;
	else
		return isBalanced(root->left) && isBalanced(root->right);
}