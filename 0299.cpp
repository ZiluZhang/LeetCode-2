class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.length();
        int bulls = 0;
        int cows = 0;
        string res = "";
        unordered_map<char, int> m;
        for (int i = 0; i < n; i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                if (m[secret[i]]++ < 0) {
                    cows++;
                }
                if (m[guess[i]]-- > 0) {
                    cows++;
                }
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};