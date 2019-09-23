class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int len = s.length();
        if (len == 0) return 0;
        unordered_map<char, int> m; // rightmost index of char in the window;
        int max_len = -1;
        int left = 0, right = 0;
        while (right < len) {
            m[s[right]] = right;
            while (m.size() > k) {
                if (m[s[left]] == left) m.erase(s[left]);
                left++;
            }
            max_len = max(max_len, right - left + 1);
            right++;
        }
        return max_len;
    }
};