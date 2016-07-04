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
        //corner case: 0 or 1 node
        if (!head || !(head->next)) return head;
        
        /******** Iterative I ************/
        /*
        ListNode *prev= NULL;
        ListNode *cur = head;
        while(cur)
        {
            ListNode *next = cur->next;
            cur->next = prev; //reverse pointer direction

            prev = cur;    //move forward
            cur = next;  //move forward
        }

        return prev;

        /******** Iterative II **********/

        ListNode *ptr = head, *l = NULL;
        
        while (ptr)
        {
            ListNode *tmp = new ListNode(ptr->val);
            //insert to the head
            tmp->next = l;
            l = tmp;
            
            //ListNode *dtmp = ptr;
            //delete(dtmp);
            ptr = ptr->next;
        }
        return l;
        
        */
        /********* Recursive ***********/
        
        struct ListNode *root = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return root;

        
    }
};


