/* Sum Root to Leaf Numbers

Given a binary tree containing digits from 0-9 only, each root-to-leaf path 
could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
*/

int sumNumbers(TreeNode *root) {
	return getSum(root, 0);
}


int getSum(TreeNode *node, int sum) {
	if (node == NULL) return 0;
	int curSum = sum * 10 + node->val;

	if (!node->left && !node->right)
		return curSum;
	else 
		return getSum(node->left, curSum) + getSum(node->right, curSum);
}