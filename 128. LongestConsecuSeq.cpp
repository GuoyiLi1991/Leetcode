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
    //int longest = 1;
public:
    int find(int x) {
        if (x == id[x])
            return x;
        else
            return find(id[x]);
    }
    
    void unionSet(int x, int y) {
        int xRoot = find(x); //id[x]
        int yRoot = find(y); //id[y]
      
        if (xRoot == yRoot) //no need to union
            return;
        if (size[xRoot] > size[yRoot]) { //add y tree to x
            id[yRoot] = xRoot;
            size[xRoot] += size[yRoot];
        }
        else {
            id[xRoot] = yRoot;
            size[yRoot] += size[xRoot];
        }
       // longest = max(longest, max(size[xRoot], size[yRoot]));
    }
    
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1) return n;
        
        //general case
        size = vector<int>(n, 1);
        for (int i = 0; i < n; i++)
            id.push_back(i);
            
        unordered_map<int, int> record; //<val, id>
        for (int i : id) {
            int val = nums[i];
            if (record.count(val) != 1) {
                record[val] = i;
                if (record.count(val - 1))
                    unionSet(i, record[val - 1]);
                if (record.count(val + 1))
                    unionSet(i, record[val + 1]);
            }
        }
        
        return *max_element(size.begin(), size.end());
        
    }
};
