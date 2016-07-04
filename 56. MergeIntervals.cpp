/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        sort(intervals.begin(), intervals.end(), 
                [](Interval i1, Interval i2)
                {
                    return i1.start<i2.start;
                });
        for (Interval v:intervals)
        {
            if (ans.empty() || ans.back().end < v.start)
                ans.push_back(v);
            else
                ans.back().end = max(v.end, ans.back().end);
        }
        return ans;
        
    }
};