class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> n;
        for (auto num : nums) n.push_back((double)num);
        return helper(n);
    }
    
    bool helper(vector<double>& n) {
        if (n.size() == 0) return false;
        if (n.size() == 1) return abs(n[0] - 24.0) < 1e-6;
        for (int i = 0; i < n.size(); i++) {
            for (int j = 0; j < i; j++) {
                vector<double> n2;
                for (int k = 0; k < n.size(); k++) {
                    if (k != i && k != j) n2.push_back(n[k]);
                }
                n2.push_back(n[i]+n[j]);
                if (helper(n2)) return true;
                n2.pop_back();
                n2.push_back(n[i]*n[j]);
                if (helper(n2)) return true;
                n2.pop_back();
                n2.push_back(n[i]-n[j]);
                if (helper(n2)) return true;
                n2.pop_back();
                n2.push_back(n[j]-n[i]);
                if (helper(n2)) return true;
                n2.pop_back();
                if (n[j] != 0) {
                    n2.push_back(n[i]/n[j]);
                    if (helper(n2)) return true;
                    n2.pop_back();
                }
                if (n[i] != 0) {
                    n2.push_back(n[j]/n[i]);
                    if (helper(n2)) return true;
                    n2.pop_back();
                }
            }
        }
        return false;
    }
};