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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        
        queue<TreeNode*, int> q; //<node, level>
        map<int, vector<int>> mp; //<level, nodes_val_of_that_level>
        q.push(root, 0);
        
        while (!q.empty()) {
            pair<TreeNode*, int> tmp = q.front();
            q.pop();
            
            TreeNode* cur = tmp->first;
            mp[tmp->second] = cur->val;
            
            if (cur->left) {
                q.push(make_pair(cur, level - 1));
            }
            if (cur->right) {
                q.push(make_pair(cur, level + 1));
            }
        }
        
        for (auto item:mp) 
            res.push_back(item->second);
            
        return res;
    }
};