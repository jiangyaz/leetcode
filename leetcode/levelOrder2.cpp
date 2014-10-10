/* Binary Tree Level Order Traversal II 
Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
(ie, from left to right, level by level from leaf to root).
*/

vector<vector<int> > levelOrderBottom(TreeNode *root) {
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
			res.insert(res.begin(), row);
			row.clear();
		}
	}
	return res;
}