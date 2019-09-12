class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        int cur = 0;
        int cnt = 0;
        vector<string> res;
        int i = 0;
        int j = 0;
        while (i < n) {
            if (cur + words[i].length() + cnt > maxWidth) {
                // form current into one line
                int space = maxWidth - cur;
                string tmp = words[j];
                if (cnt == 1) {
                    tmp += string(space, ' ');
                } else {
                    int a = space / (cnt - 1);
                    int b = space % (cnt - 1);
                    for (int k = j+1; k < i; k++) {
                        if (k-j <= b) {
                            tmp += string(a+1, ' ');
                        } else {
                            tmp += string(a, ' ');
                        }
                        tmp += words[k];
                    }
                }
                res.push_back(tmp);
                // new start
                cur = 0;
                cnt = 0;
                j = i;
            }
            cur += words[i].length();
            cnt++;
            i++;
        }
        // form the last line
        string lastLine = words[j];
        for (int k = j+1; k < n; k++) {
            lastLine += ' ' + words[k];
        }
        lastLine += string(maxWidth - lastLine.length(), ' ');
        res.push_back(lastLine);
        return res;
    }
};