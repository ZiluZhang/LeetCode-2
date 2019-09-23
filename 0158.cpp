// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    char buff[4];
    int read_pt = 0, write_pt = 0;
    int read(char *buf, int n) {
        for (int i = 0; i < n; i++) {
            if (read_pt == write_pt) {
                write_pt = read4(buff);
                read_pt = 0;
                if (write_pt == 0) return i;
            }
            buf[i] = buff[read_pt++];
        }
        return n;
    }
};