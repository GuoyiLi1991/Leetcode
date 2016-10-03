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
    void helper(TreeNode *root, vector<vector<int>> &ans, int level)
    {
        if (!root) return;
        if (ans.size() < level +1)
            ans.push_back(vector<int>{});
        ans[level].push_back(root->val);
        helper(root->left, ans, level+1);
        helper(root->right, ans,level+1);
    }
    
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        /****** Recursive *******/
        // helper(root, ans, 0);
        // return ans;
        /****** Iterative(BFS) *******/
        if (!root) return ans;
        queue<pair<TreeNode*, int>> q; //<node, level>
        q.push(make_pair(root, 0));  //enqueue
        
        while(!q.empty())
        {
            //pair<TreeNode*, int> cur = q.front();
            TreeNode* cur = q.front().first;
            int level = q.front().second;
            if (cur->left)
                q.push(make_pair(cur->left, level+1));
            if (cur->right)
                q.push(make_pair(cur->right, level+1));
                
             q.pop();  //dequeue
             if (ans.size() < level+1)
                ans.push_back(vector<int>{});
            ans[level].push_back(cur->val);
            
        }
        
        return ans;
        
    }
};