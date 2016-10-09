/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 // Sol1. Recursive
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *dummy = reverseList(head->next);
        
        head->next->next = head;
        head->next = NULL;
        
        return dummy;
    }
};

//////////
// Sol 2. Iterative 
// In-place, O(n) time
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *pre = NULL, *post = NULL;
        ListNode *cur = head;
        while (cur) {
            post = cur->next; //advance post
            cur->next = pre;  //reverse cur and pre
            pre = cur;    //advance pre
            cur = post;   //advance p
        }
        return pre;
    }
};


/////////////////
// Sol 3. Iterative II
// Need extra space for LL creation: insert node to head
// O(n) space, O(n) time
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //corner case: 0 or 1 node
        if (!head || !(head->next)) return head;

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
    }
};


