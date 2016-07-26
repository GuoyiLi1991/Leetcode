/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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