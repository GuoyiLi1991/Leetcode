// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int res = 0;
        while (n) {
            int tmp = min(n, read4(buf));
            buf += tmp;
            res += tmp;
            if (tmp < 4) break;
            n -= 4;
        }
        return res;
    }
};
