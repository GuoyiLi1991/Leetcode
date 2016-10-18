/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* helper(vector<int>& nums) {
        int c = 1; //carry
        int n = nums.size();
        for (int i = n - 1; i >= 0; i--) {
            int d = nums[i] + c;
            c = d / 10;
            nums[i] = d % 10;
            if (c == 0) break;
        }
        if (c == 1)
            nums.insert(nums.begin(), 1);
        
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;
        for (int i = 0; i < nums.size(); i++) {
            p->next = new ListNode(nums[i]);
            p = p->next;
        }
        
        return dummy->next;
    }
public:
    ListNode* plusOne(ListNode* head) {
        vector<int> nums;
        ListNode* p = head;
        while (p != NULL) {
            nums.push_back(p->val);
            cout <<p->val;
            p = p->next;
        }
        
        return helper(nums);
    }
};