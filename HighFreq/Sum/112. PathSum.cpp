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
            return (root->val == sum);

        //recursive step
        sum -= root->val;
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
        
    }
};