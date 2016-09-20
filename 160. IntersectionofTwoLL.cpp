/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 /*
 两种思路：
 http://www.cppblog.com/humanchao/archive/2015/03/22/47357.html
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        if (!p1 || !p2)
            return NULL;
            
        while ((p1 || p2) && (p1 != p2)) {
            p1 = p1->next;
            p2 = p2->next;
            
            if (p1 == p2) return p1;
            
            if (!p1) p1 = headB; //A is shorter, B tail to head and find cycle
            if (!p2) p2 = headA; //B is shorter, A tail to head and find cycle
        }

        //termination: either p1 p2 all NULL or p1 == p2
        return p1; //same with p2
    }
};

//////////////////////////////////
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        
        ListNode *p = headA, *q = headB;
        int l1 = 1, l2 = 1; //lenth of A and B
        while (p->next) {
            p = p->next;
            l1++;
        }
        while (q->next) {
            q = q->next;
            l2++;
        }
        if (p != q) // no intersection
            return NULL;
        
        p = headA;
        q = headB;
        int diff = l1 - l2;
        if (diff > 0) {
            for (int i = 0; i < diff; i++)
                p = p->next;
        }
        else {
            for (int i = 0; i < -diff; i++)
                q = q->next;
        }
        while (p != q) {
            p = p->next;
            q = q->next;
        }
        
        return p;
    }
};