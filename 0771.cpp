class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> jset;
        for (char c: J) {
            jset.insert(c);
        }
        int res = 0;
        for (char c: S) {
            res += jset.count(c);
        }
        return res;
    }
};