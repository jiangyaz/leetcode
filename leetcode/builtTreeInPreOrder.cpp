/* Construct Binary Tree from Preorder and Inorder Traversal 
Given preorder and inorder traversal of a tree, construct the binary tree.
*/

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
	int n = preorder.size();
	if (n == 0) return NULL;
	return getTree(preorder, 0, n-1, inorder, 0);
}

TreeNode *getTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart) {
	if (preStart > preEnd) return NULL;
	int inEnd = inStart + preEnd - preStart;

	TreeNode *root = new TreeNode(preorder[preStart]);
	int index = inStart;
	while (inorder[index] != preorder[preStart]) {
		index++;
	}

	root->left = getTree(preorder, preStart+1, preStart+index-inStart, inorder, inStart);
	root->right = getTree(preorder, preStart+index-inStart+1, preEnd, inorder, index+1);
	return root;
}