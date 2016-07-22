class Solution {
    int sq[10] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};
    int ssd(int n) {
        int sum = 0;
        while (n) {
            int d = n % 10;
            sum += sq[d];
            n /= 10;
        }
        return sum;
    }
public:
    bool isHappy(int n, unordered_set<int> &myset) {
        if (n == 1)
            return true;
        if (myset.find(n) == myset.end()) {
            myset.insert(n);
            return isHappy(ssd(n), myset);
        }
        else
            return false;
    }
    bool isHappy(int n) {
        unordered_set<int> myset;
        return isHappy(n, myset);
    }
};