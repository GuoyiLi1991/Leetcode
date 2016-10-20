//Sol1. using carry
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if (n == 0) return vector<int>();
        
        int carry = 1;
        for (int i = n - 1; i >= 0; i--) {
            digits[i] += carry;
            carry = digits[i] / 10;
            if (carry == 0)
                break;
            
            digits[i] %= 10;
        }
        
        if (carry)
            digits.insert(digits.begin(), 1);
            
        return digits;
    }
};

//Sol2. Find the last not nine position first
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if (n == 0) return vector<int>();
       
       vector<int> res; 
       int ptr = n - 1;
       while (ptr >= 0 && digits[ptr] == 9)
            ptr--;
       if (ptr < 0) {
           res.push_back(1);
           res.resize(n + 1, 0);
           return res;
       }
       else {
           digits[ptr++]++;
           while (ptr < n)
                digits[ptr++] = 0;
       }
       
       return digits;
    }
};