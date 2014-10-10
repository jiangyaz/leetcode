/* Symmetric Tree

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:
*/

bool isSymmetric(TreeNode *root) {
	if (root == NULL) 
		return true;
	else 
		return isSymmetricHelper(root->left, root->right);
}

bool isSymmetricHelper(TreeNode *p, TreeNode *q) {
	if (!p && !q)
		return true;
	else if ((p && !q) || (!p && q)) 
		return false;
	else if (p->val != q->val)
		return false;
	else
		return isSymmetricHelper(p->left, q->right) && isSymmetricHelper(p->right, q->left);
}