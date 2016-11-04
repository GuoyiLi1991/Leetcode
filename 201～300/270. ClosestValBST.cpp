/////////////
// Sol1. Recursive BS

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
                return min(closestValue(root->left, target);
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


//////////
// Sol 2. Iterative BS

class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int res = root->val;
        double minDist = fabs(res - target);
        
        while (root) {
            double curDist = fabs(root->val - target);
            if (curDist < minDist) { //find better sol, update res
                res = root->val;
                minDist = curDist;
            }
            
            //binary search
            if (root->val < target) //search right
                root = root->right;
            else
                root = root->left;
        }
        
        return res;
    }
};
