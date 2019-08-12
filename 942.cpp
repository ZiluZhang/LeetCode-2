class Solution {
public:
    vector<int> diStringMatch(string S) {
        int n = S.length();
        int left = 0;
        int right = n;
        vector<int> res;
        for (char c: S) {
            if (c == 'I') {
                res.push_back(left);
                left++;
            } else {
                res.push_back(right);
                right--;
            }
        }
        res.push_back(left);
        return res;
    }
};