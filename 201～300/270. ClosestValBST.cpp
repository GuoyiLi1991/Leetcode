class Solution {
    int res = INT_MAX;
public:
    int closestValue(TreeNode* root, double target) {
        if (res == INT_MAX) res = root->val;
        //base case:
        double minDist = fabs(res - target);
        double curDist = fabs(root->val - target);
        if (curDist < minDist) {
            minDist = curDist;
            res = root->val;
        }
        
        //recursion
        if (root->val > target) {//seach left 
            if (root->left)
                return closestValue(root->left, target);
            else
                return res;
        }
        else { //search right
            if (root->right)
                return closestValue(root->right, target);
            else 
                return res;
        }
    }
};
