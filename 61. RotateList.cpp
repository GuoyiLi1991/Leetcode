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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k <= 0) 
            return head;
            
        ListNode *ptr = head;
        ListNode *res;
        int len = 1;
        while (ptr->next)
        {
            len++;
            ptr = ptr->next;
        }
        
        k = k % len;
        
        ptr->next = head; //make it a circle 
        if (k)  //ptr now should move to the (len-k)th position to find the new head
        {
            for (int i = 0; i< len-k; i++) 
                ptr = ptr->next;
        }
        res = ptr->next;
        ptr->next = NULL;
        return res;
        
    }
};