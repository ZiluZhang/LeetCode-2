class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n = sentence.size();
        vector<int> len;
        int allLen = 0;
        for (string s: sentence){
            len.push_back(s.length());
            allLen += s.length() + 1;
        }
        int cnt = 0;
        int idx = 0;
        for (int i = 0; i < rows; i++) {
            int j = cols;
            while (j > 0) {
                if (j >= len[idx]) {
                    j -= len[idx];
                    if (j > 0) j--;
                    idx++;
                    if (idx == n) {
                        cnt += (1 + j / allLen);
                        j = j % allLen;
                        idx = 0;
                    }
                } else {
                    break;
                }
            }
        }
        return cnt;
    }
};