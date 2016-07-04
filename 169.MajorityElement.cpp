// Discussion of 3 solutions: 
// http://www.geeksforgeeks.org/majority-element/

//Here, Moore's Voting Algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int major;
        for (int num:nums) {
            if (count == 0) {   //new start, update cur major
                major = num;
                count ++;
            }
            else
                if (major == num)  //continue increasing cur freq
                    count++;
                else
                    count--; //decrease cur freq
        }
        return major;
    }
};
