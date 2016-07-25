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
    bool hasPathSum(TreeNode* root, int sum) {
        //edge case
        if (!root)
            return false;
        //find a leaf, terminate
        if (!root->left && !root->right)
            if (root->val == sum)
                return true;
            else return false;
        //recursive step
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
        
    }
};