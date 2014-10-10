/* Binary Tree Inorder Traversal 

Given a binary tree, return the inorder traversal of its nodes' values.

Note: Recursive solution is trivial, could you do it iteratively?
*/

vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    if (root == NULL) return res;
    stack<TreeNode *> sta;
    TreeNode *curNode = root;

    while (!sta.empty() || curNode) {
	    if (curNode) {
		    sta.push(curNode);
		    curNode = curNode->left;
	    } else {
		    curNode = sta.top();
		    sta.pop();
		    res.push_back(curNode->val);
		    curNode = curNode->right;
	    }
    }
    return res;
}

/*
vector<int> inorderTraversal(TreeNode *root) {
	vector<int> res;
	inOrder(res, root);
	return res;
}

void inOrder(vector<int> &res, TreeNode *node) {
	if (node == NULL) return;

	inOrder(res, node->left);
	res.push_back(node->val);
	inOrder(res, node->right);
}
*/