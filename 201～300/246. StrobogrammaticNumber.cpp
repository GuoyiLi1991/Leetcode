/*
246. Strobogrammatic Number  
  QuestionEditorial Solution  My Submissions
  Total Accepted: 12724
  Total Submissions: 34009
  Difficulty: Easy
A strobogrammatic number is a number that looks 
the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is 
strobogrammatic. The number is represented as a string.

For example, the numbers "69", "88", and "818" are 
all strobogrammatic.
*/


class Solution {
public:
    bool isStrobogrammatic(string num) {
        int n = num.size();
        int l = 0, r = n - 1;
        while (l <= r){
            char lc = num[l], rc = num[r];
            if (lc == '1' && rc == '1' || 
                lc == '8' && rc == '8' || 
                lc == '6' && rc == '9' ||
                lc == '9' && rc == '6' ||
                lc == '0' && rc == '0') {
                    l++; r--;
                }
            else return false;
        }
        return true;
    }
};

//hash table
class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> ht = {{'1','1'},{'6','9'},{'9','6'},{'8','8'},{'0','0'}};
        int n = num.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            if (ht[num[l]] == num[r]) {
                l++;
                r--;
            }
            else return false;
        }
        return true;
    }
};