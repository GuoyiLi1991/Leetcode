/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    void dfs(TreeNode*root, string &s) { //preorder traversal
        if (!root) {
            s += "# ";
            return;
        }
        else
            s += to_string(root->val) + ' ';
        dfs(root->left, s);
        dfs(root->right, s);
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string output;
        dfs(root, output);
        return output;
    }

    // Decodes your encoded data to tree.
    TreeNode* helper(stringstream &in) {
        TreeNode *root;
        
        string token;
        in >> token; 
        
        if (token == "#") return NULL;

        root = new TreeNode(stoi(token));
        root->left = helper(in);
        root->right = helper(in);

        return root;
    }
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return helper(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));