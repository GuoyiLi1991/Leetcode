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
    unordered_map<int, int> m; //<value, index> in inorder
    TreeNode* build(vector<int>& inorder, int s0, int e0,
                        vector<int>& postorder, int s1, int e1)
    {
        if (s0 >e0 || s1>e1)
            return NULL;
        TreeNode* root = new TreeNode(postorder[e1]);
        int mid = m[postorder[e1]];
        int length = mid -s0;
        
        
        root->left = build(inorder, s0, mid-1, postorder, s1, s1+length-1);
        root->right = build(inorder, mid+1, e0, postorder, s1+length, e1-1);
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        if (inorder.size() != n) throw("not valid");
        
        if (n ==0) return NULL;
        
        for (int i =0; i<n; i++)
            m[inorder[i]] = i;
            
        return build(inorder, 0, n-1, postorder, 0, n-1);
    }
};


/////////////////////////////
// Converted directorly from 105. 
// choose last element in postorder, find pos in inorder....
// 56ms

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
    TreeNode* helper(vector<int>& postorder, int i, int j, vector<int>& inorder, int ii, int jj) {
        //illegal
        if (i >= j || ii >= jj)
            return NULL;
        
        int val = postorder[j - 1];
        vector<int>::iterator pos = find(inorder.begin() + ii, inorder.begin() + jj, val);
        int offset = pos - inorder.begin() - ii;
        
        TreeNode *root = new TreeNode(val);
        root->left = helper(postorder, i, i + offset, inorder, ii, ii + offset);
        root->right = helper(postorder, i + offset, j - 1, inorder, ii + offset + 1, jj);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) 
            return NULL;
        return helper(postorder, 0, postorder.size(), inorder, 0, inorder.size());
    }
};