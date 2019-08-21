class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int len = A.size();
        vector<vector<int>> res(len);
        for (int i = 0; i < len; i++) {
            int wid = A[i].size();
            for (int j = wid-1; j >= 0; j--) {
                res[i].push_back(!A[i][j]);
            }
        }
        return res;
    }
};