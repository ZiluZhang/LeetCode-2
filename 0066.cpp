class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        if (len == 0) return {1};
        digits[len-1] ++;
        int i = len-1;
        while (i > 0) {
            if (digits[i] < 10) return digits;
            digits[i] = digits[i] % 10;
            digits[i-1]++;
            i--;
        }
        if (digits[0] >= 10) {
            digits[0] %= 10;
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};