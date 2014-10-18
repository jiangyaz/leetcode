/* Binary Tree Maximum Path Sum

Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
*/

int maxPathSum(TreeNode *root) {
	int maxGlobalSum = INT_MIN;
	int maxSumEndAtRoot = maxPathSum(root, maxGlobalSum);
	return maxGlobalSum;        
}

int maxPathSum(TreeNode *node, int &maxGlobalSum) {
	if (node == NULL) return 0;

	int leftMax = maxPathSum(node->left, maxGlobalSum);
	int rightMax = maxPathSum(node->right, maxGlobalSum);
	
	int curSum = node->val;
	if (leftMax > 0) curSum += leftMax;
	if (rightMax > 0) curSum += rightMax;

	maxGlobalSum = max(maxGlobalSum, curSum);

	return max(node->val, max(leftMax, rightMax) + node->val);
}