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
    // void DFS(vector<vector<int>>& ans, TreeNode* root, int column)
    // {
    //     if (!root) return;
    //     if (root->left)
    // }
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans;
       if (!root) return ans;
       
       /******** BFS *********/
       queue<pair<TreeNode*, int>> q; // <node, col>
       map<int, vector<int>> mp;
       q.push(make_pair(root, 0));
       
       while(!q.empty())
       {
            TreeNode* cur = q.front().first;
            int col = q.front().second;
           
            if (cur->left)
                q.push(make_pair(cur->left, col-1));
            if (cur->right)
                q.push(make_pair(cur->right, col+1));
                
            //dequeue and add to ans
            q.pop();
            mp[col].push_back(cur->val);
       }
       
       for (auto item:mp)
       {
           ans.push_back(item.second);
       }
       return ans;
        
    }
};