class Solution {
public:
    int maxRepOpt1(string text) {
        string mark = "";
        vector<int> cnt;
        int len = text.length();
        int i = 0;
        int res = 0;
        while (i < len) {
            mark += text[i];
            int tmp = 1;
            while (i+1 < len && text[i+1] == text[i]) {
                i++;
                tmp++;
            }
            res = max(res, tmp);
            cnt.push_back(tmp);
            i++;
        }
        cout << mark << endl;
        for (int i = 0; i < cnt.size(); i++) {
            cout << cnt[i];
        }
        if (cnt.size() == 1) return cnt[0];
        if (cnt.size() == 2) return max(cnt[0], cnt[1]);
        int len2 = cnt.size();
        for (int i = 0; i < len2; i++) {
            if (i+2 < len2 && mark[i] == mark[i+2] && cnt[i+1] == 1) {
                if (mark.find_first_of(mark[i]) != i || mark.find_last_of(mark[i+2]) != i+2)
                    res = max(res, cnt[i] + cnt[i+2] + 1);
                else
                    res = max(res, cnt[i] + cnt[i+2]);
            }
            if (mark.find_first_of(mark[i]) != i || mark.find_last_of(mark[i]) != i) {
                res = max(res, cnt[i]+1);
            }
        }
        
        return res;
    }
};