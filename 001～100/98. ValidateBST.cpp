// Sol1. isSorted(inorder_vector)
// O(n) time O(n) space
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
// Sol 2: maintain a prev node
class Solution {
    bool inorder(TreeNode*root, TreeNode *&prev)
    {
        if (!root) return true;
        
        if (inorder(root->left, prev) ||
            prev && prev->val >= root->val)
            return false;
        
        prev = root;
        return (inorder(root->right, prev));
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
        /****** Sol 2. compare current node with the previous one ******/
        TreeNode *prev = NULL;
        return sol2(root, prev);
    }
};

////////
// Sol2-2 prev as global var
class Solution {
    TreeNode *prev;
    bool isValid(TreeNode* root) {
        if (!root) return true;
    
        if (!isValid(root->left) || 
            prev && prev->val >= root->val )
            return false;
            
        prev = root;
        return isValid(root->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        prev = NULL;
        if (root && !root->left && !root->right)
            return true;
    
        return isValid(root);
    }
};

/////////
// Sol3. Maintain range nodes
class Solution {
    bool sol3(TreeNode *root, TreeNode *minNode, TreeNode *maxNode)
    {
        if (!root)
            return true;
        if ((minNode && root->val <= minNode->val) 
            || (maxNode && root->val>= maxNode->val))
            return false;
        return sol3(root->left, minNode, root) 
        && sol3(root->right, root, maxNode);
    }
    
public:
    bool isValidBST(TreeNode* root) {
        return sol3(root, NULL, NULL);
    }
};



//////////
// Sol3-2 maintain range values
// Problem with limits values, better use the "node"
class Solution {
    bool isValid(TreeNode* root, int min, int max) {
        if (!root) return true;
    
        if (root->val <= min || root->val >= max)
            return false;
            
        return isValid(root->left, min, root->val) 
        && isValid(root->right, root->val, max);
    }
public:
    bool isValidBST(TreeNode* root) {
        if (root && !root->left && !root->right)
            return true;
    
        return isValid(root, INT_MIN, INT_MAX);
    }
};

