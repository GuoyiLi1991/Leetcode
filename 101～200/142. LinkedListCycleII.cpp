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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            
            if (fast == slow)
                break;
        }
        
        if (!(fast && fast->next)) //no cycle
            return NULL;
        
        //has cycle, the second collision will be the entrance
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        
        return fast;
    }
};