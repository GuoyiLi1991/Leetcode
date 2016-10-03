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
    void DFS(TreeNode *root, vector<vector<int>>&ans, int level)
    {
        if (!root) return;
        if (ans.size() < level+1)
            ans.push_back(vector<int>{});
        
        if (level%2 == 0) //even line
            ans[level].push_back(root->val);
        else //odd line
            ans[level].insert(ans[level].begin(), root->val);
        DFS(root->left, ans, level+1);
        DFS(root->right, ans, level+1);
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        /******** Recursive *********/
        vector<vector<int>> ans;
        DFS(root, ans, 0);
        return ans;
    }
};