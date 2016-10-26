class Solution {
    vector<TreeNode*> q;
    TreeNode* inorder(TreeNode*root, TreeNode **prev) {
        if (!root) return;
        
        inorder(root->left);
        if (prev == p)
            return root;
        prev = root;
        // q.push_back(root);
        inorder(root->right);
    }
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        return inorder(root, NULL);
        // vector<TreeNode*>::iterator it = find(q.begin(), q.end(), p);
        // if (it + 1 == q.end()) return NULL;
        //return *(++it); 
    }
};

//////////
//recursive
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
    //Tree
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        
        if (root == NULL) return NULL;
        
        //find the rightmost subtree that contains ele larger than p
        if (root->val <= p->val) 
            return inorderSuccessor(root->right, p);
        
        //can we make it smaller?
        TreeNode *left = inorderSuccessor(root->left, p);
        if (left == NULL)
            return root;
        else 
            return left;
        
    }
};

////////////
// Iterative
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root) return NULL;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        
        bool found = false;
        while (cur || !st.empty()) {
            if (cur) {
                st.push(cur);
                cur = cur->left;
            }
            else {
                cur = st.top();
                st.pop();
                if (found) return cur;
                
                if (cur == p)
                    found = true;

                cur = cur->right;
            }
        }
        return NULL;
    }
};


//////////////
// Follow-up: precessor
public TreeNode predecessor(TreeNode root, TreeNode p) {
  if (root == null)
    return null;

  if (root.val >= p.val) {
    return predecessor(root.left, p);
  } else {
    TreeNode right = predecessor(root.right, p);
    return (right != null) ? right : root;
  }
}