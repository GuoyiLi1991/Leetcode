class Solution {
public:
    int getSum(int a, int b) {
        int base = a ^ b;
        int carry  = ((a & b) << 1);
        
        //merge base and carry
        //base case
        if ((base & carry) == 0) 
            return (base | carry);
        return getSum(base, carry);
        
    }
};