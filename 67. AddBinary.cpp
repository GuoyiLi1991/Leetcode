class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.size(),n2 = b.size();
        int c = 0; //carry
        
        int size_sum = n1>n2?n1:n2;
        
        //make equal length
        while (a.size() < size_sum) a = "0"+a;
        while (b.size() < size_sum) b = "0"+b;
        string sum(size_sum, '0');
        
        for (int i = size_sum; i>=0; i--)
        {
            int d = (a[i]-'0') + (b[i]-'0')+c;  // d can be 0, 1,2,3
            switch(d)
            {
                case 0 : c = 0; d = 0; break;
                case 1 : c = 0; d = 1; break;
                case 2 : c  =1; d = 0; break;
                case 3: c  =1; d = 1; break;
            }
            sum[i] = char('0'+d);
        }
        
        //deal with the most significant digit
        if (c) sum = "1"+sum;
        return sum;
    }
};