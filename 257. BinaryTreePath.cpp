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
    void DFS(TreeNode *t, vector<string>&ret, string path)
    {
        if (!(t->left) && !(t->right)) //Termination: find leaf
        {
            ret.push_back(path);
            return;
        }
        
        if (t->left)
            DFS(t->left, ret, path + "->" + to_string(t->left->val));
        if (t->right)
            DFS(t->right, ret, path + "->" + to_string(t->right->val));
        
    }
    
    vector<string> nonrecursive(TreeNode *root)
    {
        vector<string> ret;
        if (!root) return ret;
        
        queue<TreeNode*> q;
        queue<string> paths;
        
        q.push(root);
        paths.push(to_string(root->val));
        
        while(!q.empty())
        {
            TreeNode *tmp = q.front();
            string path_tmp = paths.front();
            q.pop();
            paths.pop();
            
            if (!tmp->left && !tmp->right)
                ret.push_back(path_tmp);
            if (tmp->left)
            {
                //enqueue tmp->left info
                q.push(tmp->left);
                paths.push(path_tmp + "->" + to_string(tmp->left->val));
            }
            if (tmp->right)
            {
                //enqueue tmp->right info
                q.push(tmp->right);
                paths.push(path_tmp + "->" + to_string(tmp->right->val));
            }
        }
        
        return ret;
    }
    
    
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        // vector<string> ret;
        // if (!root) return ret;
        // DFS(root, ret, to_string(root->val));
        // return ret;
        
        //non-recursive
        return nonrecursive(root);
    }
};



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
    //aka. backtracking
    void dfs(vector<string> &res, string path, TreeNode *root) {  
        if (!root)
            return;
        path += to_string(root->val);
        
        //if leaf, terminate
        if (!root->left && !root->right) 
        {
            res.push_back(path);
            return;
        }
        
        //not leaf, recursive
        if (root->left)
            dfs(res, path + "->", root->left);
        if (root->right)
            dfs(res, path + "->", root->right);
            
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string path;
        dfs(res, path, root);
        return res;
    }
};