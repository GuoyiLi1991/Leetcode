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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;
            
        ListNode *dummy = new ListNode(0), *p = dummy;
        ListNode *slow = head, *fast = slow->next;
        while (fast) {
            p->next = fast;
            fast = fast->next;
            p->next->next = slow;
            slow = fast;
            if (slow) fast = slow->next;
            p = p->next->next;
        }
        p->next = slow;
        return dummy->next;
    }
};