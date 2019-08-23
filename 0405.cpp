class Solution {
public:
    string toHex(int num) {
        unsigned int n = num;
        if (n == 0) return "0";
        string res = "";
        while (n) {
            int k = n % 16;
            if (k < 10) res = to_string(k) + res;
            else {
                char cur = 'a'+k-10;
                res = cur + res;
            }
            n /= 16;
        }
        return res;
    }
};