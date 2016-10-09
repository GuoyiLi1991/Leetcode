// Based on merge2Lists, apply divide and conquer

/*
During 1st iteration, we merge two lists(every list is N) into one, this will make K down to K / 2.
During 2nd iteration, we merge two lists(every list is 2N) into one, this will make K / 2 down to k /4.
During 3rd iteration, we merge two lists(every list is 4N) into one, this will make K / 4 down to k /8.

And so forth...

I think when we merge two lists, the complexity is O(list1.length) + O(list2.length).

So the total complexity is:

(2N) * (K / 2) + 
(4N) * (K / 4) + 
(8N) * (K / 8) + 
.............. + 
(2^logK*N) * (K / (2 ^logK)) 

= logK*KN, where K is number of lists, and N is length of each list.
*/

ListNode* merge2Lists(ListNode *l1, ListNode *l2) {
    // Recursive version
    if (!l1) return l2;
    if (!l2) return l1;
    if (l1->val < l2->val) {
        l1->next = merge2Lists(l1->next, l2);
        return l1;
    }
    else {
        l2->next = merge2Lists(l2->next, l1);
        return l2;
    }
}
ListNode* merge2Lists(ListNode* l1, ListNode* l2)
    //Iteratvie version
    {
        ListNode *l3 = new ListNode(0);
        ListNode *p = l3;
        
        if (!l1 || !l2) 
            return l1? l1:l2;
            
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                p->next = l1;
                p = p->next;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                p = p->next;
                l2 = l2->next;
            }
        }
        
        if (l1) p->next = l1;
        if (l2) p->next = l2;
        
        return l3->next;
    }
/////// Sol 1. Recursive divide and conquer 32ms
class Solution {
    ListNode* divide_conquer(vector<ListNode*>& lists, int i, int j) {
        // base case: only one or two lists left
        if (i == j)
            return lists[i];
        if (i + 1 == j)
            return merge2Lists(lists[i], lists[j]);

        // Recursive: partion into two parts, [i, mid] and [mid+1, j]
        // sort each part with divide_conquer(), and then merge them
        int mid = i + (j - i) / 2;
        return merge2Lists(divide_conquer(lists, i, mid), divide_conquer(lists, mid + 1, j));
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        return divide_conquer(lists, 0, lists.size() - 1);
    }
};

/////// Sol 2. Iterative divide and conquer 28ms
class Solution {
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n==0) return NULL;
    
        while (n>1)
        {
            //********  Divide and conquer  O(KlogK) ************//
            int k = (n+1)/2;
            for (int i = 0; i < n/2; i++)
            {
                lists[i] = merge2Lists(lists[i], lists[i+k]);
            }
            n = k;
        }
        
        return lists[0];
        
    }
};


//////// Sol 3. Using Map 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        map<int,int> order;
        for(auto &list:lists){
            while(list!=NULL){
                order[list->val]++;
                list=list->next;
            }
        }
        ListNode head(0);
        ListNode* tmp=&head;
        for(auto &num:order){
            while(num.second--){
                tmp->next=new ListNode(num.first);
                tmp=tmp->next;
            }
        }
        return head.next;
    }
};
