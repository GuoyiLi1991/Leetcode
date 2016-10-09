/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {  //one scan
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int n = intervals.size();
        vector<Interval> ans;
        
        int i = 0;
       
        while (i<n && newInterval.start >intervals[i].end)   //before pos
            ans.push_back(intervals[i++]);
            
        while (i<n && newInterval.end >= intervals[i].start)  //pos
        {
            newInterval.start = min(newInterval.start, intervals[i].start);
            newInterval.end = max(newInterval.end, intervals[i].end);
            i++;
        }
        ans.push_back(newInterval);
        
        while(i<n)                      //after pos
            ans.push_back(intervals[i++]);
        
        return ans;
    }
};

//===================
//  Binary Search O(lgN)
//====================

class Solution {    
    
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int n = intervals.size();
        vector<Interval> ans;
        
        int i = 0;
       
        while (i<n && newInterval.start >intervals[i].end)   //before pos
            ans.push_back(intervals[i++]);
            
        while (i<n && newInterval.end >= intervals[i].start)  //pos
        {
            newInterval.start = min(newInterval.start, intervals[i].start);
            newInterval.end = max(newInterval.end, intervals[i].end);
            i++;
        }
        ans.push_back(newInterval);
        
        while(i<n)                      //after pos
            ans.push_back(intervals[i++]);
        
        return ans;
    }
};
