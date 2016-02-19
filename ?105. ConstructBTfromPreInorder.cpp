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
    unordered_map<int, int> m;
    TreeNode* build(vector<int>& preorder, int s0, int e0, 
                    vector<int>& inorder, int s1, int e1)
    {
        if (s0 >e0 || s1>e1)
            return NULL;
            
        TreeNode*root = new TreeNode(preorder[s0]);
        
        int mid = m[preorder[s0]];
        int length = mid-s1;
        
        root->left = build(preorder, s0+1, s0+length, inorder, s1, mid-1);
        root->right = build(preorder, s0+length+1, e0, inorder,mid+1, e1);
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if (!n) return NULL;
        
        for (int i = 0; i<n; i++)
            m[inorder[i]] = i;
            
        return build(preorder, 0, n-1, inorder, 0, n-1);
        
    }
};