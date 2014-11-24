

void getPath(TreeNode* node, vector<vector<int> > &res, vector<int> &path, int target) {
	if (node == NULL) return;
	path.push_back(node->val);
	int sum = 0;
	for (int i = path.size()-1; i >=0; i++) {
		sum += path[i];
		if (sum == target) {
			vector<int> sol;
			for (int j = i; j < path.size()-1; j++) {
				sol.push_back(path[j]);
			}
			res.push_back(sol);
		}
	}
	getPath(node->left, res, path, target);
	getPath(node->right, res, path, target);
	path.pop_back();
}

vector<vector<int> > getPathForSum(TreeNode *root, int target) {
	vector<vector<int> > res;
	vector<int> path;
	getPath(root, res, path, target);
	return res;
}