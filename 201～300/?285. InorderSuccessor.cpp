class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (p -> right) return leftMost(p -> right);
        TreeNode* suc = NULL;
        while (root) {
            if (p -> val < root -> val) {
                suc = root;
                root = root -> left;
            }
            else if (p -> val > root -> val)
                root = root -> right; 
            else break;
        }
        return suc;
    }
private:
    TreeNode* leftMost(TreeNode* node) {
        while (node -> left) node = node -> left;
        return node;
    }
};