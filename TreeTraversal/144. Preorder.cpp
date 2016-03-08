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
    void preorder(TreeNode *root, vector<int> &ans){
        if (!root) return;
        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        /******** Recursive **********/
        // vector<int> ans;
        // preorder(root, ans);
        // return ans;
        
        /******** Iterative *********/
        vector<int> ans;
        if (!root) return ans;
        
        stack<TreeNode *> st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode *cur = st.top();
            st.pop();
            ans.push_back(cur->val);
            
            if (cur->right) st.push(cur->right);
            if (cur->left) st.push(cur->left);
        }
        
        return ans;
    }
};