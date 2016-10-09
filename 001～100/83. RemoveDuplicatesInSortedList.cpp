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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *fast = head->next, *slow = head;
        while (fast) {
            if (fast->val == slow->val) {
                fast = fast->next;
            }
            else {
                slow->next = fast;
                fast = fast->next;
                slow = slow->next;
            }
        }
        slow->next= NULL;
        return head;
        
            
        
    }
};