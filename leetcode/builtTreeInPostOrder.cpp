/* Construct Binary Tree from Inorder and Postorder Traversal

Given inorder and postorder traversal of a tree, construct the binary tree.
*/

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    int n = inorder.size();
    if (n == 0)  return NULL;
	return getTree(inorder, 0, n-1, postorder, 0);        
}

TreeNode *getTree(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart) {
    int postEnd = postStart + inEnd - inStart;
    if (inStart > inEnd || postStart > postEnd) return NULL;

    TreeNode *root = new TreeNode(postorder[postEnd]);
    int index = inStart;
    while (inorder[index] != postorder[postEnd]) {
	    index++;
    }
    
    root->left = getTree(inorder, inStart, index-1, postorder, postStart);
    root->right = getTree(inorder, index+1, inEnd, postorder, postStart + index-inStart);
    return root;
}