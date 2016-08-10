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
    void DFS(TreeNode* root, vector<int> &ans)
    {
        if (!root) return;
        DFS(root->left, ans);
        DFS(root->right,ans);
        ans.push_back(root->val);
    }
    void BFS(TreeNode *root, vector<int> &res) {
        if (!root) return ans;
        stack<TreeNode *> st;
        st.push(root);
        
        while(!st.empty())
        {
            TreeNode *cur = st.top();
            st.pop();
            ans.insert(ans.begin(),cur->val);

            if (cur->left)
                st.push(cur->left);
            if (cur->right)
                st.push(cur->right);
        }
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        DFS(root, ans);
        //BFS(root, ans);
        return ans;

    }
};