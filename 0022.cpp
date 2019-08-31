class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack("", res, 0, 0, n);
        return res;
    }
    
    void backtrack(string cur, vector<string>& res, int left, int right, int n) {
        if (cur.length() == n * 2) {
            res.push_back(cur);
            return;
        }
        if (left < n)
            backtrack(cur + "(", res, left+1, right, n);
        if (right < left)
            backtrack(cur + ")", res, left, right+1, n);
        return;
    }
};