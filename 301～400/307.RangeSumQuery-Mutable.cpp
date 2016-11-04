class NumArray {
    vector<int> sum;
    vector<int> nums;
    vector<pair<int, int>> updates; //<idx, delta>
    
    void getPS() {
        int n = nums.size();
        if (n == 0) return;
        sum.resize(n, 0);
        
        sum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            sum[i] = sum[i - 1] + nums[i];
        }
    }
    
public:
    NumArray(vector<int> &num):nums(num) {
        getPS();
    }

    void update(int i, int val) {
        updates.push_back({i, val - nums[i]});
        nums[i] = val;
        
        if (updates.size() > 333) {
            getPS();
            updates.clear();
        }
    }

    int sumRange(int i, int j) {
        int res = sum[j] - sum[i - 1];
        
        //adjust to updates
        for (auto &change : updates) {
            if (change.first >= i && change.first <= j) {
                res += change.second;
            }
        }
        return res;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);