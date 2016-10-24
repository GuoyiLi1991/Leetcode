/*
Given a singly linked list, group all odd nodes together 
followed by the even nodes. 

Please note here we are talking about the node number 
and not the value in the nodes.
*/

// Sol1. Inplace
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

// Sol2. Similar to 86. LinkedList partition

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
            return head;
            
        ListNode oddDummy(0), evenDummy(0);
        ListNode *oddTail = &oddDummy;
        ListNode *evenTail = &evenDummy;
        
        while (head) {
            oddTail->next = head;
            oddTail = head;
            
            head = head->next;
            if (!head)
                break;
            evenTail->next = head;
            evenTail = head;
            
            head = head->next;
        }
        
        oddTail->next = evenDummy.next;
        evenTail->next = NULL;
        
        return oddDummy.next;
    }
};