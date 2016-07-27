// Brute force O(n * sizeof(int))

class Solution {
    int countBit(int num) {
        int cnt = 0;
        while (num) {
            if ((num & 1) == 1)
                cnt++;
            num = (num >> 1);
        }
        return cnt;
    }
public:
    vector<int> countBits(int num) {
        vector<int> res;
        for (int i = 0; i <= num; i++) {
            res.push_back(countBit(i));
        }
        return res;
    }
};

////////
// O(n) with just one pass, hash table
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res{0};
        if (num == 0) return res;
        int start = 1;
        
        for (int i = 1; i <= num; i++) {
            if (i == start) {//2, 4, 8
                //update next start
                start *= 2;
                res.push_back(1);
                continue;
            }
            else {
                res.push_back(1 + res[i - start/2]);
            }
        }
        return res;
    }
};

/*  0 0   0
    1 01   1
    
    2 10  1
    3 11  2
    
    4 100 1
    5 101 2
    6 110 2
    7 111 3
    
    8 1000 1
    9 1001 2
    10 1010 2
    11 1011 3
    12 1100 2
    13 1101 3
    14 1110 3
    15 1111 4
*/

//////////////
// Good solution O(n) time O(n) space
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i&(i-1)] + 1;
        return ret;
    }
};
