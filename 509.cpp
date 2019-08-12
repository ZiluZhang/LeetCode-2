class Solution {
public:
    int fib(int N) {
        int res = 0;
        int prev = 1;
        int prevprev = -1;
        for (int i = 0; i <= N; i++) {
            res = prevprev + prev;
            prevprev = prev;
            prev = res;
        }
        return res;
    }
};