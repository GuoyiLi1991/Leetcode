/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class Solution {
    void dfs(int &res, vector<NestedInteger>& nestedList, int depth) {
        for (NestedInteger item : nestedList) {
            if (item.isInteger())
                res += depth * item.getInteger();
            else {
                dfs(res, item.getList(), depth + 1);
            }
        }
    }
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        int res = 0;
        dfs(res, nestedList, 1);
        return res;
        
    }
};