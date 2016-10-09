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
    void dfs(TreeNode *root, vector<vector<int>> &ret, vector<int> path, int sum) {
        if (!root) 
            return;
        
        path.push_back(root->val);
        //if leaf, return
        if (!root->left && !root->right) { 
            if (sum == root->val) { //if solution, save before return
                ret.push_back(path);
            }
            return;
        }
        
        //if not leaf, backtracking
        if (root->left)
            dfs(root->left, ret, path, sum - root->val);
        if (root->right)
            dfs(root->right, ret, path, sum - root->val);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        vector<int> path;
        dfs(root, ret, path, sum);
        return ret;
    }
};