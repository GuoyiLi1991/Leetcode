class Solution {
    // int maxHeight(TreeNode* root) {
    //     if (!root) return 0;
    //     return 1 + max(maxHeight(root->left), maxHeight(root->right));
    // }
    void dfs(vector<int>& res, TreeNode* root, int unprinted, int &curLevel) {
        if (!root) return;
        
        if (curLevel < unprinted) {
            res.push_back(root->val);
            curLevel = unprinted;
        }
        dfs(res, root->right, unprinted + 1, curLevel);
        dfs(res, root->left, unprinted + 1, curLevel);
        
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        
        int unprinted = 1;
        int curLevel = 0;
        dfs(res, root, unprinted , curLevel);
        return res;
    }
};