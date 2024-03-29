/* Maximum Depth of Binary Tree
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

int maxDepth(TreeNode *root) {
	if (root == NULL) 
		return 0;
	else 
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}