/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //// O(n) time, in-place
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *cur = root;
        while (cur) {
            if (cur->left) {
                //move cur->right to the rightchild of the rightmost leave of cur->left
                TreeNode *ptr = cur->left;  
                while (ptr->right)
                    ptr = ptr->right;
                    
                ptr->right = cur->right;
                
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;  //move down current
        }
    }
};