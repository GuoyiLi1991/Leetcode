// Sol1: Linkedlist->vector->linkedlist
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

//Sol2: Find the last not-nine
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode *p = head;
        ListNode *last_not_nine = dummy;
        
        while (p) {
            if (p->val != 9) 
                last_not_nine = p;
            p = p->next;
        }
        
        //add one
        last_not_nine->val++;
        //make elem after it to 0's
        p = last_not_nine->next;
        while (p) {
            p->val = 0;
            p = p->next;
        }
        
        if (dummy->val == 1)
            return dummy;
        else
            return dummy->next;
    }
};