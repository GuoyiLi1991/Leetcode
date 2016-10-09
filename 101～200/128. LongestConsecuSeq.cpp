// Sol1. unordered_map
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1) return n;
        
        //general case
        int longestLen = 0;
        unordered_map<int, bool> ht; //<int, not_visited>
        
        //make set
        for (int val : nums)
            ht[val] = true;
            
        for (auto& item : ht) {
            int val = item.first;
            int left = val, right = val + 1;
            while (ht.count(left) && ht[left])
                ht[left--] = false;
            while (ht.count(right) && ht[right])
                ht[right++] = false;
                
            longestLen = max((right-1) - (left+1) + 1, longestLen);
        }
        return longestLen;
    }
};

// Sol2. unordered_set
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1) return n;
        
        //general case
        int longestLen = 1;
        unordered_set<int> myset; 
        
        //make set
        for (int val : nums)
            myset.insert(val);
            
        for (int val : myset) {
            int left = val - 1, right = val + 1;
            while (myset.count(left))
                myset.erase(left--);
                
            while (myset.count(right))
                myset.erase(right++);
                
            longestLen = max(right - left - 1, longestLen);
        }
        return longestLen;
    }
};

// Sol3. Union find
class Solution {
    vector<int> id;
    vector<int> size;
    
    void make_set(vector<int>& id, vector<int>& size, n) {
        int n = nums.size();
        id = vector<int>(n, 0);
        size = vector<int>(n, 1);
        for (int i = 1; i < n; i++) {
            id = i;
        }
    }
    
    int find(int x) {
        if (x == id[x])
            return x;
        return find(id[x]);
    }
    
    void unions(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);
        if (xRoot == yRoot) return; //no combination needed
        int xSize = size[xRoot], ySize = size[yRoot]; //make a biggest tree
        if (xSize < ySize) {
            id[xRoot] = yRoot;
            size[yRoot] += size[xRoot];
        }
        else {
            id[yRoot] = xRoot;
            size[xRoot] += size[yRoot];
        }
        
    }
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;
        
        make_set(id, size, n);
        unordered_map<int, int> val_id;
        for (int i = 0; i < n; i++) {
            val_id[nums[i]] = i;
        }
        
        //union set
        for (int val : nums) {
            if (val_id.count(val - 1))
                unions(val_id[val], val_id[val - 1]);
            if (val_id.count(val + 1))
                unions(val_id[val], val_id[val + 1]);    
        }
        
        return *max_element(size.begin(), size.end());
        
    }
};