class Solution {
public:
    int minAddToMakeValid(string S) {
        int res = 0;
        int balance = 0;
        for (char c: S) {
            if (c == '(') balance += 1;
            else balance += -1;
            // 一旦遇到-1，一定要加一个
            if (balance == -1) {
                balance++;
                res++;
            }
        }
        // 剩余balance>=0，如果>0，说明多了几个左括号
        return res + balance;
    }
};