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
    //custom STL sort() - using Comp struct
    bool sol1(vector<Interval>& intervals)  //580ms
    {
        int n = intervals.size();
        if ( n< 2) 
            return true;
        
        sort(intervals.begin(), intervals.end(), Comp);
        
        for (int i = 0; i<n-1; i++)
        {
            if (intervals[i].end >intervals[i+1].start)
                return false;
        }
        
        return true;
    }
    
    //custom STL sort() - using lamda function
    bool sol2(vector<Interval>& intervals) //592ms
    {
        int n = intervals.size();
        if ( n< 2) 
            return true;
        
        sort(intervals.begin(), intervals.end(), 
            [](const Interval &a, const Interval &b)
                {
                    return a.start <b.start;
                }
                );
       
        
        for (int i = 0; i<n-1; i++)
        {
            if (intervals[i].end >intervals[i+1].start)
                return false;
        }
        
        return true;
    }
    
    // Hashmap
    bool sol3(vector<Interval>& intervals)      //716ms
    {
        map<int, int> ht; // store <start,end> pairs in hash table
        int n = intervals.size();
        if (n <2) return true;
        
        for (int i = 0; i<n; i++)
            ht[intervals[i].start] = intervals[i].end;
        
        if (ht.size() < n)  //exist starting time conflict
            return false;
        
        int tmp = 0;
        for (map<int, int>::iterator it = ht.begin(); it!=ht.end(); ++it)
        {
            if (tmp >it->first) return false;
            tmp = it->second;
        }
        return true;
    }
    
    struct{
        bool operator()(Interval a, Interval b)
        {
            return a.start<b.start;
        }
    }Comp;    
    
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        return sol3(intervals);
    }
};


//////// Sweaping lines
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        vector<pair<int, int>> times;
        for (auto &item : intervals) {
            times.push_back({item.start, 1});
            times.push_back({item.end, -1});
        }
        sort(times.begin(), times.end());
        
        int occupy = 0;
        for (auto &item : times) {
            occupy += item.second;
            if (occupy > 1) return false;
        }
        
        return true;
    }
};