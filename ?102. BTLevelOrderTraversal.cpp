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
    // vector<vector<int>> levelOrder(TreeNode* root)  //8ms
    // {
    //     vector<vector<int>> ret;
    //     if (!root) return ret;
        
    //     queue<pair<TreeNode*, int>> q;
    //     q.push(make_pair(root,1));
    //     int depth;
    //     while (!q.empty())
    //     {
    //         auto tmp = q.front();
    //         q.pop();
    //         TreeNode *cur = tmp.first;
    //         depth = tmp.second;
    //       // ret.resize(ret.size()+1);
    //         ret.push_back(vector<int>(0));
    //         ret[depth-1].push_back(cur->val);
    //         if (cur->left)
    //             q.push(pair<TreeNode*, int>(cur->left, depth+1));
    //         if(cur->right) 
    //             q.push(pair<TreeNode*, int>(cur->right, depth+1));
    //     }
    //     ret.resize(depth);
    //     return ret;
    // }
    void helper(vector<vector<int>> &result, TreeNode*root, int level)//4ms
    {
        if (!root) return;
        if (result.size() < level+1)
            result.push_back(vector<int>{});
        result[level].push_back(root->val);
        helper(result, root->left, level+1);
        helper(result, root->right, level+1);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        helper(result, root, 0);
        return result;
        
    }
};



