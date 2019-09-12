class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        string res = "";
        int s = 0, c = 0;
        for (int k = 1; k <= min(len1, len2); k++) {
            s = c + (num1[len1-k]-'0') + (num2[len2-k]-'0');
            c = s / 10;
            res = to_string(s % 10) + res;
        }
        for (int k = len1+1; k <= len2; k++) {
            s = c + (num2[len2-k]-'0');
            c = s / 10;
            res = to_string(s % 10) + res;
        }
        for (int k = len2+1; k <= len1; k++) {
            s = c + (num1[len1-k]-'0');
            c = s / 10;
            res = to_string(s % 10) + res;
        }
        if (c) {
            res = to_string(c) + res;
        }
        return res;
    }
};