/* Binary Tree Level Order Traversal 
Given a binary tree, return the level order traversal of its nodes' values. 
(ie, from left to right, level by level).

*/

vector<vector<int> > levelOrder(TreeNode *root) {
	vector<vector<int>> res;
	vector<int> row;
	queue<TreeNode *> curLevel, nextLevel;

	if (root == NULL) return res;
	curLevel.push(root);

	while (!curLevel.empty()) {
		TreeNode *node = curLevel.front();
		row.push_back(node->val);
		curLevel.pop();

		if (node->left)
			nextLevel.push(node->left);
		if (node->right)
			nextLevel.push(node->right);

		if (curLevel.empty()) {
			curLevel.swap(nextLevel);
			res.push_back(row);
			row.clear();
		}
	}
	return res;
}
