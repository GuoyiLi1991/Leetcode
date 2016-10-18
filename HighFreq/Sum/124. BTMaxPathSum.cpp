// Sol1. 暴力搜索得出树中两两节点之间的路径和，取最小
// Time: O(n^2)

// Sol2. Divide & conquer
// Time: O(n), Space: O(h), h is depth of recursion stack
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
        int sp = max(0, max(left->singlePath, right->singlePath) + root->val); //要么取root要么不取
        int mp = max(left->maxPath, max(right->maxPath, left->singlePath + right->singlePath + root->val));
        
        return new ResultType(sp, mp);
    }
public:
    int maxPathSum(TreeNode* root) {
        return helper(root)->maxPath;
    }
};

// Sol 2-2: same idea, more concise by holding a global var maxValue
class Solution {
    int maxValue;
    int maxPathDown(TreeNode* node) { // contain only downwards direction
        if (!node) return 0;
        
        //divide
        int left = max(0, maxPathDown(node->left));
        int right = max(0, maxPathDown(node->right));
        
        //conquer
        maxValue = max(maxValue, left + right + node->val);
        return max(left, right) + node->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        maxValue = INT_MIN;
        maxPathDown(root);
        return maxValue;
    }
};
