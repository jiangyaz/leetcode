/* Validate Binary Search Tree 
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/


bool isBSTHelper(TreeNode *node, int minVal, int maxVal) {
	if (node == NULL) 
		return true;
	else if (node->val <= minVal || node->val >= maxVal)
		return false;
	else 
		return isBSTHelper(node->left, minVal, node->val) && isBSTHelper(node->right, node->val, maxVal);
}

bool isValidBST(TreeNode *root) {
	return isBSTHelper(root, INT_MIN, INT_MAX);   
}