class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n == 1) return {{1}};
        vector<vector<int>> res(n, vector<int>(n,0));
        int cnt = 1;
        for (int k = 0; k < (n+1)/2; k++) {
            int i = k, j = k;
            if (k == n-k-1) {
                res[k][k] = cnt;
                break;
            }
            while (j < n-k-1) {
                res[i][j] = cnt;
                cnt++;
                j++;
            }
            while (i < n-k-1) {
                res[i][j] = cnt;
                cnt++;
                i++;
            }
            while (j > k) {
                res[i][j] = cnt;
                cnt++;
                j--;
            }
            while (i > k) {
                res[i][j] = cnt;
                cnt++;
                i--;
            }
        }
        return res;
    }
};