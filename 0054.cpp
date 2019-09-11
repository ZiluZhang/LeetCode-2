class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return {};
        int n = matrix[0].size();
        vector<int> res;
        for (int k = 0; k < (min(m, n) + 1) / 2; k++) {
            int i = k, j = k;
            while (j <= n-k-1) {
                res.push_back(matrix[i][j]);
                j++;
            }
            j = n-k-1;
            i = k+1;
            while (i <= m-k-1) {
                res.push_back(matrix[i][j]);
                i++;
            }
            i = m-k-1;
            if (i == k) continue;
            j = n-k-2;
            while (j >= k) {
                res.push_back(matrix[i][j]);
                j--;
            }
            j = k;
            if (j == n-k-1) continue;
            i = m-k-2;
            while (i > k) {
                res.push_back(matrix[i][j]);
                i--;
            }
        }
        return res;
    }
};