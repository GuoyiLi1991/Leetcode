class Solution {
public:
    bool isMin(int a, int b, int c)
    {
        return (a<=b && a<=c);
    }
    int nthUglyNumber(int n) {
        queue<int> nums, temp1, temp2, temp3;
        int size =0;
        nums.push(1);
        size++;
        if (n == 1) return 1;
        temp1.push(2);
        temp2.push(3);
        temp3.push(5);
        int min = 0, min1, min2, min3;
        do{
            min1 = temp1.front(); 
            min2 = temp2.front();
            min3 = temp3.front();
            if (isMin(min1, min2, min3)) 
            {
                min = min1;
                temp1.pop();
            }
            else if (isMin(min2, min3, min1)) 
            {
                min = min2;
                temp2.pop();

            }
            else if (isMin(min3, min1, min2)) 
            {
                min = min3;
                temp3.pop();
            }
            else {
                min = -1;
            }
            if (min == nums.back()) continue;
            temp1.push(min*2);
            temp2.push(min*3);
            temp3.push(min*5);
            nums.push(min);
            size = nums.size();
        }while(size<n);

        return min;
        
        
    }
};
