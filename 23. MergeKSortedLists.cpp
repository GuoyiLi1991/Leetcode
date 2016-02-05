/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* merge2Lists(ListNode* l1, ListNode* l2)
    //same as merge two sorted lists
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
    ListNode* divide_and_conquer(vector<ListNode*>&lists, int i, int j)
    {
        if (i == j)
            return lists[i];
        if (i == j-1)
            return merge2Lists(lists[i], lists[j]);
        return merge2Lists(divide_and_conquer(lists, i, (i+j)/2), divide_and_conquer(lists, (i+j)/2+1, j));
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *ret = NULL;
        int n = lists.size();
        if (n==0) return ret;
    
        while (n>1)
        {
            //********  Divide and conquer  O(NlogN) ************//
            int k = (n+1)/2;
            for (int i = 0; i < n/2; i++)
            {
                lists[i] = merge2Lists(lists[i], lists[i+k]);
            }
            n = k;
        }
        
        
        return lists[0];//divide_and_conquer(lists, 0, lists.size()-1);
        
    }
};


/*   Using Map 
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

*/