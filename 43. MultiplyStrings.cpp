class Solution {
    string add(string s1, string s2)  //add two numbers represented by strings
    {
        int sum_size = s1.size() > s2.size()? s1.size(): s2.size();
        string sum(sum_size, '0');
        //make equal size
        while (s1.size() < sum_size)
            s1 = "0" + s1;
        while(s2.size() < sum_size)
            s2 = "0" + s2;
        
        //add by digit from the end
        int c = 0; //carry
        for (int i = sum_size -1; i>=0; --i)
        {
            int d = (s1[i]-'0') + (s2[i]-'0') + c;
            sum[i] = d%10 + '0';
            c = d/10;
        }
        
        //deal with the most significant digit
        if (c ==1)
            sum = "1" + sum;
            
        return sum;
    }
    string multiply(string num1, char c)
    {
        if (c == '0')
            return "0";
        if (c == '1')
            return num1;
            
        string prod;
        int carry = 0; //carry
        for (int i = num1.size()-1; i>=0; --i)
        {
            int d = (num1[i]-'0') * (c-'0') + carry;
            prod = to_string(d%10)+prod;
            carry = d/10;
        }
        if (carry != 0)
            prod = to_string(carry) + prod;
        return prod;
    }
public:

    /******** mine *************/
    string multiply2(string num1, string num2) {  
        if (num1 =="0" || num2 == "0")
            return "0";
        string sum;//(num1.size()+num2.size(), '0');
        
        //multiply from the least significant digit
        string prod;
        for (int i = num1.size()-1; i>=0; --i)
        {
             prod = multiply(num2, num1[i]);
            //add num1.size()-1-i 0's
            for (int j = 0; j<num1.size()-1-i; j++)
                prod += "0";
            sum = add(sum, prod);
        }
        return sum;
    }
    
    
    /************ good solution ***********/
    string multiply(string num1, string num2) {  
    string sum(num1.size() + num2.size(), '0');

    for (int i = num1.size() - 1; 0 <= i; --i) {
        int carry = 0;
        for (int j = num2.size() - 1; 0 <= j; --j) {
            int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
            sum[i + j + 1] = tmp % 10 + '0';
            carry = tmp / 10;
        }
        sum[i] += carry;
    }

    size_t startpos = sum.find_first_not_of("0");
    if (string::npos != startpos) {
        return sum.substr(startpos);
    }
    return "0";
}

};


