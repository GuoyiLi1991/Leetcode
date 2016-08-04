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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *ptr = head, *pre = NULL;
        while (ptr) {
            if (ptr->val == val)
            {
                if (!pre) {  //delete head
                    head = head->next;
                    delete ptr;
                    ptr = head;
                }
                else {
                    pre->next = ptr->next;
                    delete ptr;
                    ptr = pre->next;
                }
            }
            else {
                pre = ptr;
                ptr = ptr->next;
            }
        }
        return head;
    }
};

///////////
// Another version
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // removing head
        while (head && head->val == val)
            head = head->next;
        // in-middle elements
        ListNode *p = head;
        while (p && p->next) {
            ListNode *cur = p;
            p = p->next;
            if (p->val == val) {
                cur->next = p->next;
                delete p;
                p = cur;
            }
        }
        //removing last one
        if (p && p->val == val) {
            p = NULL;
            delete p;
        }
        return head;
    }
};