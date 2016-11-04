class Solution {
    TreeNode *first, *second, *prev;
    void inorder(TreeNode *root) {
        if (!root) return;
        inorder(root->left);
        
        if (prev && prev->val > root->val) {
            if (!first) first = prev;
            second = root;
        }
        
        prev = root;
        inorder(root->right);
            
    }
public:
    void recoverTree(TreeNode* root) {
        prev = first = second = NULL;
        inorder(root);
        
        if (first)
            swap(first->val, second->val);
    }
};