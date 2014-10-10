/* Unique Binary Search Trees II 
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
*/

vector<TreeNode *> generateTrees(int n) {
	vector<TreeNode *> res(1);
	getTrees(res, 1, n);
	return res;        
}

void getTrees(vector<TreeNode *> &trees, int start, int end) {
	if (start > end) {
	    trees.push_back(NULL);    // Very important: make sure leftSubTree.size() != 0
	    return;
	}
	/*
	if (start == end) {
		TreeNode *root = new TreeNode(start);
		trees.push_back(root);
		return;
	}  */

	for (int k = start; k <= end; k++) {
		vector<TreeNode *> leftSubTrees, rightSubTrees;	
		getTrees(leftSubTrees, start, k-1);
		getTrees(rightSubTrees, k+1, end);

		for (int i = 0; i < leftSubTrees.size(); i++) {
			for (int j = 0; j < rightSubTrees.size(); j++) {
				TreeNode *root = new TreeNode(k);
				root->left = leftSubTrees[i];
				root->right = rightSubTrees[j];
				trees.push_back(root);
			}
		}
	}
}