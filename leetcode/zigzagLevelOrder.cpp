/* Binary Tree Zigzag Level Order Traversal

Given a binary tree, return the zigzag level order traversal of its nodes' values. 
(ie, from left to right, then right to left for the next level and alternate between).
*/

vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
	vector<vector<int> >res;
	vector<int> row;
	queue<TreeNode *> curLevel, nextLevel;

	if (root == NULL) return res;   
	curLevel.push(root);

	bool flag = true;

	while (!curLevel.empty()) {
		TreeNode *node = curLevel.front();
		curLevel.pop();

		if (flag)   // flag = true, push from left to right
			row.push_back(node->val);
		else 
			row.insert(row.begin(), node->val);

		if (node->left)
			nextLevel.push(node->left);
		if (node->right)
			nextLevel.push(node->right);

		if (curLevel.empty()) {
			nextLevel.swap(curLevel);
			res.push_back(row);
			flag = !flag;   
			row.clear();
		}
	}
	return res;
}