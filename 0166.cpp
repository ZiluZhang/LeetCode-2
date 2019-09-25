class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long num = abs((long long)numerator);
        long long den = abs((long long)denominator);
        bool neg = (numerator < 0) ^ (denominator < 0);
        long long tmp = num / den;
        long long rem = num % den;
        unordered_map<long long, int> m;
        string res = to_string(tmp);
        if (neg && (tmp > 0 || rem > 0)) res = "-" + res;
        if (rem == 0) return res;
        res += ".";
        string s = "";
        int pos = 0;
        while (rem > 0) {
            if (m.find(rem) != m.end()) {
                s.insert(m[rem], "(");
                s += ")";
                return res + s;
            }
            m[rem] = pos;
            pos++;
            s += to_string((rem * 10) / den);
            rem = (rem * 10) % den;
        }
        return res + s;
    }
};