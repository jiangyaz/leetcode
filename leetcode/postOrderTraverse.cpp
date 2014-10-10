/* Binary Tree Postorder Traversal 

Given a binary tree, return the postorder traversal of its nodes' values.
*/

vector<int> postorderTraversal(TreeNode *root) {
	vector<int> res;
	if (root == NULL) return res;

	stack<TreeNode *> sta;
	sta.push(root);
	TreeNode *head = root;

	while (!sta.empty()) {
		TreeNode *node = sta.top();
		if ( (!node->left && !node->right) || node->left == head || node->right == head) {
			res.push_back(node->val);
			sta.pop();
			head = node;
		} else {
			if (node->right)
				sta.push(node->right);
			if (node->left) 
				sta.push(node->left); 
		}
	}
	return res;
}