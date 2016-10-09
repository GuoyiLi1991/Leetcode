/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 /// Naively, convert linked list to vector and check
 // O(n) time and O(n) space
class Solution {
    vector<int> ll2vec(ListNode* head) {
        vector<int> res;
        while (head) {
            res.push_back(head->val);
            head = head->next;
        }
        return res;
    }
public:
    bool isPalindrome(ListNode* head) {
        vector<int> vec = ll2vec(head);
        for (int i = 0; i < vec.size()/2; i++) {
            if (vec[i] != vec[vec.size() - 1 - i])  
                return false;
        }
        return true;
    }
};

/////////////////////////
// Reverse second half of the list 
// and compare with first half

class Solution {
    ListNode *reverseList(ListNode *head) {
        if (!head || !head->next)
            return head;
            
        ListNode *root = reverseList(head->next);
        
        head->next->next = head;
        head->next = NULL;
        
        return root;
    }
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) // 0 or 1 node only
            return true; 
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        } // now fast is the tail, slow is the mid point
        
        slow->next = reverseList(slow->next);
        slow = slow->next;
        while (slow) {
            if (head->val != slow->val)
                return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
};