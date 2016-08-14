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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *res = new ListNode(INT_MIN);
        for (ListNode *p = head; p != NULL; p = p->next) {
            int val = p->val;
            ListNode *pp = res;
            ListNode *pre = res;
            while (pp && pp->val <= val) {
                pre = pp;
                pp = pp->next;
            }
            pre->next = new ListNode(val);
            pre->next->next = pp;
        }
        return res->next;
    }
};