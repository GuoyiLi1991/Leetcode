/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool isSymmetric(TreeNode *s, TreeNode *t) {
        if (!s && !t)
            return true;
        if (s && t) {
            if (s->val != t->val)
                return false;
            return isSymmetric(s->left, t->right) && isSymmetric(s->right, t->left);
        }
        else 
            return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return isSymmetric(root->left, root->right);
    }
};