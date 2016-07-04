class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int result;
        for (int i = 0; i< 32; ++i) {
            if (((n>>i) & 1) > 0)
                result |= 1 << ( 31 - i );
        }
        return result;
    }
};

//follow-up: if the function is called many times, how to optimize
//chunk to 4 bits a group
    int result = 0;
    int rev4[16]= {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    int mask = 0xf;
    for (int i = 0; i< 8; ++i) {
        int cur = n & mask;
        int rev = rev4[cur];
        result |= (rev << (4*(7-i)));
        n = n >> 4;
    }

    return result;