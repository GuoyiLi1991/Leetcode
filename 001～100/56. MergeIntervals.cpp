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


    //////////// My version ////////////////
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
        int n = intervals.size();
        vector<Interval> res;
        
        if (n < 2) return intervals;
        
        sort(intervals.begin(), intervals.end(), 
                [](Interval i1, Interval i2)
                {
                    return i1.start<i2.start;
                });
                
        int start = intervals[0].start;
        int end = intervals[0].end;
        
    
        for (int i = 1; i < n; i++) {
            Interval cur = intervals[i];
            
            if (cur.start > end) //no merging
            {
                Interval tmp(start, end);
                res.push_back(tmp);
                start = cur.start;
                end = cur.end;
            }
            
            if (cur.end > end) {
                end = cur.end;
            }
        }
        
        Interval tmp(start,end);
        res.push_back(tmp);
        return res;
    }
};
};








// Sweaping line
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        map<int, int> overlapping; //<time, number of intervals at this time>
        
        for (auto &interval : intervals) {
            overlapping[interval.start] += 1;
            overlapping[interval.end] -= 1;
        }
        
        vector<Interval> res;
        Interval newInterval;
        int ongoing = 0;
        for (auto &item: overlapping) {
            if (ongoing == 0) //start point
                newInterval.start = item.first;
            
            ongoing += item.second; //+1 if start, -1 if end
            
            if (ongoing == 0) { //end point
                newInterval.end = item.first;
                res.push_back(newInterval);
            }
        }
        
        return res;
    }
};

