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
