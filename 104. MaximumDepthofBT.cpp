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
    int sol1(TreeNode* root)  //DFS, recursive
    {
        if (!root) return 0;
        return 1+ max(maxDepth(root->left), maxDepth(root->right));
    }
    
    int sol2(TreeNode* root)  //BFS
    {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0, cnt;
        TreeNode *left, *right;
        while(!q.empty())
        {
            depth++;
            cnt = q.size();
            
            //pop out all the cur level node
            while(cnt-- >0)
            {
                left = q.front()->left;
                if (left) q.push(left);
                right = q.front()->right;
                if(right) q.push(right);
                
                q.pop();
            }
        }
        return depth;
    }
public:
    int maxDepth(TreeNode* root) {
        
        //return sol1(root);
        return sol2(root);
        
    }
};


