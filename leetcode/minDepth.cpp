/* Minimum Depth of Binary Tree
Given a binary tree, find the maximum path sum.

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/

int minDepth(TreeNode *root) {
	if (root == NULL) 
		return 0;
	else if (!root->left) 
		return minDepth(root->right)+1; 
	else if (!root->right)
		return minDepth(root->left) +1;
	else 
		return min(minDepth(root->left), minDepth(root->right))+1;      
}