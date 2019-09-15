class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int res = 0;
        for (int i = 0; i <= n*2-1; i++) {
            int left = i/2;
            int right = left + i % 2;
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
                res++;
            }
        }
        return res;
    }
};

// 0 1 2 3, n = 4
// min(2, 4-2-1=1)
