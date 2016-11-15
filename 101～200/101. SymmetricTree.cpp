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
    bool isSymmetric(TreeNode *s, TreeNode *t) {
        if (!s && !t)
            return true;
        if (s && t) {
            if (s->val != t->val)
                return false;
            return isSymmetric(s->left, t->right) && isSymmetric(s->right, t->left);
        }
        else 
            return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return isSymmetric(root->left, root->right);
    }
};



////////
// Sol2. Iterative

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        // 0 or 1 node
        if (!root || !root->left && !root->right) return true;
        // 2 nodes
        if (!root->left || !root->right)
            return false;
        
        //left and right both not null
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        
        while (!q.empty()) {
            TreeNode* left = q.front(); q.pop();
            TreeNode* right = q.front(); q.pop();
            
            //check current level
            if (left->val != right->val)
                return false;
            if (!left->left && right->right || left->left && !right->right ||
                !left->right && right->left || left->right && !right->left)
                return false;
                
            //passed the current, push next level
            if (left->left) q.push(left->left);
            if (right->right) q.push(right->right);
            if (left->right) q.push(left->right);
            if (right->left) q.push(right->left);
        }
        return true;
    }
};

