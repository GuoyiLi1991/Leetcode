/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    queue<int> nodes;
    
    void inorder(TreeNode* root, queue<int>& nodes) {
        if (!root) return;
        if (root->left) inorder(root->left, nodes);
        nodes.push(root->val);
        inorder(root->right, nodes);
    }
public:
    BSTIterator(TreeNode *root) {
        inorder(root, nodes);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (!nodes.empty());
    }

    /** @return the next smallest number */
    int next() {
        if (!hasNext()) return -1;
        int tmp = nodes.front();
        nodes.pop();
        return tmp;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */