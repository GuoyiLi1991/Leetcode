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
    void dfs(TreeNode *root, int num, int& sum) {
        if (!root) return;
        num = num * 10 + root->val;
        //find leave, add to sum
        if (!root->left && !root->right) {
            sum += num;
            //cout << num <<endl;
            return;
        }
        //not leave, recursive
        if (root->left)
            dfs(root->left, num, sum);
        if (root->right)
            dfs(root->right, num, sum);
        
    }
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        dfs(root, 0, sum);
        return sum;
    }
};

/////////////
// Shorter version
class Solution {
    int sumSteps(TreeNode *root, int sum) {
        if (!root)
            return 0;
        sum = sum * 10 + root->val;
        if (!root->left && !root->right)
            return sum;
        return sumSteps(root->left, sum) + sumSteps(root->right, sum);
    }
public:
    int sumNumbers(TreeNode* root) {
        return sumSteps(root, 0);
    }
};