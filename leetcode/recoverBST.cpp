/* Recover Binary Search Tree
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.
*/

void recoverTree(TreeNode *root) {
    TreeNode *prev = NULL;
    TreeNode *n1 == NULL, *n2 = NULL;
    inOrderTraverse(root, prev, n1, n2);
    swap(n1->val, n2->val);
}

void inOrderTraverse(TreeNode *node, TreeNode* &prev, TreeNode* &n1, TreeNode* &n2) {
    if (node == NULL) return;
    
    inOrderTraverse(node->left, prev);
    
    if (prev && prev->val >=node->val) {
        n2 = node;             // remember!
        if (!n1) n1 = prev;    // remember!
    } else {
        prev = node;
    } 
    
    inOrderTraverse(node->right, prev);
}