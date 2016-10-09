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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head;
        int len = 0;
        while (p) {
            len++;
            p = p->next;
        }
        if (n > len)
            return head;
        p = head;
        n = len - n - 1;
        //if delete the head
        if (n < 0)
            return head->next;
        //else 
        while (n--){
            p = p->next;
        }
        ListNode *tmp = p->next;
        if (tmp)
            p->next = tmp->next;
        delete tmp;
        return head;
        
    }
};