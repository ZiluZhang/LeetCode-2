class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return helper(n, n);
    }
    
    vector<string> helper(int m, int n) {
        if (m == 0) return {""};
        if (m == 1) return {"1", "8", "0"};
        vector<string> prev = helper(m-2, n);
        vector<string> res;
        for (auto s : prev) {
            if (m != n) res.push_back("0" + s + "0");
            res.push_back("1" + s + "1");
            res.push_back("6" + s + "9");
            res.push_back("8" + s + "8");
            res.push_back("9" + s + "6");
        }
        return res;
    }
};