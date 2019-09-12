// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int res = 0;
        for (int i = 0; i <= n/4; i++) {
            int tmp = read4(buf + res);
            if (tmp == 0) break;
            res += tmp;
        }
        return min(res, n);
    }
};