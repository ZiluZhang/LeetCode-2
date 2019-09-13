class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        int cnt = 1;
        int k = 1;
        vector<vector<int>> res = {{r0, c0}};
        vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        int idx = 0;
        int x = r0, y = c0;
        while (cnt < R * C) {
            for (int t = 0; t < 2 && cnt < R*C; t++) {
                for (int i = 0; i < k && cnt < R*C; i++) {
                    int nx = x + dir[idx][0];
                    int ny = y + dir[idx][1];
                    if (0 <= nx && nx < R && 0 <= ny && ny < C) {
                        // cout << t << ' ' << i << ' ' << idx << endl;
                        res.push_back({nx, ny});
                        cnt++;
                    }
                    x = nx;
                    y = ny;
                }
                idx = (idx+1)%4; // change direction
            }
            k++;
        }
        return res;
    }
};