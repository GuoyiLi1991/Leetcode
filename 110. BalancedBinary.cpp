/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //// Sol1: O(n^2)
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

/// Sol2: return immediately when finding an unbalanced subtree
/// Time: O(n), space: O(log n)
class Solution {
    int getHeight(TreeNode *root) {
        //return -1 if unbalanced
        if (!root) return 0; //height is 0
        
        //check if left or right is unbalanced
        int leftHeight = checkHeight(root->left);
        int rightHeight = checkHeight(root->right);
        if (leftHeight == -1 ||  rightHeight == -1)
            return -1;
        
        //check if current node is balanced
        if (abs(leftHeight - rightHeight) > 1)
            return -1;
        else
            return 1 + max(leftHeight, rightHeight);
        
    }
public:
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};
