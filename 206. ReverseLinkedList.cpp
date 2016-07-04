/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //corner case: empty or only one node
        if (!head || !(head->next)) return head;
        
        /******** Iterative ************/
        /*
        ListNode *ret= NULL;
        ListNode *ptr = head;
        while(ptr)
        {
            ListNode *tmp = ptr->next;
            ptr->next = ret;
            ret = ptr;
            ptr = tmp;
        }

        return ret;
        
        */
        /********* Recursive ***********/
        
        struct ListNode *root = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return root;

        
    }
};