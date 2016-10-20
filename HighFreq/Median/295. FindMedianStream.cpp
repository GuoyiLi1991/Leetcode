class MedianFinder {
    int size;
    priority_queue<int> maxHeap; //storing below median
    priority_queue<int, vector<int>, std::greater<int>> minHeap; //storing above median
public:
    MedianFinder():size(0){};
    // Adds a number into the data structure.
    void addNum(int num) {
        int curMedian = findMedian();
        maxHeap.push(num);
        size++;
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if (size % 2 == 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        
    }

    // Returns the median of current data stream
    double findMedian() {
        //return 0;
        if (size == 0) return 0;
        if (size % 2 == 1)
            return maxHeap.top();
        else
            return double(maxHeap.top() + minHeap.top())/2;
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();