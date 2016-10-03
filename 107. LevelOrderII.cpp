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

//////////////////////////
// Combination of max depth and level order(I).
// beat 90%
class Solution {
    int maxDepth(TreeNode * root) {
        if (!root)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
    void DFS(vector<vector<int>> & res, TreeNode *root, int level) {
        if (!root)
            return;
        res[level - 1].push_back(root->val);
        DFS(res, root->left, level - 1);
        DFS(res, root->right, level - 1);
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int d = maxDepth(root);
        vector<vector<int>> res(d, vector<int>{});
        DFS(res, root, d);
        return res;
    }
};



/////////////
// BFS converted from vertical order traversal
// BFS + map<level, list_of_vals>

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root)
            return vector<vector<int>>{};
        vector<vector<int>> res;
        
        queue<pair<TreeNode*, int>> q; //<node, level>
        map<int, vector<int>> levels; // <level, list_of_vals>
        q.push(make_pair(root, 0));
        
        while (!q.empty()) {
            TreeNode *cur = q.front().first;
            int level  = q.front().second;
            
            if (cur->left)
                q.push(make_pair(cur->left, level - 1));
            if (cur->right) 
                q.push(make_pair(cur->right, level - 1));
            
            q.pop();
            levels[level].push_back(cur->val);
        }
        
        for (auto item:levels) {
            res.push_back(item.second);
        }
        return res;
    }
};