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
   // int ans = numeric_limits<int>::max();
    int DFS(TreeNode*root)
    {
        if (!root) return 0;
        if (root->left && root->right)
            return min(DFS(root->left), DFS(root->right))+1;
        else if (root->left)
            return DFS(root->left)+1;
        else if (root->right)
            return DFS(root->right)+1;
        else return 1;
    }
    
    int BFS(TreeNode * root)
    {
        if (!root) return 0;
        queue<pair<TreeNode*, int>> q;  //<node, depth>
        q.push(make_pair(root,1));
        
        while(!q.empty())
        {
            pair<TreeNode*, int> tmp = q.front();
            q.pop();
            int depth = tmp.second;
            TreeNode* cur = tmp.first;
            
            if (!cur->left && !cur->right) return depth;
                
            if(cur->left) q.push(make_pair(cur->left,depth+1));
            if(cur->right) q.push(make_pair(cur->right,depth+1));
        }
    }
public:
    int minDepth(TreeNode* root) {
        return DFS(root);
      
        //return BFS(root);
        
      
        
    }
};