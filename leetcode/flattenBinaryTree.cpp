/* Flatten Binary Tree to Linked List 
Given a binary tree, flatten it to a linked list in-place.

For example, Given
         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
*/

void flatten(TreeNode *root) {
	if (root == NULL) return;
	TreeNode *prev = NULL;
	stack<TreeNode *> sta;

	sta.push(root);
	while (!sta.empty()) {
		TreeNode *cur = sta.top();
		sta.pop();

		if (cur->right)
			sta.push(cur->right);
		if (cur->left)
			sta.push(cur->left);

		if (!prev) {
			prev = cur;
		} else {
			prev->right = cur;
			prev->left = NULL;   // don't for get this!
			prev = cur;
		}
	}
}

