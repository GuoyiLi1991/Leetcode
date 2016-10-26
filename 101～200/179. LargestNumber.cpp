struct Cmp{
    bool operator()(string &s1, string &s2) {
        string t1 = s1 + s2;
        string t2 = s2 + s1;
        return t1.compare(t2) > 0;
    }
};
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strings;
        for (int i : nums) {
            strings.push_back(to_string(i));
        }
        sort(strings.begin(), strings.end(), Cmp());
        
        //corner case: nothing but 0's
        if (strings[0] == "0")
            return "0";

        //greater than 0
        string res;
        for (string s : strings) {
            res += s;
        }
        return res;
    }
};