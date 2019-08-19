class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;
        int len = grid.size();
        if (len == 0) return res;
        int wid = grid[0].size();
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < wid; j++) {
                if (grid[i][j]) {
                    res += 4;
                    for (int k = 0; k < 4; k++) {
                        int nx = i + dir[k][0];
                        int ny = j + dir[k][1];
                        if (0 <= nx && nx < len && 0 <= ny && ny < wid && grid[nx][ny]) {
                            res -= 1;
                        }
                    }
                }
            }
        }
        return res;
    }
};