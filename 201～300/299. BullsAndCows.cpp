class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0; //A
        int cow = 0; //B
        int ht[10];
        fill_n(ht, 10, 0);
        
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bull++;
            }
            else
                ht[secret[i] - '0']++;
        }
        for (int i = 0; i < guess.size(); i++) {
            if (secret[i] != guess[i] && ht[guess[i] - '0'] > 0) {
                cow++;
                ht[guess[i] - '0']--;
            }
        }
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};