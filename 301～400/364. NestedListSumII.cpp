/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

 //Sol1. 
class Solution {
    void getDepth(int& maxDepth, int curDepth, vector<NestedInteger> &nestedList) {
        maxDepth = max(maxDepth, curDepth);
        for (int i = 0; i < nestedList.size(); i++) {
            if (!nestedList[i].isInteger()) {
                getDepth(maxDepth, curDepth + 1, nestedList[i].getList());
            }
        }
    }
    void dfs(int &sum, int curDepth, vector<NestedInteger> &nestedList) {
        for (int i = 0; i < nestedList.size(); i++) {
            if (!nestedList[i].isInteger()) {
                dfs(sum, curDepth - 1, nestedList[i].getList());
            }
            else
                sum += curDepth * nestedList[i].getInteger();
        }
    }
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        if (nestedList.size() == 0) return 0;
        
        int maxDepth = 1;
        int sum = 0;
        getDepth(maxDepth, 1, nestedList);
        dfs(sum, maxDepth, nestedList);
        
        return sum;
    }
};

////////////
// Sol2.
class Solution {
    void dfs(map<int, int> &depth_sum, int curDepth, vector<NestedInteger> &nestedList) {
        depth_sum[curDepth] += 0; //!!!!!!e.g.[[[8]]]
        for (int i = 0; i < nestedList.size(); i++) {
            if (!nestedList[i].isInteger()) {
                dfs(depth_sum, curDepth - 1, nestedList[i].getList());
            }
            else
                depth_sum[curDepth] += nestedList[i].getInteger();
                // sum += curDepth * nestedList[i].getInteger();
        }
    }
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        if (nestedList.size() == 0) return 0;
        
        int sum = 0;
        map<int, int> depth_sum;
        dfs(depth_sum, 0, nestedList);
        
        int maxDepth = depth_sum.size();
        for (auto item : depth_sum) {
            int curDepth = maxDepth + item.first;
            sum += item.second * curDepth;
        }
        cout << maxDepth;
        return sum;
    }
};