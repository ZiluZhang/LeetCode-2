class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        if (num > 10 || num < 0) return {};
        if (num == 0) return {"0:00"};
        vector<string> res;
        int cur = 0;
        for (int i = 0; i <= 10 - num; i++) {
            cur += 1 << i;
            DFS(i+1, num-1, cur, res);
            cur -= 1 << i;
        }
        return res;
    }
    
    void DFS(int s, int k, int cur, vector<string>& res) {
        if (k == 0) {
            int hour = cur >> 6;
            int minute = cur % (1 << 6);
            if (hour >= 12 || minute >= 60) return;
            res.push_back(getTime(cur));
            return;
        }
        for (int i = s; i <= 10 - k; i++) {
            cur += 1 << i;
            DFS(i+1, k-1, cur, res);
            cur -= 1 << i;
        }
    }
    
    string getTime(int n) {
        int hour = n >> 6;
        int minute = n % (1<<6);
        string res = "";
        res += to_string(hour) + ":";
        if (minute < 10) res += "0";
        res += to_string(minute);
        return res;
    }
};