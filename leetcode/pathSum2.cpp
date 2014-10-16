/* Path Sum II 

Given a binary tree and a sum, find all root-to-leaf paths where 
each path's sum equals the given sum.
*/

vector<vector<int> > pathSum(TreeNode *root, int sum) {
	vector<vector<int> >res;
	vector<int> path;
	getPath(root, sum, path, res);
	return res;
}

void getPath(TreeNode *node, int sum, vector<int> &path, vector<vector<int> > &res) {
	if (node == NULL) return;
	path.push_back(node->val);

	if (!node->left && !node->right) {
		if (node->val == sum) {
			res.push_back(path);
			return;
		}
	}
	if (node->left) {
		getPath(node->left, sum - node->val, path, res);
		path.pop_back();
	}
	if (node->right) {
		getPath(node->right, sum - node->val, path, res);
		path.pop_back();
	}
}
