class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        auto tmp = trans(S);
        // for (auto p : tmp) {
        //     cout << p.first << ' ' << p.second << endl;
        // }
        int res = 0;
        for (auto str : words) {
            auto cur = trans(str);
            if (tmp.size() != cur.size()) continue;
            int i = 0, j = 0;
            bool flag = true;
            while (i < tmp.size() && j < cur.size()) {
                if (tmp[i].first != cur[j].first) {
                    flag = false;
                    break;
                }
                if (tmp[i].second < cur[j].second) {
                    flag = false;
                    break;
                }
                if (tmp[i].second > cur[j].second && tmp[i].second < 3) {
                    flag = false;
                    break;
                }
                i++; j++;
            }
            if (flag) res++;
        }
        return res;
    }
    
    vector<pair<char, int>> trans(string& str) {
        vector<pair<char, int>> tmp;
        int n = str.length();
        int i = 0;
        while (i < n) {
            char c = str[i];
            int cnt = 1;
            while (i+1 < n && str[i+1] == c) {
                i++;
                cnt++;
            }
            tmp.push_back({c, cnt});
            i++;
        }
        return tmp;
    }
};