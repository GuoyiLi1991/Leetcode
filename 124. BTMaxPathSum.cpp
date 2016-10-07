// Sol1. 暴力搜索得出树中两两节点之间的路径和，取最小
// Time: O(n^2)

// Sol2. Divide & conquer
// Time: O(n)
class ResultType{
public:
    int singlePath; //at least 0
    int maxPath; // at least one point
    ResultType() {
        singlePath = 0;
        maxPath = INT_MIN;
    }
    ResultType(int sp, int mp) {
        singlePath = sp;
        maxPath = mp;
    }
};
class Solution {
    ResultType* helper(TreeNode*root) { //D&C
        if (!root) return new ResultType();
        
        //divide
        ResultType* left = helper(root->left);
        ResultType* right = helper(root->right);
        
        //conquer
        int sp = max(0, max(left->singlePath, right->singlePath) + root->val);
        int mp = max(left->maxPath, max(right->maxPath, left->singlePath + right->singlePath + root->val));
        
        return new ResultType(sp, mp);
    }
public:
    int maxPathSum(TreeNode* root) {
        return helper(root)->maxPath;
    }
};