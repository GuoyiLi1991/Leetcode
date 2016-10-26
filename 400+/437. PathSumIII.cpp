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
    int findPath(TreeNode* root, int sum) {
        if (!root) return 0;
        
        return (root->val == sum) + 
        		findPath(root->left, sum - root->val) + 
        		findPath(root->right, sum - root->val);
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        return findPath(root, sum) + 
        		pathSum(root->left, sum) + 
        		pathSum(root->right, sum);
        
    }
};

/////////////
class Solution {
    void dfs(TreeNode* root, int sum, int &num_path) {
        if (!root) return;
        if (root->val == sum)
            num_path++;
        
        dfs(root->left, sum - root->val, num_path);
        dfs(root->right, sum - root->val, num_path);
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        int res = 0;
        dfs(root, sum, res);
        
        return res + pathSum(root->left, sum) + 
        			pathSum(root->right, sum);
    }
};