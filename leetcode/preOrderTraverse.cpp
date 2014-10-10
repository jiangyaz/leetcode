/* Binary Tree Preorder Traversal

Given a binary tree, return the preorder traversal of its nodes' values.

*/

vector<int> preorderTraversal(TreeNode *root) {
	vector<int> res;
	if (root == NULL) return res;
    
    stack<TreeNode *> sta;
    sta.push(root);
    while (!sta.empty()) {
    	TreeNode *node = sta.top();
    	sta.pop();
    	res.push_back(node->val);
    	if (node->right) 
    		sta.push(node->right);

    	if (node->left) 
    		sta.push(node->left);
    }
    return res;
}