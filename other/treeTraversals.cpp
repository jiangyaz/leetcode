// Tree Traversal

vector<int> preOrderIt(TreeNode *root) {
    vector<int> res;
    stack<TreeNode *> sta;
    if (root == NULL) return res;
    sta.push(root);

    while (!sta.empty()) {
        TreeNode *node = sta.top();
        sta.pop();
        res.push_back(node->val);
        if (node->right) sta.push(node->right);
        if (node->left) sta.push(node->left);
    }
    return res;
}

void preOrderRec(vector<int> &res, TreeNode *node) {
    if (node == NULL) return;
    res.push_back(node->val);
    preOrderRec(res, node->left);
    preOrderRec(res, node->right);
}

vector<int> preOrder(TreeNode *root) {
    vector<int> res;
    preOrderRec(res, root);
    return res;
}

// =================================================

// So damn tricky, this solution
vector<int> inOrderIt(TreeNode *root) {
    vector<int> res;
    stack<TreeNode *> sta;
    TreeNode *cur = root;

    while (!sta.empty() || cur) {
        if (cur) {
            sta.push(cur);
            cur = cur->left;
        } else {
            cur = sta.top();
            sta.pop();
            res.push_back(cur->val);
            cur = cur->right;
        }
    }
    return res;
}


void inOrderRec(vector<int> &res, TreeNode *node) {
    if (node == NULL) return;
    inOrderRec(res, node->left);
    res.push_back(node->val);
    inOrderRec(res, node->right);
}

vector<int> inOrder(TreeNode *root) {
    vector<int> res;
    inOrderRec(res, root);
    return res;
}

// =================================================

vector<int> postOrderIt(TreeNode *root) {
    vector<int> res;
    if (root == NULL) return res;

    stack<TreeNode *> sta;
    sta.push(root);
    TreeNode *last = root;

    while (!sta.empty()) {
        TreeNode *node = sta.top();
        if ((!node->left && !node->right) || (last == node->left) || (last == node->right)) {
            res.push_back(node->val);
            sta.pop();
            last = node;
        } else {
            if (node->right)
                sta.push(node->right);
            if (node->left)
                sta.push(node->left);
        }
    }
    return res;
}

void postOrderRec(vector<int> &res, TreeNode *node) {
    if (node == NULL) return;
    postOrderRec(res, node->left);
    postOrderRec(res, node->right);
    res.push_back(node->val);
    return res;
}

vector<int> postOrder(TreeNode *root) {
    vector<int> res;
    postOrderRec(res, node);
    return res;
}


// =================================================

vector<vector<int> >levelOrder(TreeNode *root) {
    vector<vector<int> > res;
    vector<int> row;
    queue<TreeNode *> curLevel, nextLevel;

    if (root == NULL) return res;
    curLevel.push(root);

    while (!curLevel.empty()) {
        TreeNode *node = curLevel.front();
        curLevel.pop();
        row.push_back(node->val);

        if (node->left)
            nextLevel.push(node->left);
        if (node->right)
            nextLevel.push(node->right);

        if (curLevel.empty()) {
            res.push_back(row);
            row.clear();
            curLevel.swap(nextLevel);
        }
    }
    return res;
}




