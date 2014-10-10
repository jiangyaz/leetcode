/* Same Tree 
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes
have the same value.
*/

bool isSameTree(TreeNode *p, TreeNode *q) {
	if (!p && !q)
		return true;
	else if ((!p && q) || (p && !q))
		return false;
	else if (p->val != q->val) 
		return false;
	else 
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}