// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (isBadVersion(1)) return 1;
        int l, r, mid;
        l = 1; r = n;
        do 
        {
            mid = (l/2+r/2);
            if (!isBadVersion(mid)) l = mid+1; //bad is later
            else r = mid; //bad is earlier
        }while(!isBadVersion(l));
        return l;
        
    }
};
