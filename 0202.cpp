class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while (true) {
            int tmp = 0;
            while (n) {
                tmp += pow(n % 10, 2);
                n /= 10;
            }
            if (tmp == 1) return true;
            if (s.count(tmp)) break;
            s.insert(tmp);
            n = tmp;
        }
        return false;
    }
};