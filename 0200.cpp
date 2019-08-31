// DFS
// 注意传参数的时候用指针，否则需要copy整个object
class Solution {
public:
    vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && (!visited[i][j])) {
                    res++;
                    visitIsland(i, j, grid, visited);
                }
            }
        }
        return res;
    }
    
    void visitIsland(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        int m = grid.size();
        int n = grid[0].size();
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '0' || visited[x][y]) return;
        visited[x][y] = true;
        visitIsland(x-1, y, grid, visited);
        visitIsland(x+1, y, grid, visited);
        visitIsland(x, y-1, grid, visited);
        visitIsland(x, y+1, grid, visited);        
    }
};