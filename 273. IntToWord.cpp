class Solution {
    map<int, string> dict = {
            {0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"},
            {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}
        };

    map<int, string> pref = {
            {2, "Twen"}, {3, "Thir"}, {4, "For"}, {5, "Fif"}, {6, "Six"}, {7, "Seven"}, {8, "Eigh"}, {9, "Nine"}
        };
        
    string chunk(int num) { //num < 1000
        string res;
        if (num < 10 && num != 0)
            return dict[num];
            
        if (num / 100) res = dict[num/100] + " Hundred ";
        if (num % 100) { //last two digits
            int n = num % 100;
            if (n < 10) 
                return res + dict[n];
            
            // Special cases
            if (n == 10) return res + "Ten";
            if (n == 11) return res + "Eleven";
            if (n == 12) return res + "Twelve";
            if (n == 14) return res + "Fourteen";

            //else
            if (n > 19) {
                res = res + pref[n / 10] + "ty";
                if (n % 10)
                    res = res + " " + dict[n % 10];
            }
            else {//teens
                res = res + pref[n % 10] + "teen";
            }
        }
        else res = res.substr(0, res.size() - 1); // remove the last " "
        return res;
    }
public:
    string numberToWords(int num) {
        if (num < 10) return dict[num];
        if (num < 1000)
            return chunk(num);
        vector<string> level = {"", "", " Thousand", " Million", " Billion", " Trillion"};
        string res;
        
        int i = 1;
        while (num) {
            int tmp = num % 1000;
            if (tmp != 0){
                res = " " + chunk(tmp) + level[i] + res;
            }
                
            i++;
            num /= 1000;
        }
        if (res[0] == ' ')
            res = res.substr(1);
        return res;
    }
};