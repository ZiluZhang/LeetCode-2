// check position (0,0)
class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0;
        int y = 0;
        for (char c: moves) {
            switch (c) {
                case 'R': x++; break;
                case 'L': x--; break;
                case 'U': y++; break;
                case 'D': y--; break;
            }
        }
        return x==0 && y==0;
    }
};

// count move
class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char, int> m;
        for(char c: moves) {
            m[c]++;
        }
        return m['L'] == m['R'] && m['U'] == m['D'];
    }
};