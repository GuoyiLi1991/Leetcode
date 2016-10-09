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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return NULL;
        if (n == 1)
            return new TreeNode(nums[0]);
        
        int mid = n/2;
        TreeNode *root = new TreeNode(nums[mid]);
    
        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid + 1, nums.end());
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);
        
        return root;
    }
};

/////////////////////
// Rewrite: no use of two vectors
/////////////////////
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
    TreeNode *sortedArrayToBST(vector<int> &nums, int start, int end) {
        if (start > end)
            return NULL;
        int mid = start + (end - start) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, start, mid - 1);
        root->right = sortedArrayToBST(nums, mid + 1, end);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return NULL;
        
        return DFS(nums, 0, nums.size() - 1);
    }
};