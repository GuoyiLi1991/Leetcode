class Solution {
    const int base = 1337;
    int powmod(int a, int k) { //a^k mod 1337, when 0 <= k <= 10
        int res = 1;
        a = a % base;
        
        for (int i = 0; i < k; i++) {
            res = (res * a) % base;
        }
        
        return res;
    }
public:
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        if (b.size() == 1) //power within[0, 9]
            return powmod(a, b[0]);
        
        int last_digit = b.back();
        b.pop_back();
        
        return powmod(superPow(a, b), 10) * powmod(a, last_digit) % base;
    }
};