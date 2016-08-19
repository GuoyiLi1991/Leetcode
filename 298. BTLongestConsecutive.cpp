/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // Sol 1. Record parent node
class Solution {
    int longestConsecutive(TreeNode *root, TreeNode *child,  int len) {
        if (!child) return len;
        
        len = (root && root->val + 1 == child->val)? len + 1: 1;

        return max(len, max(longestConsecutive(child, child->left, len), longestConsecutive(child, child->right, len)));
    }

public:
    int longestConsecutive(TreeNode* root) {
        return longestConsecutive(NULL, root, 0);
    }
};

///////////
// Sol 2: record parent value
class Solution {
    int longest(TreeNode *root, int lastValue, int curLen){
        if (!root) return curLen;
        if (root->val  == lastValue + 1)
            curLen++;
        else
            curLen = 1;
        
        //recursion
        int lvalue = longest(root->left, root->val, curLen);
        int rvalue = longest(root->right, root->val, curLen);
        return max(curLen, max(lvalue, rvalue));
    }
public:
    int longestConsecutive(TreeNode* root) {
        if (!root) return 0;
        
        return longest(root, INT_MAX, 0);
        
    }
};