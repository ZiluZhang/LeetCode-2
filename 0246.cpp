class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> m = {
            {'6', '9'},
            {'9', '6'},
            {'8', '8'},
            {'0', '0'},
            {'1', '1'}
        };
        int len = num.length();
        // if (len <= 1) return m.count(num[0]) && m[num[0]] == num[0];
        for (int i = 0; i < (len+1) / 2; i++) {
            // cout << i << ' ' << len-i-1 << endl;
            // cout << num[i] << ' ' << num[len-i-1] << endl;
            if (i == len-i-1) return m.count(num[i]) && m[num[i]] == num[i];
            if (!m.count(num[i]) || m[num[i]] != num[len-i-1]) return false;
        }
        return true;
    }
};