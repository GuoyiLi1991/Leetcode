// directly converted from 108.
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
    TreeNode *sortedListToBST(ListNode*head, ListNode *tail) {
        if (head == tail) //empty
            return NULL;
        if (head->next == tail) //one node
            return new TreeNode(head->val);
        
        //find mid point
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != tail && fast->next != tail) {
            slow = slow ->next;
            fast = fast->next->next;
        }
        
        //now slow is the mid point
        TreeNode *root = new TreeNode(slow->val);
        root->left = sortedListToBST(head, slow);
        root->right = sortedListToBST(slow->next, tail);
        
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return sortedListToBST(head, NULL);
    }
};

////////////////////////////////////////////
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