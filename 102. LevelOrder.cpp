// Sol1. DFS
class Solution {
    void dfs(TreeNode *root, vector<vector<int>> &ans, int level)
    {
        if (!root) return;
        if (ans.size() < level +1)
            ans.push_back(vector<int>{});
        ans[level].push_back(root->val);
        dfs(root->left, ans, level+1);
        dfs(root->right, ans,level+1);
    }
    
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root, ans, 0);
        return ans;        
    }
};

// Sol2. BFS (三种写法)
/*
- 2 queues: 交替存儿子
- 1 queue with "#"
- 1 queue
*/
// BFS-1 queue<TreeNode*, int> //<node, level>
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;

        queue<pair<TreeNode*, int>> q; //<node, level>
        q.push(make_pair(root, 0));  //enqueue
        
        while(!q.empty())
        {
            //pair<TreeNode*, int> cur = q.front();
            TreeNode* cur = q.front().first;
            int level = q.front().second;
            if (cur->left)
                q.push(make_pair(cur->left, level+1));
            if (cur->right)
                q.push(make_pair(cur->right, level+1));
                
             q.pop();  //dequeue
             if (ans.size() < level+1)
                ans.push_back(vector<int>{});
            ans[level].push_back(cur->val);
            
        }
        
        return ans;
        
    }
};

// BFS-2 queue with for-loop
class Solution { 
    vector<vector<int>> bfs(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        
        queue<TreeNode*> q; 
        q.push(root);
        
        while (!q.empty()) {
            vector<int> level;

            int size = q.size();//容易出错！先存起来当前size！
            
            for (int i = 0; i < size; i++) {
                TreeNode* tmp = q.front();
                q.pop();

                level.push_back(tmp->val);
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }

            res.push_back(level);
        }
        
        return res;
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        return bfs(root);
    }
};