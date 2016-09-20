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
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n == 0) return 0;
        
        vector<int> begins, ends;
        for (auto i: intervals) {
            begins.push_back(i.start);
            ends.push_back(i.end);
        }
        sort(begins.begin(), begins.end());
        sort(ends.begin(), ends.end());
        
        int available = 0, minRoom = 0;
        for (int i = 0, j = 0; i < n; i++) {
            while (ends[j] <= begins[i]) {
                available++;
                j++;
            }
            
            //now ends[j] > begins[i]
            if (available > 0)
                available--;
            else
                minRoom++;
        }
        
        return minRoom;
        
    }
};