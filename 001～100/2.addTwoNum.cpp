// Question: 
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
///////////////////
// Sol1. store res in vector and convert back to LL
// Time: O(M + N), Space: O(max(m, n))
class Solution {
    ListNode* vec2List(vector<int> num)
    {
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        for (int i: num)
        {
            p->next = new ListNode(i);
            p = p->next;
        }
        return head->next;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 = l1, *ptr2 = l2;
        vector<int> ans;
        int c = 0; //carry
        while( ptr1 || ptr2)
        {
            int n1 = 0, n2 = 0, d = 0;
            if (ptr1)
            {
                n1 = ptr1->val;
                ptr1 = ptr1->next;
            }
            if (ptr2)
            {
                n2 = ptr2->val;
                ptr2 = ptr2->next;
            }
            d = n1 + n2 + c;
            c = d/10;
            
            //add to result
            ans.push_back(d%10);
        }
        
        //deal with the most significant digit
        if (c ==1)
            ans.push_back(c);
        return vec2List(ans);
        
    }
};


////////////////////////////
// Sol2. Iterative, without the vector
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(0);
        ListNode *p = res;
        
        int c = 0; //carry
        while (l1 || l2 || c) {
            int v1 = 0, v2 = 0;
            if (l1) {
                v1 = l1->val;
                l1 = l1->next;
            }
            if (l2) {
                v2 = l2->val;
                l2 = l2->next;
            }
            int sum = c + v1 + v2;
            c = sum /10;
            p->next = new ListNode(sum%10);
            p = p->next;
        }
        return res->next;
    }
};


////////////////////////////////
// Sol3. Recursive
class Solution {
    ListNode *backward(ListNode* l1, ListNode* l2, int& carry) {
        if (!l1 && !l2 && !carry)
            return NULL;
    
        //current case:
        int v1 = 0, v2 = 0;
        if (l1) {
            v1 = l1->val;
            l1 = l1->next;
        }
        if (l2) {
            v2 = l2->val;
            l2 = l2->next;
        }
        
        int sum = carry + v1 + v2;
        carry = sum /10;
        ListNode* res = new ListNode(sum%10);
        

        //recursive
        res->next = backward(l1, l2, carry);
        
        return res;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        return backward(l1, l2, carry);
    }
};

////////////
// Follow up: what if the numbers are stored in forward order
// eg. [4,3] + [6,4] = [1, 0, 7]
// Difference: 
// - need padding to make alignment
// - recursion call first
class Solution {
    int len(ListNode *l) {
        int len = 0;
        
        for (ListNode *p = l; p; p = p->next)
            len++;
        
        return len;
    }
    
    void makeEqualLength(ListNode* &l1, ListNode* &l2) {
        int len1 = len(l1);
        int len2 = len(l2);
        
        if (len1 == len2) return;
        if (len1 > len2) {
            //padding 0's at the beginning of l2
            int diff = len1 - len2;
            while (diff--) {
                ListNode* dummy = new ListNode(0);
                dummy->next = l2;
                l2 = dummy;
            }
        }
        else {
            makeEqualLength(l2, l1);
        }
    }
    ListNode *forward(ListNode* l1, ListNode* l2, int& carry) { 
        //before calling this function, l1 and l2 are made equal length
        if (!l1) return NULL;
    
        //recursive
        ListNode* res = new ListNode(0);
        res->next = forward(l1->next, l2->next, carry);
        
        //current case
        int sum = carry + l1->val + l2->val;
        carry = sum /10;
        res->val = sum % 10;
        
        return res;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        makeEqualLength(l1, l2);
        
        int carry = 0;
        ListNode* res = forward(l1, l2, carry);
        
        if (carry) {
            ListNode* dummy = new ListNode(1);
            dummy->next = res;
            res = dummy;
        }
        
        return res;
    }
};