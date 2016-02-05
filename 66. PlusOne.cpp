class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1, d = 0;
        int n = digits.size();
        vector<int> result(n,0);
        
        for (int i = n-1; i>=0; i--)
        {
            d = carry + digits[i];
            carry = d/10;
            d = d%10;
            result[i] = d;
        }
        
        // the most significant digit
        if (carry == 1)
        {
            result.insert(result.begin(), 1);
        }
        
        return result;
    }
};