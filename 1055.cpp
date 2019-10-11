class Solution {
public:
    int shortestWay(string source, string target) {
        int res = 0, i = 0;
        while (1) {
            res++;
            int tmp = i;
            for (int j = 0; j < source.length(); j++) {
                if (source[j] == target[i]) i++;
                if (i == target.size()) return res;
            }
            if (tmp == i) return -1;
        }
    }
};