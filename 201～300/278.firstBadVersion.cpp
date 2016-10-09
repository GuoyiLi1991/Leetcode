//////
// Rewrite
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (!isBadVersion(mid))
                l = mid + 1;
            else if (!isBadVersion(mid - 1))
                return mid;
            else
                r = mid - 1;
        }
        return l;
    }
};