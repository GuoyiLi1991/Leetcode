/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 // Sol1. BFS
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        
        RandomListNode *copy = new RandomListNode(head->label);
        unordered_map<RandomListNode*, RandomListNode*> mapping;
        mapping[head] = copy;
        
        queue<RandomListNode*> q; //BFS
        q.push(head);
        
        while (!q.empty()) {
            RandomListNode* original = q.front();
            RandomListNode* duplic = mapping[original];
            q.pop();
            

            if (original->next) {
                if (mapping.count(original->next) == 0) {
                    mapping[original->next] = new RandomListNode(original->next->label);
                    q.push(original->next);
                }
                duplic->next = mapping[original->next];
            }
            
            if (original->random) {
                if (mapping.count(original->random) == 0) {
                    mapping[original->random] = new RandomListNode(original->random->label);
                    q.push(original->random);
                }
                duplic->random = mapping[original->random];
            }
        }
        
        return copy;
    }
};



/////////////////////
// Sol2. DFS
class Solution {
    unordered_map<RandomListNode*, RandomListNode *> ht;
    RandomListNode* copyNode(RandomListNode *head) {
        if (!head) return NULL;
        
        if (ht.find(head) != ht.end())
            return ht[head];
            
        ht[head] = new RandomListNode(head->label);
        if (head->next) 
            ht[head]->next = copyNode(head->next);
        if (head->random)
            ht[head]->random = copyNode(head->random);
        
        return ht[head];
    }
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        return copyNode(head);
    }
};