// Discussion of 3 solutions: 
// http://www.geeksforgeeks.org/majority-element/

//Here, Moore's Voting Algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) { //16ms
        int majorElement = nums[0];
        int count = 1;
        for (int i = 1; i<nums.size(); i++)
        {
            if (nums[i] == majorElement ) count++;
            else if(count >0) count--;
            else {
                majorElement = nums[i];
                count =1;
            }
        }
        return majorElement;
    }
};

