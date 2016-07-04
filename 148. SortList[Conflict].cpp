/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //merge sort
class Solution {
    ListNode* merge(ListNode*l1, ListNode *l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        if (l1->val <= l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        }
        else {
            l2->next = merge(l2->next, l1);
            return l2;
        }
    }
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) //0 or 1 node
            return head;
            
        ListNode *fast, *slow;
        fast = slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        } //now slow is the mid point
        
        ListNode *tmp = slow->next;
        slow->next = NULL;
        return merge(sortList(head), sortList(tmp));  //head till slow is L, tmp till end is R
        
        
    }
};
