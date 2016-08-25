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
    void dfs(vector<NestedInteger>& nestedList, int& sum, int level) {
        for (int i = 0; i < nestedList.size(); i++) {
            NestedInteger item = nestedList[i];
            if (item.isInteger())
                sum += level * item.getInteger();
            else
                dfs(item.getList(), sum, level + 1);
        }
    }
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        int level = 1;
        int sum = 0;
        dfs(nestedList, sum, level);
        return sum;
    }
};


////////////
class Solution {
    int dfs(vector<NestedInteger>& nestedList, int level) {
        int sum = 0;
        for (int i = 0; i < nestedList.size(); i++) {
            NestedInteger item = nestedList[i];
            if (item.isInteger())
                sum += level * item.getInteger();
            else
                sum += dfs(item.getList(), level + 1);
        }
        return sum;
    }
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        return dfs(nestedList, 1);
    }
};