class Solution {
public:
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    int m, n;
    vector<vector<int>> mymatrix;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        mymatrix = matrix;
        m = matrix.size();
        if (m == 0) return 0;
        n = matrix[0].size();
        int res = 1;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, getPath(i, j, visited));
            }
        }
        return res;
    }
    
    int getPath(int i, int j, vector<vector<int>>& visited) {
        if (visited[i][j] > 0) return visited[i][j];
        for (int k = 0; k < 4; k++) {
            int x = i + dir[k][0];
            int y = j + dir[k][1];
            if (0 <= x && x < m && 0 <= y && y < n && mymatrix[x][y] > mymatrix[i][j]) {
                visited[i][j] = max(visited[i][j], getPath(x, y, visited));
            }
        }
        visited[i][j]++;
        return visited[i][j];
    }
};