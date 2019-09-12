class Solution {
public:
    bool validPalindrome(string s) {
        for (int i = 0; i < s.length()/2; i++) {
            if (s[i] != s[s.length()-1-i]) {
                string s1 = s.substr(0, i) + s.substr(i+1);
                string s2 = s.substr(0, s.length()-1-i) + s.substr(s.length()-i);
                return check(s1) || check(s2);
            }
        }
        return true;
    }
    
    bool check(string s) {
        for (int i = 0; i < s.length()/2; i++) {
            if (s[i] != s[s.length()-1-i]) return false;
        }
        return true;
    }
};