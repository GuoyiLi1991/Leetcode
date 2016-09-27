// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (guess(mid) == 0)
                return mid;
            else if (guess(mid) == -1) //lower
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
};

//////
// 运用模版
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            if (guess(mid) == 0)
                r = mid;
            else if (guess(mid) == 1)
                l = mid;
            else
                r = mid;
        }
        if (guess(l) == 0)
            return l;
        else if (guess(r) == 0)
            return r;
        return -1;
    }
};