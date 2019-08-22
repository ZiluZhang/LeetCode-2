class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        string s = to_string(x);
        int len = s.length();
        for (int i = 0; i < len/2; i++) {
            if (s[i] != s[len-i-1])
                return false;
        }
        return true;
    }
};

// 翻转一半的数字
// 如果是偶数位，应该相等
// 如果是奇数位，应该差10倍
// 12321 => 123 12
// 123321 => 123 123
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        
        int reverted = 0;
        while (x > reverted) {
            reverted = reverted * 10 + x % 10;
            x /= 10;
        }
        
        return x == reverted || x == reverted / 10;
    }
};