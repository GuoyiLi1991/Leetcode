/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* vec2List(vector<int> num)
    {
        ListNode *head = NULL;
        for (int i: num)
        {
            /***** Add to the end of list******/
            ListNode *tmp = new ListNode(i);
            if (head == NULL)
                head = tmp;
            else
            {
                
                ListNode *ptr = head;
                while(ptr->next) 
                    ptr = ptr->next;
                ptr->next = tmp;
                /
            }
            /**********************************/
        }
        return head;
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


///// Another way: without converting to vector ////////////
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
            p = p->next = new ListNode(sum%10);
        }
        p->next = NULL;
        return res->next;
    }
};