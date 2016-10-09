// Sol1. isSorted(inorder_vector)
class Solution {
    void inorder(vector<int>& nums, TreeNode* root) {
        if (!root) return ;
        inorder(nums, root->left);
        nums.push_back(root->val);
        inorder(nums, root->right);
    }
    
    bool isSorted(vector<int>& nums) {
        if (nums.size() < 2)
            return true;
            
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] >= nums[i + 1])
                return false;
        }
        return true;
    }
    
public:
    bool isValidBST(TreeNode* root) {
        vector<int> nums;
        inorder(nums, root);
        return isSorted(nums);
    }
};

//////////////////////////

class Solution {

    // bool isSorted(vector<int>&nums)
    // {
    //     for (int i = 0; i<nums.size()-1; i++)
    //     {
    //         if (nums[i]>=nums[i+1])
    //             return false;
    //     }
    //     return true;
    // }
    
    // void inOrder(TreeNode *root, vector<int> &nums)
    // {
    //     if (!root) return;
    //     inOrder(root->left, nums);
    //     nums.push_back(root->val);
    //     inOrder(root->right, nums);
    // }
    bool sol2(TreeNode*root, TreeNode *&prev)
    {
        if (!root) return true;
        
        if (sol2(root->left, prev) == false)
            return false;
            
        if (prev && prev->val >= root->val)
            return false;
        prev = root;
        
        return (sol2(root->right, prev));
    }
    bool sol3(TreeNode *root, TreeNode *minNode, TreeNode *maxNode)
    {
        if (!root)
            return true;
        if ((minNode && root->val <= minNode->val) || (maxNode && root->val>= maxNode->val))
            return false;
        return sol3(root->left, minNode, root) && sol3(root->right, root, maxNode);
    }
    
public:
    bool isValidBST(TreeNode* root) {
        /****** Sol 1. check if the inorder traversal is sorted ******/
        // if (!root) return true;
        // vector<int> nums;
        // inOrder(root, nums);
        // return isSorted(nums);
        /****** Sol 2. compare current node with the previous one ******/
        // TreeNode *prev = NULL;
        // return sol2(root, prev);
        /****** Sol 2. compare current node with the previous one ******/
        return sol3(root, NULL, NULL);
    }

};

