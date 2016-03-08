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
    void inorder(TreeNode* root, vector<int>& ans) //recursive
    {
        if (!root) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        /******* Recursive ***********/
        // vector<int> ans;
        // inorder(root, ans);
        // return ans;
        
        /***** Iterative *******/
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode *cur = root;
        
        while(cur || !st.empty())
        {
            if (cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            else //till the leftmost
            {
                cur = st.top();
                st.pop();
                ans.push_back(cur->val);
                cur = cur->right;
            }
        }
        return ans;
        
    }

};