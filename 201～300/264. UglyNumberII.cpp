// Sol1: keep 3 lists
// O(4n), 66ms
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly;
        ugly.push_back(1);
        queue<int> l1; //times 2
        queue<int> l2; //times 3
        queue<int> l3; //times 5
        for (int i = 1; i < n; i++) {
            l1.push(ugly[i - 1] * 2);
            l2.push(ugly[i - 1] * 3);
            l3.push(ugly[i - 1] * 5);
            
            int next = min(min(l1.front(), l2.front()), l3.front());
            ugly.push_back(next);
            
            // Notice: could pop more than one element, eg. 6 appears in both l1 and l2
            if (l1.front() == next) {
                l1.pop();
            }
            if (l2.front() == next){
                l2.pop();
            }
            if (l3.front() == next)
                l3.pop();
        }
        
        // for (int i = 0; i < n; i++) 
        //     cout << ugly[i] <<endl;
        return ugly[n - 1];
    }
};

// Sol2: keep 3 pointers
// 16ms
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly;
        ugly.push_back(1); //ugly[0]
        
        int p2 = 0, p3 = 0, p5 = 0; //pointers of times2, times3, times5
        for (int i = 1; i < n; i++) {
            int next = min(min(ugly[p2] * 2, ugly[p3] * 3), ugly[p5] * 5);
            ugly.push_back(next);
            
            // Notice: could pop more than one element, eg. 6 appears in both l1 and l2
            if (ugly[p2] * 2 == next) p2++;
            if (ugly[p3] * 3 == next) p3++;
            if (ugly[p5] * 5 == next) p5++;
        }
        
        // for (int i = 0; i < n; i++) 
        //     cout << ugly[i] <<endl;
        return ugly[n - 1];
    }
};