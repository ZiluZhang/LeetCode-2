class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.length();
        int len2 = b.length();
        string res = "";
        int c = 0, s = 0;
        for (int k = 1; k <= min(len1, len2); k++) {
            s = c + (a[len1-k]-'0') + (b[len2-k]-'0');
            c = s / 2;
            res = to_string(s % 2) + res;
        }
        for (int k = len1+1; k <= len2; k++) {
            s = c + (b[len2-k]-'0');
            c = s / 2;
            res = to_string(s % 2) + res;
        }
        for (int k = len2+1; k <= len1; k++) {
            s = c + (a[len1-k]-'0');
            c = s / 2;
            res = to_string(s % 2) + res;
        }
        if (c) {
            res = to_string(c) + res;
        }
        return res;
    }
};