// Find the sum of the largest subtree of a binary tree
// 

int maxSubtreeSum(TreeNode *root) {
	if (root == NULL) return 0;
	int maxSubtreeAtRoot = root->val + maxPathAcrossRoot(root->left, maxGlobal) + 
							maxPathAcrossRoot(root->right, maxGlobal);
	return max(maxSubtreeAtRoot, maxGlobal);
}

int maxPathAcrossRoot(TreeNode *node, int &maxGlobal) {
	if (node == NULL) return 0;

	int leftMax = maxPathAcrossRoot(node->left);
	int rightMax = maxPathAcrossRoot(node->right);

	// update maxGlobal
	int curSum = node->val + leftMax + rightMax;
	maxGlobal = max(maxGlobal, curSum);

	// pass node+left or node+right to parent
	return max(leftMax, rightMax) + node->val;
}