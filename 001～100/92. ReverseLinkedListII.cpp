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



//////////////////
// my version, complicated but beat 92%
// convert directly from reverse linked list
class Solution {
    ListNode* reverseList(ListNode *head) {
        if (!head || !head->next)
            return head;
        ListNode *pre = NULL;
        ListNode *next = NULL;
        while (head) {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }

        return pre;
    }
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m >= n)
            return head;
        ListNode *start = head;
        ListNode *end = head;
        for (int i = 0; i < n - 1; i++) {
            if (i < m - 2)
                start = start->next;
            end = end->next;
        }
        ListNode *rest = end->next;
        end->next = NULL;
        if (m != 1)
            start->next = reverseList(start->next);
        else
            head = reverseList(head);
            
        while (start->next) {
            start = start->next;
        }
        start->next = rest;
        return head;
        
        
    }
};


