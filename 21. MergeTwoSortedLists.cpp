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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {  //8ms
        if (!l1 || !l2) return (l1)? l1:l2;
        
        ListNode * l3 = new ListNode(0); //store result
        ListNode* tail = l3;
        while(l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        if (l1) tail->next = l1;
        else if (l2) tail->next = l2;
        
        return l3->next;
    }
};

//////////// Recursion 8ms////////////////
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val < l2->val) { 
            l1 -> next = mergeTwoLists(l1->next,l2); 
            return l1; 
        }
        else { 
            l2 -> next = mergeTwoLists(l2->next,l1); 
            // Here, order does not matter to get the correct answer. However, it's
            // faster if we put l2->next first, as it will always lead the if fork to 
            // the first part
            return l2; 
        }
    }
};

//////////////////////////////////////////

/* using map  12ms
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 || !l2) return (l1)? l1:l2;
        
        ListNode * l3 = new ListNode(0); //store result
        ListNode *p = l3;
        
        map<int,int> order;
        
        while (l1)
        {
            order[l1->val]++;
            l1 = l1->next;
        }
        while(l2) 
        {
            order[l2->val]++;
            l2 = l2->next;
        }
        
        for (auto num:order)
        {
            while (num.second--)
            {
                ListNode *tmp = new ListNode(num.first);
                p->next = tmp;
                p = p->next;
            }
        }
        
        return l3->next;
    }

    */