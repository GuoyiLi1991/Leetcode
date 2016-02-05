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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * l3 = NULL; //store result
        if (!l1 && !l2) return l3;
        if (!l1) return l2;
        if (!l2) return l1;
        
       // ListNode* p1 = l1, *p2 = l2;
        ListNode* tail = NULL;
        ListNode *tmp;
        while(l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                tmp  = new ListNode(l1->val);
                l1 = l1->next;
            }
            else
            {
                tmp  = new ListNode(l2->val);
                l2 = l2->next;
            }
            //insert tmp to l3 head
            if (!l3) 
            {
                l3 = tmp;
                tail = tmp;
            }
            else
            {
                tail->next = tmp;
                tail = tail->next;
            }
        }
        if (l1) tail->next = l1;
        else if (l2) tail->next = l2;
        
        return l3;
    }
};