class MedianFinder {
    priority_queue<int> maxHeap; //storing below median
    priority_queue<int, vector<int>, std::greater<int>> minHeap; //storing above median
public:
    MedianFinder(){};
    // Adds a number into the data structure.
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if (maxHeap.size() != minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (maxHeap.size() != minHeap.size())
            return maxHeap.top();
        else
            return double(maxHeap.top() + minHeap.top())/2;
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();


////////
// Sol2. 
class MedianFinder {
    vector<int> v;
public:
    // Adds a number into the data structure.
    void addNum(int num) {
        int l = 0, r = v.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (num > v[mid])
                l = mid + 1;
            else
                r = mid - 1;
        }//now l is the place to insert
        v.insert(v.begin() + l, num);
    }

    // Returns the median of current data stream
    double findMedian() {
        int n = v.size();
        
        if(n % 2) return v[n / 2];
        else return 0.5 * (v[n/2] + v[n/2 - 1]);
    }
};
