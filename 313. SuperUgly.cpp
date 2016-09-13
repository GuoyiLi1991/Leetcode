class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n == 1) return 1;
        int k = primes.size();
        vector<int> p(k, 0); //p[i] is the pointer of primes[i]
        
        vector<int> su(n, INT_MAX); //array of super ugly numbers
        su[0] = 1;
        
        for (int i = 1; i < n; i++) {
            // update su[i]: find the minimum
            for (int j = 0; j < k; j++)
                su[i] = min(su[i], su[p[j]] * primes[j]);
                
            //update k pointers
            for (int j = 0; j < k; j++) {
                if (su[i] == su[p[j]] * primes[j]) 
                    p[j]++;
            }
        }
        
        // for (int i = 0; i < n; i++)
        //     cout << su[i] <<endl;
        return su[n - 1];
        
    }
};