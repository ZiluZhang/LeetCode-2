class Solution {
public:
    string crackSafe(int n, int k) {
        string res = string(n, '0');
        unordered_set<string> used{{res}};
        for (int i = 1; i < pow(k, n); i++) {
            string prev = res.substr(res.length()-n+1);
            for (int j = k-1; j >= 0; j--) {
                string tmp = prev + to_string(j);
                if (!used.count(tmp)) {
                    res += to_string(j);
                    used.insert(tmp);
                    break;
                }
            }
        }
        return res;
    }
};