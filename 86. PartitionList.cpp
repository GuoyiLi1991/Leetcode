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
    ListNode* partition(ListNode* head, int x) {
        if (!head) return NULL;
        ListNode smallDummy(0), greatDummy(0);
        ListNode *smallTail = &smallDummy;
        ListNode *greatTail = &greatDummy;
        
        while (head != NULL) {
            if (head->val < x) { //add to rear of smaller ll
                smallTail->next = head;
                smallTail = head;
            }
            else { //add to rear of greater ll
                greatTail->next = head;
                greatTail = head;
            }
            head = head->next;
        }
        
        //combine the two ll
        smallTail->next = greatDummy.next;
        greatTail->next = NULL;
        
        
        return smallDummy.next;
    }
};



