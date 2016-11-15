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
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int height = 0;
        TreeNode *left = root->left;
        TreeNode *right = root->left;
        
        //for left subtree
        while (right) {
            height++;
            left = left->left;
            right = right->right;
        }
        
        int cnt = (1 << height) - 1;
        if (!left && !right)
            return cnt + 1 + countNodes(root->right); // leftSub + root + rightSub 
        else 
            return cnt + 1 + countNodes(root->left);
        
    }
};
