class Solution {
public:
    vector<string> ipToCIDR(string ip, int n) {
        long x = ip2int(ip);
        vector<string> res;
        while (n > 0) {
            long step = x & (-x);
            while (step > n) step /= 2;
            res.push_back(int2ip(x, step));
            x += step;
            n -= step;
        }
        return res;
    }
    
    long ip2int(string ip) {
        long res = 0;
        istringstream is(ip);
        string t;
        while (getline(is, t, '.')) {
            res = (res << 8) + stoi(t);
        }
        return res;
    }
    
    string int2ip(long n, int k) {
        return to_string(n >> 24) + "." + to_string((n >> 16) & 0xff) + "." + to_string((n >> 8) & 0xff) + "." + to_string(n & 0xff) + "/" + to_string(32 - (int)log2(k));
    }
};