/* 
Find the maximum sum leaf to root path in a Binary Tree
Given a Binary Tree, find the maximum sum path from a leaf to root. 
For example, in the following tree, there are three leaf to root paths 8->-2->10,
 -4->-2->10 and 7->10. The sums of these three paths are 16, 4 and 17 respectively.
 The maximum of them is 17 and the path for maximum is 7->10.

                 10
                /  \
	          -2    7
             /   \     
	        8    -4  
*/ 

int maxLeafToRootSum(TreeNode *root) {
	if (root == NULL) 
		return 0;
	else 
		return root->val + max(maxLeafToRootSum(root->left), maxLeafToRootSum(root->right));
}