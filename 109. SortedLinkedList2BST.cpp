/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    // ListNode *list;
    int getLength(ListNode *head) {
        int len = 0;
        while (head){
            len++;
            head = head->next;
        }
        return len;
    }
    TreeNode *generate(int n, ListNode * & head) {
        if (n == 0)
            return NULL;
        TreeNode *node = new TreeNode(0);
        
        node->left = generate(n/2, head);
        node->val = head->val;
        head = head->next;
        node->right = generate(n-1 - n/2, head);
        return node;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int len = getLength(head);
        return generate(len, head);
    }
};