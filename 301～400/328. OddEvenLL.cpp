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
    ListNode* oddEvenList(ListNode* head) {
        //corner case: 0 or 1 node
        if (!head || !head->next) return head;
        
        ListNode *slow = head, *fast = head->next; //slow points to odd, fast points to even
        while (fast && fast->next) {
            ListNode *tmp = slow->next;
            slow->next = fast->next;
            fast->next = fast->next->next;
            slow->next->next = tmp;
            
            fast = fast->next;
            slow = slow->next;
        }
        
        return head;
    }
};