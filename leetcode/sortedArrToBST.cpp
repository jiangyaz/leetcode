/* Convert Sorted Array to Binary Search Tree
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/


TreeNode *sortedArrayToBST(vector<int> &num) {
	if (num.size() == 0) return NULL;
	return arrToBST(num, 0, num.size()-1);       
}

TreeNode *arrToBST(vector<int> &num, int start, int end) {
	if (start > end) return NULL;

	int mid = (start + end)/2;
	TreeNode *root = new TreeNode(num[mid]);
	root->left = arrToBST(num, start, mid-1);
	root->right = arrToBST(num, mid+1, end);
	return root;
}