//Difference: Instead of finding the closest, we want k closest

/////////
// Sol1. Iterative: Variation from in-order traversal
class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode *ptr = root;
        
        while (ptr || !st.empty()) {
            if (ptr) {
                st.push(ptr);
                ptr = ptr->left;
            }
            else {
                ptr = st.top();
                st.pop();
                
                //==========the only difference is how we store the res========//
                if (res.size() < k)
                    res.push_back(ptr->val);
                else { //res.size() == k
                    if (fabs(ptr->val - target) < fabs(res.front() - target)) { //better sol
                        //need to erase element from res to insert better sol
                    res.erase(res.begin());
                    res.push_back(ptr->val);
                    }
                    else break; //no better
                }
                //========= Other part is just a basic iterative inorder=======//
                ptr = ptr->right;
            }
        }
        
        return res;
    }
};

/////////
// Sol2. Recursive
class Solution {
    void dfs(vector<int>& res, TreeNode* root, double target, int k) {
        if (!root) return;
        
        dfs(res, root->left, target, k);
        
        if (res.size() < k) {
            res.push_back(root->val);
        }
        else if (fabs(root->val - target) < fabs(res.front() - target)) { //better sol
                        //need to erase element from res to insert better sol
            res.erase(res.begin());
            res.push_back(root->val);
        }
        else return;
        
        dfs(res, root->right, target, k);
    }
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        dfs(res, root, target, k);
        
        return res;
    }
};