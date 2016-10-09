/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // Sol1. Non- Recursive: BFS
class Solution {
    void preorder(TreeNode *root, vector<int> &ans){
        if (!root) return;
        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
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


//////////////
// Sol2. Recursion: DFS
class Solution {
    void preorder(TreeNode *root, vector<int> &ans){
        if (!root) return;
        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
};


////////////
// Sol3. Divide and conquer
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;
            
        //divide
        vector<int> left = preorderTraversal(root->left);
        vector<int> right = preorderTraversal(root->right);
        
        //conquer
        res.push_back(root->val);
        res.insert(res.end(), left.begin(), left.end());
        res.insert(res.end(), right.begin(), right.end());
        
        return res;
    }
};