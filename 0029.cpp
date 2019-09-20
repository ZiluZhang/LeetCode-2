class Solution {
public:
    int divide(int dividend, int divisor) {
        // cout << INT_MAX << ' ' << INT_MIN << endl;
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long long m = abs((long long)dividend), n = abs((long long)divisor), res = 0;
        if (n == 1) return sign == 1 ? m : -m;
        while (m >= n) {
            long long t = n, p = 1;
            while (m >= (t << 1)) {
                t <<= 1;
                p <<= 1;
            }
            res += p;
            m -= t;
        }
        // cout << sign << endl;
        return sign == 1 ? res : -res;
    }
};