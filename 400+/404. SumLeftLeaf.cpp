/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //sol1. Recursive
class Solution {
    bool isLeaf(TreeNode* node) {
        return (!node->left && !node->right);
    }
    
    void dfs(TreeNode* root, int &sum) {
        if (!root)
            return;
        if (root->left) {
            if (isLeaf(root->left))
                sum += root->left->val;
            else
                dfs(root->left, sum);
        }
        if (root->right)
            dfs(root->right, sum);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        dfs(root, sum);
        return sum;
    }
};

//////////////
// rewrite
class Solution {
    bool isLeaf(TreeNode* node) {
        return (!node->left && !node->right);
    }
    
    void dfs(TreeNode* root, int &sum) {
        if (!root)
            return;
        if (root->left && isLeaf(root->left))
                sum += root->left->val;
        
        dfs(root->left, sum);
        dfs(root->right, sum);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        dfs(root, sum);
        return sum;
    }
};

//////////
// Sol2. Iterative
class Solution {
    bool isLeaf(TreeNode* node) {
        return (!node->left && !node->right);
    }
    
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        
        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();
            if (tmp->left && isLeaf(tmp->left))
                sum += tmp->left->val;
            
            if (tmp->left) q.push(tmp->left);
            if (tmp->right) q.push(tmp->right);
            
        }
        
        return sum;
    }
};