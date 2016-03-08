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
    TreeNode* str2Node(string& data){
        int pos = data.find(',');
        string token = data.substr(0, pos);
        TreeNode* node = new TreeNode(stoi(token));
        data = data.substr(pos+1);
        
        return node;
    }
    TreeNode* mydeserialize(string& data)
    {
        TreeNode* root = nullptr;
        if (data[0] == '#') //empty node
        {
            if (data.size() > 1) //#,...
                data = data.substr(2);  
            return nullptr;
        }
        else //num{,num}
        {
            root = str2Node(data);
            root->left = mydeserialize(data);
            root->right = mydeserialize(data);
        }
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "#";
        int num = root->val;
        return to_string(num) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return mydeserialize(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));