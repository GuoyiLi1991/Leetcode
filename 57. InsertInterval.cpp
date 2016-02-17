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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int n = intervals.size();
        vector<Interval> ans;
        if (n == 0)
        {
            ans.push_back(newInterval);
            return ans;
        }
        
        int i = 0;
        while (i<n && newInterval.start >intervals[i].end)   //before pos
            ans.push_back(intervals[i++]);
            
        if (i ==n)
        {
            ans.push_back(newInterval);
            return ans;
        }
            
        int s = min(newInterval.start, intervals[i].start);  //pos
        int e;
        
        while (i<n && newInterval.end >= intervals[i].start)
            e = max(newInterval.end, intervals[i++].end);
        ans.push_back(Interval(s,e));
        
        while(i<n)                      //after pos
            ans.push_back(intervals[i++]);
        
        return ans;
    }
};