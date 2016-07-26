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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) 
        	return root;
        if (!root->left && !root->right)
        	return root;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
        
    }
};

//////////////////////////////////////
// iterative
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return root;
        queue<TreeNode *> st;
        st.push(root);
        
        while (!st.empty()) {
            TreeNode *tmp = st.front();
            swap(tmp->left, tmp->right);
            st.pop();
            if (tmp->left)
                st.push(tmp->left);
            if (tmp->right)
                st.push(tmp->right);
        }
        return root;
    }
};