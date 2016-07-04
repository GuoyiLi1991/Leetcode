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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        //corner case
        if (m == n || !head || !head->next)
            return head;
          
        ListNode dummy(0); // safeguard head node 
        ListNode *prev = &dummy;
        prev->next = head;
        
        for (int i =0 ; i < m-1; i++)
            prev = prev->next;      //prev is (m-1)-th
            
        ///////////////////////////////////////////
        ListNode *cur = prev->next; 
        ListNode *post = cur->next;
        
        for (int i =0; i < n-m; i++) {
            ListNode *ppost = post->next;
            post->next = cur;
            cur = post;
            post = ppost;
        }
        ///////////////////////////////////////////
        
        ListNode *tmp = prev->next;  
        prev->next = cur; //cur points to the original n-th, now should be m-th
        tmp->next = post; //post points to the original (n+1)th
        
        // for (int i = 0; i < n-m; i++) {
        //     ListNode *post = cur->next;
        //     cur->next = post->next;
        //     post->next = prev->next;
        //     prev->next = post;
        // }
        
        return dummy.next;
    }
};


