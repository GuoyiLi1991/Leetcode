class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n ==0  || s[0] == '0') return 0;
        
        vector<int> dp(n+1, 0); //TF table
        dp[n] = 1;
        dp[n-1] = (s[n-1] != '0');
        
        for (int i = n-2; i>=0; i--)
        {
            if (s[i] == '0') dp[i] = 0;
            else if(s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))
                dp[i] = dp[i+1] + dp[i+2];
            else
                dp[i] = dp[i+1];
        }
        
        return dp[0];
        
    }
};

//another way
 int n = s.size();
    if(n == 0 || s[0] == '0') return 0;
    if(n == 1) return 1;
    int res = 0,fn_1 = 1,fn_2 = 1;
    for(int i = 1;i < n;i++){
        int temp = fn_1;
        bool b1 = isValid(s[i]);
        bool b2 = isValid(s[i-1], s[i]);
        if(b1  && b2)  res+=fn_1+fn_2;
        if(!b1 && b2) res+=fn_2;
        if(b1  && !b2) res+=fn_1;
        if(!b1 && !b2)  return 0;
        fn_1 = res;
        fn_2 = temp;
        res = 0;
    }
    return fn_1;
}
bool isValid(char a,char b){
    return a == '1'||(a == '2' && b <='6');
}
bool isValid(char a){
    return a != '0';
}