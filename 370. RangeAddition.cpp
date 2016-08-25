////// brute forse: O(K * length), k ops
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length, 0);
        
        int n = updates.size();
        if (n == 0) return res;
        
        
        for (int i = 0; i < n; i++) {
            vector<int> change = updates[i];
            int inc = change[2]; 
            if (inc == 0) continue; //no change
            
            int start = change[0];
            int end = change[1];
            
            int sameops = 1;
            while (i < n - 1 && updates[i] == updates[i + 1]) {
                    i++;
                    sameops++;
            }
            
            for (int j = start; j <= end; j++) {
                res[j] += inc * sameops;
            }
        }

        
        return res;
    }
};

//////// By hint, only update the start and end elements
// O(length + k), k ops
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res, nums(length + 1, 0);
        for (int i = 0; i < updates.size(); ++i) {
            nums[updates[i][0]] += updates[i][2];
            nums[updates[i][1] + 1] -= updates[i][2];
        }
        int sum = 0;
        for (int i = 0; i < length; ++i) {
            sum += nums[i];
            res.push_back(sum);
        }
        return res;
    }
};
