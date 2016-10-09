class Solution {
public:
    int addDigits(int num) {
        if (num ==0) return 0;
        return (num-1)%9+1;
    }
};
//////////////////////
// Basic version
class Solution {
    int getSum(int num) {
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
public:
    int addDigits(int num) {
        if (num / 10 == 0)
            return num;
        return addDigits(getSum(num));
    }
};