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
    int sol1(vector<Interval>& intervals) { //map:600ms O(n)
        int n = intervals.size();
        if (n<2) return n;
        
        map<int, int> mp;
        for (auto interval:intervals)
        {
            mp[interval.start] += 1;
            mp[interval.end] -= 1;
        }
        
        int minCount = 0, tmp = 0;
        for (auto item:mp)
        {
            tmp += item.second;
            if (minCount < tmp)
                minCount = tmp;
        }
        return minCount;
    }
    
    struct{
        bool operator()(Interval&a, Interval&b)
        {
            return a.start < b.start;
        }
    }Comp;
    
    int sol2(vector<Interval>& intervals) { //using priority_queue/ min_heap  584msO(nlogn)
        int n = intervals.size();
        if (n<2) return n;
        
        int minCount = 0;
        sort(intervals.begin(), intervals.end(), Comp); //sort by starting time
        priority_queue<int, vector<int>, std::greater<int>> end_pq;
        
        int cnt = 0;
        for (Interval interval: intervals)
        {
            end_pq.push(interval.end);
            cnt++;
            while (interval.start >= end_pq.top())
            {
                end_pq.pop();
                cnt --;
            }
            if (cnt > minCount)
                minCount = cnt;
                
        }

        return minCount;

    }
    
    int sol3(vector<Interval>& intervals) //two vectors O(2nlog(n))
    {
        vector<int> starts, ends;
        for (auto interval: intervals)
        {
            starts.push_back(interval.start);
            ends.push_back(interval.end);
        }
        
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        
        int minRoom = 0, available = 0;
        int n = intervals.size();
        int j = 0;
        for (int i = 0; i<n; i++)
        {
            while(ends[j] <= starts[i])
            {
                available++;
                j++;
            }
            if (available <=0)
                ++minRoom;
            else available--;
            
        }
        return minRoom;
    }
    
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        return sol3(intervals);

    }
};