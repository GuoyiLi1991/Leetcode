// This problem is easily to get TLE
// Improvement 1: isPrime() check from 2 to sqrt(n),
//                reducing O(n) to O(n^.5). 
//                Total time complexity is O(n^1.5)
// Improvement 2: Extra space for a hash table, eliminating
//                all multiples of i on the go.
//                "Sieve of Eratosthenes". O(n log log n)
class Solution {
    // bool isPrime(int n) {
    //     if (n < 2) return false;
    //     if (n == 2 || n == 3 || n == 5 || n == 7)
    //         return true;
    //     for (int i = 2; i * i <= n; i++) {
    //         if (n % i == 0)
    //             return false;
    //     }
    //     return true;
    // }
public:
    int countPrimes(int n) {
        int cnt = 0;
        vector<bool> ht(n, true);
        ht[0] = ht[1] = false;
        for(int i = 0; i < n; i++) {
            if (ht[i] == false)
                continue;
            
            int k = ht[i]? 2:1;  /////////TLE if use isPrime(i) instead of ht[i]
            while ((k * i) <= n) {
                ht[k * i] = false;
                k++;
            }
            cnt++;
        }

        return cnt;
    }
};