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
    void DFS(vector<vector<int>> & ans, TreeNode* root, int level)
    {
        if (!root) return;
        if (ans.size() < level+1)
            ans.push_back(vector<int>{});
        ans[level].push_back(root->val);
        DFS(ans, root->left, level+1);
        DFS(ans, root->right, level +1);
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        DFS(ans, root, 0);
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};