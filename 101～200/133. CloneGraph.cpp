/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        
        UndirectedGraphNode *copy = new UndirectedGraphNode(node->label);
        queue< UndirectedGraphNode* > q;
        unordered_map< UndirectedGraphNode*, UndirectedGraphNode* > ht;
        q.push(node);
        ht[node] = copy;
        
        //clone node
        while (!q.empty()) {
            UndirectedGraphNode* original = q.front();
            UndirectedGraphNode* duplic = ht[original];
            q.pop();
            
            for (auto node : original->neighbors) {
               if (ht.count(node) == 0) {
                    q.push(node);
                    ht[node] = new UndirectedGraphNode(node->label);
                }
                duplic->neighbors.push_back(ht[node]);
            }
        }
        
        return copy;
    }
};


//////////
// Sol2. DFS
class Solution {
    unordered_map<int, UndirectedGraphNode*> ht;
    UndirectedGraphNode* clone(UndirectedGraphNode* node) {
        //given a node, return its cloned version
        if (!node) return NULL;
        
        if (ht.count(node->label)) //memorization
            return ht[node->label];
        
        UndirectedGraphNode* copy = new UndirectedGraphNode(node->label);
        ht[node->label] = copy;
        
        for (auto neighbor : node->neighbors) {
            copy->neighbors.push_back(clone(neighbor)); //recursion
        }
        
        return copy;
    }
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        return clone(node);
    }
};

