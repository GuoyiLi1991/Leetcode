// Sol1. Kth popped element in In-order
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int i= 0; //return when i == k
        
        stack<TreeNode*> st;
        TreeNode *cur = root;
        while (cur || !st.empty()) {
            if (cur) {
                st.push(cur);
                cur = cur->left;
            }
            else {
                cur = st.top();
                if (++i == k)
                    return cur->val;
                st.pop();
                cur = cur->right;
            }
        }
        return -1;
    }
};

// Sol3. Direct in-order (Best)
// Time: O(n), or O(lgn) only if it is well balanced
class Solution {
public:
    int kthSmallest(TreeNode* root, int &k) {
        if (!root) return -1;
        
        int x = kthSmallest(root->left, k);
        if (k == 0) return x;
        else if (--k == 0)
            return root->val;
        else
            return kthSmallest(root->right, k);
    }
};


// Sol3. min Heap
// not good, did not use the property of BST
class Solution {
    void traverse(TreeNode *root, priority_queue<int, vector<int>, std::greater<int>> &pq) {
        if (!root) return;
        pq.push(root->val);
        
        traverse(root->left, pq);
        traverse(root->right, pq);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return -1;
        
        priority_queue<int, vector<int>, std::greater<int>> pq;
        traverse(root, minHeap);
        while (--k)
            pq.pop();
        return pq.top();
    }
};