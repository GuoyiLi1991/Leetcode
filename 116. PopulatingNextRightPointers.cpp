/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
    void BFS(TreeLinkNode *root)
    {
        queue<TreeLinkNode*> q;
        
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size(); 
            //count the number of nodes on the same level
            
            TreeLinkNode *cur, *prev;

            /*** create a dummy head node to make code clean ***/
            TreeLinkNode *dummy = new TreeLinkNode(-1);

            cur = q.front();
            prev = dummy;
            prev->next = cur;
            
            while(n--)
            {   
                prev->next = cur;
                q.pop();
                
                if (cur->left)  q.push(cur->left);
                if (cur->right) q.push(cur->right);  
                //This is more universal than the assumption that
                // it is a perfect tree
                
                prev = cur;
                cur = q.front();
            }
            /**** set the tail node of the current level ***/
            //prev->next = NULL;
        }
    }
    
    void DFS(TreeLinkNode *tree)
    {
        if (!tree->left) //deepest level
            return;
        tree->left->next = tree->right;
        tree->right->next = (tree->next == NULL)?NULL:tree->next->left;
        DFS(tree->left);
        DFS(tree->right);
    }
    
    void iterative(TreeLinkNode *root)
    {
        while(root)   
        {
            TreeLinkNode *tmp = root;
            while(tmp)
            {
                if(tmp->left)
                {
                    tmp->left->next = tmp->right;
                    tmp->right->next = 
                        (tmp->next == NULL)?NULL:tmp->next->left;
                }
                tmp = tmp->next;
            }
            root = root->left;
        }
    }
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        
        iterative(root); //24ms
        //BFS(root);    //28ms
        //DFS(root);    //28ms
        
       
    }
};