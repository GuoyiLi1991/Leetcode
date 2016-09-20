// Forward declaration of the knows API.
bool knows(int a, int b);

////// Sol1: Brute Force: O(n^2), 229ms
class Solution {
public:
    int findCelebrity(int n) {
        for (int i = 0; i < n; i++) {
            bool other_know = true;
            bool know_other = false;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    // check if others all know
                    if (!knows(j, i)) {
                        other_know = false;
                        break;
                    }
                    // check if know other
                    if (knows(i, j)) {
                        know_other = true;
                        break;
                    }
                }
            }
            if (other_know && !know_other)
                return i;
        }
        return -1;
    }
};
/* consisely:
    int findCelebrity(int n) {
        for (int i = 0; i < n; i++) {
            int j;
            for (j = 0; j < n; j++) {
                if (i != j && ( !knows(j, i) || knows(i, j))) 
                        break;
            }
            if (j == n)  //all satisfies
                return i;
        }
        return -1;
    }
*/

/////////
// Sol 2: Two passes: O(2n), 176ms
// 最多1个人完全不认识其他人
// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        //first find a candidate that knows nobody else after him
        int candidate = 0;
        for (int i = 1; i < n; i++) { 
            if (knows(candidate, i))
                candidate = i;
        }
        
        // double check:
        // 1. he does not know others before him
        // 2. everybody else knows him
        // Either 1 or 2 not true, return -1
        for (int i = 0; i < n; i++) {
            if (!knows(i, candidate) || (i < candidate && knows(candidate, i)))
                return -1;
        }
        return candidate;
    }
};
/////////