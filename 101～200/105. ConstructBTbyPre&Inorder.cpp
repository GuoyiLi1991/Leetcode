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
    TreeNode *helper(vector<int>& preorder, int i, int j, vector<int>& inorder, int ii, int jj) {
        //illegal case
        if (i >= j || ii >= jj)
            return NULL;
        
        /* The first element in preorder is the root
         * find offset of this value in inorder
         * For preorder: 
         *      [i+1, i+1+offset) => left
         *      [i+1+offset, j)   => right
         * For inorder:
         *      [ii, ii + offset)       => left
         *      [ii + offset + 1, jj)   => right
         */
        int root_val = preorder[i]; 
        vector<int>::iterator pos = find(inorder.begin() + ii, inorder.begin() + jj, root_val);
        int offset = pos - inorder.begin() - ii;
        
        TreeNode *root = new TreeNode(root_val);
        root->left = helper(preorder, i + 1, i + 1 + offset, inorder, ii, ii + offset);
        root->right = helper(preorder, i + 1 + offset, j, inorder, ii + offset + 1, jj);
        
        return root;
        
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0)
            return NULL;
        return helper(preorder, 0, preorder.size(), inorder, 0, inorder.size());
        
    }
};