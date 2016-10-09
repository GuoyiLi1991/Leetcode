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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) return NULL;
        
        while(true) //find a root value that is between p and q
        {
            int diff1 = root->val - p->val;
            int diff2 = root->val - q->val;
            
            if (diff1 * diff2 <= 0) return root;
            root = diff1<0? root->right: root->left;
        }
    }
};