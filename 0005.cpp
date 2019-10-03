class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 0) return "";
        int max_len = 0;
        int l = 0, r = 0;
        for (int i = 0; i < s.length(); i++) {
            int len1 = getPalindrome(s, i, i);
            int len2 = getPalindrome(s, i, i+1);
            int len = max(len1, len2);
            if (len > max_len) {
                l = i - (len-1)/2;
                r = i + len/2;
                max_len = len;
            }
        }
        return s.substr(l, r-l+1);
    }
    
    int getPalindrome(string s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
};