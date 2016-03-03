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
    int getHeight(TreeNode *root)
    {
        if (!root) return 0;
        
        return 1+max(getHeight(root->left), getHeight(root->right));
    }
public:
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        
        return (abs(leftHeight-rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right));
    }
};
