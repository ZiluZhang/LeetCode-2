class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string src = boardStr(board);
        unordered_set<string> visited{{src}};
        queue<string> q{{src}};
        string res = "123450";
        if (src == res) return 0;
        vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        int cnt = 0;
        while (!q.empty()) {
            cnt++;
            for (int k = q.size(); k > 0; k--) {
                auto cur = q.front(); q.pop();
                int loc = getZero(cur);
                int x = loc / 3;
                int y = loc % 3;
                for (int i = 0; i < 4; i++) {
                    int nx = x + dir[i][0];
                    int ny = y + dir[i][1];
                    if (nx < 0 || nx > 1 || ny < 0 || ny > 2) continue;
                    swap(cur[nx*3+ny], cur[x*3+y]);
                    if (visited.count(cur) == 0) {
                        if (checkStr(cur, res)) return cnt;
                        q.push(cur);
                        visited.insert(cur);
                    }
                    swap(cur[nx*3+ny], cur[x*3+y]);
                }
            }
        }
        return -1;
    }
    
    string boardStr(vector<vector<int>>& b) {
        string s = "";
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                s += b[i][j]+'0';
            }
        }
        return s;
    }
    
    
    int getZero(string s) {
        return s.find("0");
    }
    
    bool checkStr(string b1, string b2) {
        for (int i = 0; i < 6; i++) {
            if (b1[i] != b2[i]) return false;
        }
        return true;
    }
};